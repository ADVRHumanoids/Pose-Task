#include "ros/ros.h"
#include "hi/hiGenSer.h"
#include <iostream>
#include <fstream>
#include <string>

 std::vector<std::string> taskfile;


 bool hiTarget(hi::hiGenSer::Request &req,hi::hiGenSer::Response &res)
 {
   
    for(int i=0;i<taskfile.size();i++)
    {
    std::string token;
    std::vector<std::string> tokens;
    std::istringstream linestream(taskfile[i]);
    while (std::getline(linestream, token,' '))
        tokens.push_back(token);
    if(std::find(res.srv_JointName.begin(), res.srv_JointName.end(), tokens[0].c_str())==res.srv_JointName.end())
        res.srv_JointName.push_back(tokens[0]);
    res.srv_JointName_hiTask.push_back(tokens[0]);
    res.srv_JointPos_hiTask.push_back(std::atof(tokens[1].c_str()));
    res.srv_ExeTime_hiTask.push_back(::atof(tokens[2].c_str()));
    
    //ROS_INFO("sending back response: [%s] [%f] [%f]",res.srv_JointName_hiTask[0].c_str(),res.srv_JointPos_hiTask[0],res.srv_ExeTime_hiTask[0]);
    
    }
    
    ROS_INFO("Hi Targets Sent");
    
    return true;
 }
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "hi_Target_Definition");
  ros::NodeHandle n;

  std::string line_file;
  std::ifstream file("hi_target_file.txt");
  
  
  if (file.is_open()) {
    
    while (std::getline(file, line_file)) {
        taskfile.push_back(line_file);
    }
    file.close();
    ros::ServiceServer service = n.advertiseService("hi_TargetIdent", hiTarget);
    ROS_INFO("Wait to send Hi Target.");
    ros::spin();
   }
 else
   ROS_INFO("Errore Apertura File");
   return 0;
}