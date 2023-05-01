    ///////////////////////////////////////////////////////////////////////////////////////////////////
   //                                                                                               //
  //                    Enables interfacing with the iCub/ergoCub through YARP                     //
 //                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <CommandInterface.h>                                                                       // thrift-generated class
#include <iostream>                                                                                 // std::cerr, std::cout
#include <map>                                                                                      // std::map
#include <PositionControl.h>                                                                        // For control of ergoCub, iCub robots
#include <Utilities.h>                                                                              // JointTrajectory object structure
#include <yarp/os/Property.h>                                                                       // Load configuration files
#include <yarp/os/RpcServer.h>                                                                      // Allows communication over yarp ports

  ///////////////////////////////////////////////////////////////////////////////////////////////////
 //                 Overrides the functions specified in CommandInterface.thrift                  //
///////////////////////////////////////////////////////////////////////////////////////////////////
class CommandServer : public CommandInterface
{
	public:
	
		CommandServer(PositionControl *_robot,
		              std::map<std::string,JointTrajectory> *_jointActionMap,
		              std::map<std::string,CartesianMotion> *_leftHandMap,
		              std::map<std::string,CartesianMotion> *_rightHandMap)
		             :
		             robot(_robot),
		             jointActionMap(_jointActionMap),
		             leftHandMap(_leftHandMap),
		             rightHandMap(_rightHandMap) {}        
		
		////////// NOTE: These are directly copied from CommandInterface.h //////////

		// Activate the grasp constraints
		bool grasp()
		{
			std::cout << "Not yet programmed!\n";
			
			return false;
		}

		// Query if the robot is finished moving
		bool is_finished() const { return this->robot->is_finished(); }
		
		// Move the hands by prescribed action
		bool perform_cartesian_action(const std::string& actionName)
		{
			// Variables used in this scope
			std::vector<Eigen::Isometry3d> leftWaypoints, rightWaypoints;               // Cartesian waypoints for the hands
			std::vector<double> times;                                                  // Time to reach each waypoint
			Type type;                                                                  // Enumeration; relative or absolute
			
			// Find the left-hand motion in the list
			auto temp = this->leftHandMap->find(actionName);
			
			if(temp == this->leftHandMap->end())
			{
				std::cerr << "[ERROR] [iCUB COMMAND SERVER] move_hands_by_action(): "
				          << "Could not find the action named '" << actionName
				          << "' for the left hand.\n";
				
				return false;
			}
			else
			{
				leftWaypoints = temp->second.waypoints;
				times         = temp->second.times;
				type          = temp->second.type;
			}
			
			// Find the right-hand motion in the list
			temp = this->rightHandMap->find(actionName);
			
			if(temp == this->rightHandMap->end())
			{
				std::cerr << "[ERROR] [iCUB COMMAND SERVER] move_hands_by_action(): "
				          << "Could not find the action named '" << actionName
				          << "' for the right hand.\n";
				
				return false;
			}
			else	rightWaypoints = temp->second.waypoints;
			
			if(type == absolute)
			{
				return this->robot->move_to_poses(leftWaypoints, rightWaypoints, times);
			}
			else // type == relative
			{
				try
				{
					// NOTE: HERE I AM ASSUMING ONLY 1 WAYPOINT, BUT I NEED TO PROGRAM
					// FOR MULTIPLE, RELATIVE WAYPOINTS
					// Also, I am only translating otherwise things get weird
					
					Eigen::Isometry3d desiredLeft  = this->robot->hand_pose("left");
					desiredLeft.translation() += leftWaypoints[0].translation();
					                               
					
					Eigen::Isometry3d desiredRight = this->robot->hand_pose("right");
					desiredRight.translation() += rightWaypoints[0].translation();
					
					this->robot->move_to_pose(desiredLeft,desiredRight,times[0]);     // Send the commands onward
					
					return true;
				}
				catch(const std::exception &exception)
				{
					std::cout << exception.what() << std::endl;                       // Print out the problem
					
					return false;
				}
			}  
		}

		// Move a grasped object by a prescribed action
		bool perform_grasp_action(const std::string& actionName)
		{
			std::cout << "NOT YET PROGRAMMED\n";
			
			return false;
		}

		// Move the configuration of the joints by a prescribed action
		bool perform_joint_space_action(const std::string& actionName)
		{
			auto jointConfig = this->jointActionMap->find(actionName);
			
			if(jointConfig == this->jointActionMap->end())
			{
				std::cerr << "[ERROR] [iCUB COMMAND SERVER] move_to_named_configuration(): "
				          << "Could not find a joint configuration named '"
				          << actionName << "' in the list.\n";
				
				return false;
			}
			else
			{
				return this->robot->move_to_positions(jointConfig->second.waypoints,
				                                      jointConfig->second.times);
				return true;
			}
		}

