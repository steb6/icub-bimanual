    ////////////////////////////////////////////////////////////////////////////////////////////////////
   //                                                                                                //
  //          A trajectory across two or more poses (position & orientation) in 3D space.           //
 //                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CARTESIAN_TRAJECTORY_H_
#define CARTESIAN_TRAJECTORY_H_

#include <Eigen/Geometry>                                                                           // Eigen::Isometry3d
#include <iDynTree/Core/CubicSpline.h>                                                              // Fundamental trajectory object
#include <iostream>                                                                                 // std::cout, std::cerr
#include <vector>                                                                                   // std::vector

class CartesianTrajectory
{
	public:
		CartesianTrajectory() {}                                                            // Empty constructor
		
		CartesianTrajectory(const std::vector<Eigen::Isometry3d> &poses,
		                    const std::vector<double>            &times);                   // Full constructor
		                    
		                    
		Eigen::Isometry3d get_pose(const double &time);
		            
		bool get_state(Eigen::Isometry3d         &pose,
		               Eigen::Matrix<double,6,1> &twist,
		               Eigen::Matrix<double,6,1> &acc,
		               const double              &time);                                    // Get the desired state for the given time
	
	private:
	
		bool isValid = false;                                                               // Won't do anything if false
		
		int numPoses;                                                                       // Number of poses
		
		std::vector<iDynTree::CubicSpline> spline;                                          // Array of spline objects
		
};                                                                                                  // Semicolon needed after class declaration

#endif
