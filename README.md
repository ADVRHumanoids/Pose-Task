# Pose-Task
Repository for a specific pose request to a generic robot.

# Scope

The package allows to perform a specific pose using this [Pose_Task file](https://github.com/ADVRHumanoids/Pose-Task/blob/master/configs/Pose_Task.yaml) in yaml format.
A [ROS Service Server](https://github.com/ADVRHumanoids/Pose-Task/blob/master/src/pose_targetSrv.cpp) it's responsable to read the file and send the information to the [ROS client](https://github.com/ADVRHumanoids/Pose-Task/blob/master/src/pose_talker.cpp) that  will generate a trajectory in the joint space to the robot using XBotCore.

# Runnig

The selected robot was Centauro, whose basic config file can be set in this way:

```
set_xbot_config /opt/xbot/build/install/share/xbot/configs/CentauroConfig/centauro_basic.yaml
```

Note: It's possible to choose any robot, it's important to select the righ joint with the specific movement writing them the pose yaml file.

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