		// Move the hands to given poses
		bool move_hands_to_pose(const yarp::sig::Matrix& leftPose,
		                        const yarp::sig::Matrix& rightPose,
		                        const double time)
		{
			if(leftPose.rows() != 4 or leftPose.cols() != 4)
			{
				std::cerr << "[ERROR] [iCUB COMMAND SERVER] move_hands_to_pose(): "
				          << "Expected a 4x4 matrix for the left hand pose, but "
				          << "it was " << leftPose.rows() << "x" << leftPose.cols() << ".\n";
				
				return false;
			}
			
			if(rightPose.rows() != 4 or rightPose.cols() != 4)
			{
				std::cerr << "[ERROR] [iCUB COMMAND SERVER] move_hands_to_pose(): "
				          << "Expected a 4x4 matrix for the right hand pose, but "
				          << "it was " << rightPose.rows() << "x" << rightPose.cols() << ".\n";
				
				return false;
			}
			
			Eigen::Matrix4d temp;
			
			// Convert yarp::sig::Matrix to Eigen::Isometry3d
			for(int i = 0; i < 4; i++)
			{
				for(int j = 0; j < 4; j++) temp(i,j) = leftPose[i][j];
			}
		
			Eigen::Isometry3d desiredLeft(temp);
			
			// Convert yarp::sig::Matrix to Eigen::Isometry3d
			for(int i = 0; i < 4; i++)
			{
				for(int j = 0; j < 4; j++) temp(i,j) = leftPose[i][j];
			}
			
			Eigen::Isometry3d desiredRight(temp);
			
			return this->robot->move_to_pose(desiredLeft, desiredRight, time);	
		}

		// Move the joints
		bool move_joints_to_position(const std::vector<double>& position, const double time)
		{
			return this->robot->move_to_position(Eigen::VectorXd::Map(&position[0], position.size()), time);
		}

		bool move_object_to_pose(const yarp::sig::Matrix& pose, const double time)
		{
			std::cout << "NOT YET PROGRAMMED.\n";
			
			return false;
		}

		bool release_object() const { return this->robot->release_object(); }

		void stop() { this->robot->halt(); }
		
		void shut_down() { this->serverActive = false; }

		// Move a grasped object to a pose
		bool move_object_to_pose(const std::vector<double>& pose, const double time)
		{
			if(pose.size() == 6)
			{
				Eigen::Isometry3d desiredPose;
				
				try
				{
					desiredPose = transform_from_vector(pose);
					
					return this->robot->move_object(desiredPose,time);
				}
				catch(const std::exception &exception)
				{
					std::cout << exception.what() << std::endl;                 // Print out the problem
					
					return false;
				}
			}
			else
			{
				std::cerr << "[ERROR] [iCUB CONTROL SERVER] move_object_to_pose(): "
				          << "Expected 6 elements for the argument, but it had " << pose.size() << ".\n";
				
				return false;
			}
		}	
		
		///////////////////// Not defined in CommandInterface.h ///////////////////////////
		bool is_active() const { return this->serverActive; }
	    
	private:
		bool serverActive = true;
		
		PositionControl *robot;                                                             // Pointer to robot object
		
		std::map<std::string, JointTrajectory> *jointActionMap;                             // Map of prescribed joint configurations

		std::map<std::string, CartesianMotion> *leftHandMap, *rightHandMap;
};                                                                                                  // Semicolon needed after class declaration

  ////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                             MAIN                                               //
