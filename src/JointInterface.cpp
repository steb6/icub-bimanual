#include <JointInterface.h>

  ////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                       Constructor                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
JointInterface::JointInterface(const std::vector<std::string> &jointList,
                               const std::vector<std::string> &portList)
                               :
                               numJoints(jointList.size())                                          // Number of joints equal to size of list
{
	// Resize std::vector objects based on number of joints in the model
	this->positionLimit.resize(this->numJoints);
	this->velocityLimit.resize(this->numJoints);

	////////////////////////// I copied this code from elsewhere ///////////////////////////////

	// Open up device drivers
	yarp::os::Property options;
	options.put("device", "remotecontrolboardremapper");
	options.addGroup("axesNames");

	yarp::os::Bottle & bottle = options.findGroup("axesNames").addList();
	for(int i = 0; i < jointList.size(); i++) bottle.addString(jointList[i].c_str());           // Add the list of all the joint names

	yarp::os::Bottle remoteControlBoards;
	yarp::os::Bottle & remoteControlBoardsList = remoteControlBoards.addList();
	for(int i = 0; i < portList.size(); i++) remoteControlBoardsList.addString(portList[i]);    // Add the remote control board port names

	options.put("remoteControlBoards", remoteControlBoards.get(0));
	options.put("localPortPrefix", "/local");

	yarp::os::Property &remoteControlBoardsOpts = options.addGroup("REMOTE_CONTROLBOARD_OPTIONS");
			    remoteControlBoardsOpts.put("writeStrict", "on");

	////////////////////////////////////////////////////////////////////////////////////////////
	
	std::string errorMessage = "[ERROR] [JOINT INTERFACE] Constructor: ";

	if(not this->driver.open(options)) throw std::runtime_error(errorMessage + "Could not open the device driver.");
	else
	{
		     if(not this->driver.view(this->pController)) throw std::runtime_error(errorMessage + "Unable to configure the position controller for the joint motors.");
		else if(not this->driver.view(this->mode))        throw std::runtime_error(errorMessage + "Unable to configure the control mode.");
		else if(not this->driver.view(this->limits))      throw std::runtime_error(errorMessage + "Unable to obtain the joint limits.");
		else
		{
			// Opened the motor controllers, so get the joint limits
			for(int i = 0; i < this->numJoints; i++)
			{
				double notUsed;
				this->limits->getLimits(i, &this->positionLimit[i][0], &this->positionLimit[i][1]);
				this->limits->getVelLimits(i, &notUsed, &this->velocityLimit[i]);   // Assume vMin = -vMax
				
				// Convert from degrees to radians
				this->positionLimit[i][0] *= M_PI/180.0;
				this->positionLimit[i][1] *= M_PI/180.0;
				this->velocityLimit[i]    *= M_PI/180.0;
				
				if(not this->mode->setControlMode(i,VOCAB_CM_POSITION_DIRECT))
				{
					errorMessage += "Unable to set the control mode for joint " + std::to_string(i) + ".";
					
					throw std::runtime_error(errorMessage);
				}
			}
			
			// Finally, configure the encoders
			if(not this->driver.view(this->encoders)) throw std::runtime_error(errorMessage + "Unable to configure the encoders.");
			else
			{
				double temp[this->numJoints];                                       // Temporary placeholder for encoder values			

				// Make 5 attempts to read the encoders
				for(int i = 0; i < 5; i++)
				{
					if(not this->encoders->getEncoders(temp) and i == 4)
					{
						throw std::runtime_error(errorMessage + "Could not obtain encoder values in 5 attempts.");
					}
				}
				
				std::cout << "[INFO] [JOINT INTERFACE] Successfully configured the joint motors.\n";
			}
		}
	}
}

  ////////////////////////////////////////////////////////////////////////////////////////////////////
 //                    Read the joint positions and velocities from the encoders                   //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool JointInterface::read_encoders(Eigen::VectorXd &pos, Eigen::VectorXd &vel)
{
	if(pos.size() != this->numJoints or vel.size() != this->numJoints)
	{
		std::cerr << "[ERROR] [JOINT INTERFACE] read_encoders(): "
		          << "There are " << this->numJoints << " joints, but "
		          << "the position argument had " << pos.size() << " elements and "
		          << "the velocity argument had " << vel.size() << " elements.\n";

		return false;
	}
	else
	{
		bool success = true;
		
		for(int i = 0; i < this->numJoints; i++)
		{
			success &= this->encoders->getEncoder     (i, &pos(i));                     // Read joint positions
			success &= this->encoders->getEncoderSpeed(i, &vel(i));                     // Read joint velocities
		}
		
		if(success)
		{
			pos *= M_PI/180.0;                                                          // Convert to radians
			vel *= M_PI/180.0;                                                          // Convert to radians
			
			return true;
		}
		else
		{
			std::cerr << "[ERROR] [JOINT INTERFACE] read_encoders(): "
			             "Could not obtain new encoder values.\n";
			
			return false;
		}
	}
}

  ////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                 Send commands to the joint motors                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool JointInterface::send_joint_commands(const Eigen::VectorXd &commands)
{
	if(commands.size() != this->numJoints)
	{
		std::cerr << "[ERROR] [JOINT INTERFACE] send_joint_command(): "
		          << "This robot has " << this->numJoints << " active joints but the input "
		          << "argument had " << commands.size() << " elements.\n";
		          
	        return false;
	}
	else
	{
		for(int i = 0; i < this->numJoints; i++)
		{
			if(not this->pController->setPosition(i,commands[i]*180.0/M_PI))
			{
				std::cerr << "[ERROR] [JOINT INTERFACE] send_joint_commands(): "
				          << "Could not send a command for joint " << i << ".\n";
				
				return false;
			}
		}
		
		return true;
	}
}

  ////////////////////////////////////////////////////////////////////////////////////////////////////
 //                             Close the device interfaces on the robot                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void JointInterface::close()
{
	for(int i = 0; i < this->numJoints; i++) this->mode->setControlMode(i, VOCAB_CM_POSITION);  // Set in position mode to lock the joint
	
	this->driver.close();                                                                       // Close the device drivers
}
