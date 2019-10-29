# Pose-Task
Repository for a specific pose request to a generic robot.

## Scope

The package allows to perform a specific pose using this [yaml format](https://github.com/ADVRHumanoids/Pose-Task/blob/master/configs/Pose_Task.yaml).
A [ROS Service Server](https://github.com/ADVRHumanoids/Pose-Task/blob/master/src/pose_targetSrv.cpp) it's responsable to read the file and send the information to the [ROS client](https://github.com/ADVRHumanoids/Pose-Task/blob/master/src/pose_talker.cpp) that  will generate a trajectory in the joint space to the robot using XBotCore.   