////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	std::string errorMessage = "[ERROR] [iCUB COMMAND SERVER] ";
	
	// Default for argc is 1, but I don't know why ¯\_(ツ)_/¯
	if(argc != 4)
	{
		std::cerr << errorMessage << "Port name and path to URDF are required. "
		          << "Usage: ./icub2_grasp_demo /portPrefix /path/to/model.urdf /path/to/config.ini\n";
		
		return 1;                                                                           // Close with error
	}

	std::string portPrefix   = argv[1];                                                         // Get the port names
	std::string pathToURDF   = argv[2];                                                         // Get the file path
	std::string pathToConfig = argv[3];                                                         // Path to the configuration file
	
	// Generate port list prefixes
	std::vector<std::string> portList;
	portList.push_back(portPrefix + "/torso");
	portList.push_back(portPrefix + "/left_arm");
	portList.push_back(portPrefix + "/right_arm");
	
	yarp::os::Property parameter; parameter.fromConfigFile(pathToConfig);                       // Load the properties from the config file
		
	try // to start up the robot
	{
		// Get the joint list from the config file
		yarp::os::Bottle* bottle; bottle = parameter.find("joint_names").asList();
		
		if(bottle == nullptr)
		{
			std::cerr << errorMessage << "No list of joint names was specified in " << pathToConfig << ".\n";
			return 1;
		}
		
		std::vector<std::string> jointNames = string_from_bottle(bottle);                   // Function specified in Utils.h

		// Load the joint-space actions from the config file
		std::map<std::string, JointTrajectory> jointActionMap;                              // NOTE: JointTrajectory is a data structure in Utils.H
		
		bottle->clear(); bottle = &parameter.findGroup("JOINT_SPACE_ACTIONS");
		
		if(bottle == nullptr)
		{
			std::cerr << errorMessage << "No group called JOINT_SPACE_ACTIONS could be found in "
			          << pathToConfig << ".\n";
			
			return 1;
		}
		if(not load_joint_configurations(bottle,jointActionMap)) return 1;
		
		// Load the left hand actions from the config file
		
		bottle->clear(); bottle = parameter.findGroup("CARTESIAN_ACTIONS").find("names").asList(); // Find all the listed names
		
		std::vector<std::string> nameList = string_from_bottle(bottle);                     // Convert to vector of strings
		
		std::map<std::string, CartesianMotion> leftHandMap;                                 // Create the map so we can search it later
		
		bottle->clear(); bottle = parameter.findGroup("CARTESIAN_ACTIONS").find("left").asList(); // Get all the actions listed for the left hand
		
		if(bottle == nullptr)
		{
			std::cerr << errorMessage << "No list called 'left' in the CARTESIAN_ACTIONS group "
			                          << "could be found in " << pathToConfig << ".\n";
			return 1;
		}
		
		if(not load_cartesian_trajectories(bottle,nameList,leftHandMap)) return 1;          // Try and put the named actions together in the map
		
		// Load the right hand actions from the config file
		std::map<std::string, CartesianMotion> rightHandMap;
		
		bottle->clear(); bottle = parameter.findGroup("CARTESIAN_ACTIONS").find("right").asList();
		
		if(bottle == nullptr)
		{
			std::cerr << errorMessage << "No list called 'right' in the CARTESIAN_ACTIONS group "
			                          << "could be found in " << pathToConfig << ".\n";
			return 1;
		}
		
		if(not load_cartesian_trajectories(bottle,nameList,rightHandMap)) return 1;
		
		////////////////////// NEED TO LOAD NAME AS AN ARGUMENT /////////////////////////////
		PositionControl robot(pathToURDF, jointNames, portList, "iCub2");                   // Start up the robot
		
		// Set the Cartesian gains
		double kp = parameter.findGroup("CARTESIAN_GAINS").find("proportional").asFloat64();
		double kd = parameter.findGroup("CARTESIAN_GAINS").find("derivative").asFloat64();	
		if(not robot.set_cartesian_gains(kp,kd)) return 1;
		
		// Set the joint gains
		kp = parameter.findGroup("JOINT_GAINS").find("proportional").asFloat64();
		kd = parameter.findGroup("JOINT_GAINS").find("derivative").asFloat64();
		if(not robot.set_joint_gains(kp,kd)) return 1;
		
		// Set the singularity avoidance parameters
		double maxDamping = parameter.findGroup("SINGULARITY_AVOIDANCE").find("maxDamping").asFloat64();
		double threshold  = parameter.findGroup("SINGULARITY_AVOIDANCE").find("threshold").asFloat64();
		if(not robot.set_singularity_avoidance_params(maxDamping,threshold)) return 1;
		
		// Set the desired position for the joints when running in Cartesian mode
		bottle->clear(); bottle = parameter.find("desired_position").asList();
		if(bottle == nullptr)
		{
			std::cerr << "[ERROR] [iCUB COMMAND SERVER] "
			          << "Couldn't find 'desired_position' listed in the config file.\n";
			return 1;
		}
		robot.set_desired_joint_position(vector_from_bottle(bottle));
		
		
		// Establish communication over YARP
		yarp::os::Network yarp;
		yarp::os::Port port;
		CommandServer commandServer(&robot, &jointActionMap, &leftHandMap, &rightHandMap);  // Create command server
		commandServer.yarp().attachAsServer(port);
		
		if(not port.open("/commandServer"))
		{
			std::cerr << errorMessage << "Could not open port /commandServer.\n";
			return 1;
		}
		
		while(commandServer.is_active())
		{
			std::cout << "\nWorker bees can leave.\n";
			yarp::os::Time::delay(5);
			std::cout << "Even drones can fly away.\n";
			yarp::os::Time::delay(5);
			std::cout << "The Queen is their slave.\n";
			yarp::os::Time::delay(20);
		}
		
		std::cout << "[INFO] [iCUB COMMAND SERVER] Shutting down. Arrivederci.\n";
		
		port.close();
		
		robot.close();
		
		return 0;                                                                           // No problems with main
	}
	catch(std::exception &exception)
	{
		std::cerr << errorMessage << "There was a problem with initialization.\n";
		          
		std::cout << exception.what() << std::endl;                                         // Inform the user
		
		return 1;                                                                           // Close with error
	}
}
