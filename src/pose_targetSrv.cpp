#include "ros/ros.h"
#include "pose/PoseGenSer.h"
#include <iostream>
#include <fstream>
#include <string>
#include "yaml-cpp/yaml.h"

char filepath[]="";

 bool PoseTarget(pose::PoseGenSer::Request &req,pose::PoseGenSer::Response &res)
 {
    /***** YAML File reading and response generation ****////
     
    YAML::Node config = YAML::LoadFile(filepath);
    
    if (config[req.req_Pose] && config[req.req_Pose]["Movements"]) 
    {
        ROS_INFO("Pose Requested Available");
        res.srv_PoseExist=true;
        for(auto movms : config[req.req_Pose]["Movements"])
        {
            for(auto JointN : config[req.req_Pose][movms.as<std::string>().c_str()]["JointNameMov"])
            {
                res.srv_TypeMov.push_back(movms.as<std::string>());
                res.srv_JointName_hiTask.push_back(JointN.as<std::string>());
            }
            for(auto PosN : config[req.req_Pose][movms.as<std::string>().c_str()]["PositionNameMov"])
                res.srv_JointPos_hiTask.push_back(PosN.as<float>());
            for(auto TimeN : config[req.req_Pose][movms.as<std::string>().c_str()]["TimeMov"])
                res.srv_ExeTime_hiTask.push_back(TimeN.as<float>());
        }
       
    }
    else
    {
        ROS_INFO("Pose Requested Not Available");
        res.srv_PoseExist=false;
    }
    return true;
 }
 
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "Pose_Target_Definition");
  ros::NodeHandle n;

  /*********Find ymal Path inside the project ********/////
  char * pch;
  
  pch = strtok (argv[0],"/");
  bool stop=false;
  while (pch != NULL && !stop)
  {
    if(strcmp(pch,"devel")==0)
    {
        strcat(filepath,"/src/Pose-Task/configs/Pose_Task.yaml");
        stop=true;
    }
    else
    {
        strcat(filepath,"/"); 
        strcat(filepath,pch); 
        pch = strtok (NULL, "/");
    }
  }
  
  /*********Pose Target Identification Service-----Server ********/////
  
  
  ros::ServiceServer service = n.advertiseService("Pose_TargetIdent", PoseTarget);
  ROS_INFO("Wait to send Pose Target.");
  ros::spin();
  
  return 0;
 
}
