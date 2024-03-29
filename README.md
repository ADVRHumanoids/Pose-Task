# Pose-Task
Repository for a specific pose request to a generic robot.

# Scope

The package allows to perform a specific pose using this [Pose_Task file](https://github.com/ADVRHumanoids/Pose-Task/blob/master/configs/Pose_Task.yaml) in yaml format.
A [ROS Service Server](https://github.com/ADVRHumanoids/Pose-Task/blob/master/src/pose_targetSrv.cpp) it's responsable to read the file and send the information to the [ROS client](https://github.com/ADVRHumanoids/Pose-Task/blob/master/src/pose_talker.cpp) that  will generate a trajectory in the joint space to the robot using XBotCore.

# Start

Clone and build the pose project: there are several options to do it, but probably the easiest is using the catkin build tool from ROS.

```
mkdir -p ~/src/catkin_pose_ws/src
cd ~/src/catkin_pose_ws/src
catkin_init_workspace
git clone https://github.com/ADVRHumanoids/Pose-Task.git
cd ..
catkin_make
```

# Run

The selected robot was Centauro, whose basic config file can be set in this way:

```
set_xbot_config /opt/xbot/build/install/share/xbot/configs/CentauroConfig/centauro_basic.yaml
```

Note: It's possible to choose any robot, it's important to select the right joints with the specific movements writing them into the pose yaml file:


    Pose Name:
          Movements: [Move_1, Move_2,...]
          Move_1:
          JointNameMov: ["joint_name1","joint_name2",...]
          PositionNameMov: [pos_joint_name1,pos_joint_name2,...]
          TimeMov: [Time_to_Exe the Trajectory]


As first thing you should run [roscore](http://wiki.ros.org/roscore):

```
roscore
```

Later on you can start the XBotCore in "dummy" mode in another terminal (more information [here](https://github.com/ADVRHumanoids/XBotControl/wiki/Quick-XBotCore-Start)) in this way:

```
XBotCore -D
```

In another terminal you can use the [RViZ](http://wiki.ros.org/rviz) tool to visualize the kinematic simulation of the robot by running:

```
rviz
```
and adding a _"RobotModel"_ with the following Robot Description: _xbotcore/robot_description_
Remind to select "world" for "Fixed Frame" in "Global Options".

This should be the visualization:

![XBotCore basic example with Centauro](https://github.com/ADVRHumanoids/XBotControl/blob/master/xbotcore_centauro_basic.png)


Start XBot Communication Plugin:

```
rosservice call /xbotcore/XBotCommunicationPlugin_switch 1
```

In another two terminals launch:
``` 
. ~/src/catkin_pose_ws/devel/setup.bash
```
Terminal 1: 
            
            rosrun pose pose_targetSrv   
Terminal 2:  
            
            rosrun pose pose_talker Centauro_Hello_Pose 
                    
# Result

This should be the visualization:

![XBotCore basic example with Centauro](https://github.com/ADVRHumanoids/Pose-Task/blob/master/HelloPose_Centauro.png)
