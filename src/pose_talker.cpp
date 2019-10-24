#include "ros/ros.h"
#include "std_msgs/String.h"

#include <vector>
#include <string>
#include "pose/PoseGenSer.h"

#include <XBotInterface/XBotInterface.h>
#include <XBotInterface/RobotInterface.h>
#include <RobotInterfaceROS/ConfigFromParam.h>

bool PersonalThirdTrajectory(const Eigen::VectorXd qi, 
                             const Eigen::VectorXd qf, 
                             const Eigen::VectorXd qdot_max,
                             const double t,
                             const double tf, 
                             Eigen::VectorXd& ref, 
                             Eigen::VectorXd& ref_dot) 
{
    double a0,a2,a3,qdiff;
    int vec_size     = qi.size();
    ref.resize(vec_size);
    ref_dot.resize(vec_size);
    bool Trajectory_Compl=false;
    if(tf > 0 && t<tf)
    {
        for (int i=0; i<vec_size; i++) 
        {
            qdiff=qf(i)-qi(i);
            a0=qi(i);
            a2=3*qdiff/std::pow(tf,2);
            a3=-2*qdiff/std::pow(tf,3); 
            ref(i)     = a3* std::pow(t,3) + a2* std::pow(t,2) + a0; 
            ref_dot(i)   = 3*a3* std::pow(t,2)+2*a2*t; 
            if(ref_dot(i) < 0)
                ref_dot(i) = 0.0*qdot_max(i);   
        }
    }
    else
    {
    ref = qi; 
    ref_dot = 0.0*qi; 
    Trajectory_Compl=true;
    }
  
return(Trajectory_Compl);
    
}

int main ( int argc, char **argv ) {
    ros::init ( argc, argv, "Pose_Talker" );

    std::string path_to_config_file = XBot::Utils::getXBotConfig();
    XBot::RobotInterface::Ptr robot = XBot::RobotInterface::getRobot ( path_to_config_file ); // returns a shared pointer to a robot object

    ros::NodeHandle n;

    /*********Pose Target Identification Service-----Client ********/////

    ros::ServiceClient client = n.serviceClient<pose::PoseGenSer> ( "/Pose_TargetIdent" );


    pose::PoseGenSer srv;


    ros::Rate loop_rate ( 200 );

    /*********Get Pose Request* *******/////

    srv.request.req_Pose= argv[1];

    /*********Call Server* *******/////

    client.call ( srv );

    int count_task=0,count_same_task,joint_indexTask,indexTime=0;

    Eigen::VectorXd qdot_max;
    robot->sense();
    robot->getVelocityLimits ( qdot_max );
    
    while ( ros::ok() && ! ( count_task>srv.response.srv_JointName_hiTask.size()-1 ) && srv.response.srv_PoseExist ) {

        robot->sense();

        const double start_time = 0;
        //double traj_time=0;
        double traj_time,time=0;

        Eigen::VectorXd q_start,final_pos,q_ref, qdot_ref;

        bool diff_task = false;

        double duration = -1;


        robot->getPositionReference ( q_start );
        final_pos = q_start;
        const double max_qdot = qdot_max.minCoeff() * 0.2; // [rad/s]

        /*********Find Same Task to perform at the same time* *******/////


        for ( count_same_task=count_task; count_task<srv.response.srv_TypeMov.size() && !diff_task; count_same_task++ ) {
            if ( count_same_task!=count_task ) {
                int c_past=count_same_task-1;
                if ( srv.response.srv_TypeMov[count_same_task]!=srv.response.srv_TypeMov[c_past] )
                    diff_task=true;
            }
            if ( !diff_task ) {
                joint_indexTask=robot->getDofIndex ( srv.response.srv_JointName_hiTask[count_same_task] );
                final_pos[joint_indexTask] = ( double ) srv.response.srv_JointPos_hiTask[count_same_task];
            }
        }
        count_same_task=count_same_task-1;
        int NumSameTask=count_same_task-count_task;
        traj_time=srv.response.srv_ExeTime_hiTask[indexTime];

        ROS_INFO ( "I'm going to perform: [%d] Task(s) in [%f]",NumSameTask,traj_time);

        count_task=count_same_task;


        bool completed_mov = false;
        const double dt = 0.1; // 10 Hz loop
        
        
        /********* Joint Trajectory Plan* *******/////


        while ( !completed_mov ) {
            
            completed_mov=PersonalThirdTrajectory(q_start,final_pos,qdot_max,time,traj_time,q_ref, qdot_ref);

            //XBot::Utils::FifthOrderTrajectory ( start_time, q_start, final_pos, max_qdot,traj_time,q_ref, qdot_ref, duration );
            if(!completed_mov)
            {

            robot->setPositionReference ( q_ref );
            robot->setVelocityReference ( qdot_ref );
            robot->move();
            }

            //completed_mov = traj_time >= ( start_time + duration );
            //traj_time += dt;
            time +=dt;

            usleep ( 1e6*dt );

        }
        indexTime++;

        ros::spinOnce();

        loop_rate.sleep();

    }

}




