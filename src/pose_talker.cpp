#include "ros/ros.h"
#include "std_msgs/String.h"

#include <vector>
#include <string>
#include "pose/PoseGenSer.h"

#include <XBotInterface/XBotInterface.h>
#include <XBotInterface/RobotInterface.h>
#include <RobotInterfaceROS/ConfigFromParam.h>



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

    int count_task=0,count_same_task,joint_indexTask;


    while ( ros::ok() && ! ( count_task>srv.response.srv_JointName_hiTask.size()-1 ) && srv.response.srv_PoseExist ) {

        robot->sense();

        const double start_time = 0;
        double traj_time=0;

        Eigen::VectorXd q_start,qdot_max,final_pos,q_ref, qdot_ref;

        bool diff_task = false;

        double duration = -1;


        robot->getJointPosition ( q_start );
        robot->getVelocityLimits ( qdot_max );
        final_pos=q_start;
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

        ROS_INFO ( "I'm going to perform: [%d] Task(s)",NumSameTask );

        count_task=count_same_task;


        bool completed_mov = false;
        const double dt = 0.1; // 10 Hz loop
        
        /********* Joint Trajectory Plan* *******/////


        while ( !completed_mov ) {

            XBot::Utils::FifthOrderTrajectory ( start_time, q_start, final_pos, max_qdot,traj_time,q_ref, qdot_ref, duration );


            robot->setPositionReference ( q_ref );
            robot->setVelocityReference ( qdot_ref );
            robot->move();

            //hi_pub.publish(JointCmd);

            completed_mov = traj_time >= ( start_time + duration );
            traj_time += dt;

            usleep ( 1e6*dt );

        }

        ros::spinOnce();

        loop_rate.sleep();

    }

}




