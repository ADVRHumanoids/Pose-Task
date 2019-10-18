#include "ros/ros.h"
#include "std_msgs/String.h"
#include "xbot_msgs/JointCommand.h"
#include "xbot_msgs/JointState.h"
#include <vector>
#include <string>
#include "hi/hiGenSer.h"

#include <XBotInterface/XBotInterface.h>
#include <XBotInterface/RobotInterface.h>
#include <RobotInterfaceROS/ConfigFromParam.h>

/*void jointstateCallback(const xbot_msgs::JointState::ConstPtr& msg)
{   
  for (size_t i = 0; i < msg->name.size(); ++i)
    {
     //if(msg->name[i]=="j_arm1_2")
        //ROS_INFO("JOINT FOUND"); 
    }
}*/


void sendROS_cmd(xbot_msgs::JointCommand *JointCmdFun,std::vector<std::string> JointName,double Position[],double Velocity[],int CtrlMode[],int vsize)
{
    std::vector<float> Pos,Vel;
    std::vector<uint8_t> CM;
        for (int i=0;i<vsize;i++) {
                Pos.push_back(Position[i]);
                Vel.push_back(Velocity[i]);
                CM.push_back(CtrlMode[i]);
    }
   
    JointCmdFun->header.seq=0;
    JointCmdFun->header.stamp.sec=0;
    JointCmdFun->header.stamp.nsec=0;
    
    JointCmdFun->name = JointName; //nmber of joints
    
    //"";
   JointCmdFun->position=Pos; //number of joints
   JointCmdFun->velocity=Vel; //number of joints
   JointCmdFun->ctrl_mode = CM; //number of joints
   for(int i=0;i<3;i++)
    ROS_INFO("Check [%s] [%f] [%f] [%d] \n",JointCmdFun->name[i].c_str(), JointCmdFun->position[i],JointCmdFun->velocity[i],JointCmdFun->ctrl_mode[i]);

}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "hi_talker");
    
    //ros::NodeHandle xbot_n("xbotcore");
    //auto opt = XBot::ConfigOptionsFromParamServer(xbot_n);
    
    std::string path_to_config_file = XBot::Utils::getXBotConfig();
    XBot::RobotInterface::Ptr robot = XBot::RobotInterface::getRobot(path_to_config_file); // returns a shared pointer to a robot object
    
    
    //XBot::XBotInterface xbi;
    //xbi.init(opt);
  
    ros::NodeHandle n;
    
    ros::ServiceClient client = n.serviceClient<hi::hiGenSer>("/hi_TargetIdent");
    
    hi::hiGenSer srv;
    //ros::Subscriber hi_sub= n.subscribe("/xbotcore/joint_states",1000,jointstateCallback);
    
    ros::Publisher hi_pub = n.advertise<xbot_msgs::JointCommand>("/xbotcore/command", 1000);
   
    ros::Rate loop_rate(200);
    
    client.call(srv);
    
    double vq_ref[srv.response.srv_JointName.size()],vqdot_ref[srv.response.srv_JointName.size()];
     int ctrlMode[srv.response.srv_JointName.size()];
     for(int i=0;i<srv.response.srv_JointName.size();i++)
         ctrlMode[i]=1;
     
    int count_hi_task=0;
   

    
    while (ros::ok()&& !(count_hi_task>srv.response.srv_JointName_hiTask.size()-1))
    {
    
    robot->sense();
    const double start_time = 0;
    double traj_time=0;
    
    
    Eigen::VectorXd q_start,qdot_max,qdot_start;
    double final_pos,q_ref, qdot_ref=0;
    
    
    double duration = -1;
    
    
    xbot_msgs::JointCommand JointCmd;
    
    robot->getJointPosition(q_start);
    robot->getJointVelocity(qdot_start);
    robot->getVelocityLimits(qdot_max);
    
    //xbi.getJointPosition(q_start);
    //xbi.getJointVelocity(qdot_start);
    //xbi.getVelocityLimits(qdot_max);
    
   
    for(int k=0;k<srv.response.srv_JointName.size();k++)
    {
        vq_ref[k]=q_start[robot->getDofIndex(srv.response.srv_JointName[k])];
        vqdot_ref[k]=qdot_start[robot->getDofIndex(srv.response.srv_JointName[k])]; 
         ROS_INFO("Index Joint [%f] [%f]",vq_ref[k],vqdot_ref[k]);
    }
    int joint_indexTask=robot->getDofIndex(srv.response.srv_JointName_hiTask[count_hi_task]);
    final_pos = (double) srv.response.srv_JointPos_hiTask[count_hi_task];
    //traj_time= (double)srv.response.JointPos,srv.response.ExeTime;
    
   

    const double max_qdot = qdot_max.minCoeff() * 0.2; // [rad/s]
    bool completed_mov = false;
    const double dt = 0.1; // 10 Hz loop
    

    while(!completed_mov)
    {
    
    XBot::Utils::ThirdOrderTrajectory(start_time,(double)q_start(joint_indexTask),final_pos,max_qdot,traj_time,q_ref,qdot_ref,duration);

    auto it= std::find(srv.response.srv_JointName.begin(), srv.response.srv_JointName.end(), srv.response.srv_JointName_hiTask[count_hi_task].c_str());
    
    //ROS_INFO("Info [%f] [%f]",q_ref,qdot_ref);
    
    if(it!=srv.response.srv_JointName.end())
    {       
    auto index = std::distance(srv.response.srv_JointName.begin(), it);
    vq_ref[index]=q_ref;
    vqdot_ref[index]=qdot_ref;
    }
    
    
    sendROS_cmd(&JointCmd,srv.response.srv_JointName,vq_ref,vqdot_ref,ctrlMode,srv.response.srv_JointName.size());
      
    

    hi_pub.publish(JointCmd);
    
    completed_mov = traj_time >= (start_time + duration);
    traj_time += dt;

    usleep(1e6*dt);

    }
    
    count_hi_task++;

    
    ROS_INFO("TASK numerber: %d",count_hi_task);
    
    ros::spinOnce();
    
    loop_rate.sleep();
    
    }
    
}




