#include <XBotInterface/RobotInterface.h>
#include <XBotInterface/Utils.h>

int main()
{
    std::string path_to_config_file = XBot::Utils::getXBotConfig();
    XBot::RobotInterface::Ptr robot = XBot::RobotInterface::getRobot(path_to_config_file); // returns a shared pointer to a robot object
    
    
    robot->sense();
   

    /* Get the current robot state as a vector */
    Eigen::VectorXd q_start;
    robot->getJointPosition(q_start);

    /* Get some homing that does not violate joint limits */
    Eigen::VectorXd q_min, q_max, q_home;
    robot->getJointLimits(q_min, q_max);
    q_home = 0.5 * (q_min + q_max);

    /* Get some joint velocity that does not violate velocity limits */
    Eigen::VectorXd qdot_max;
    robot->getVelocityLimits(qdot_max);
    const double max_qdot = qdot_max.minCoeff() * 0.2; // [rad/s]

    /* Send a smooth trajectory to the robot */
    double time = 0;
    const double start_time = 0;
    const double dt = 0.01; // 100 Hz loop
    double duration = -1;
    bool homing_complete = false;
    Eigen::VectorXd q_ref, qdot_ref; 

    while(!homing_complete)
    {
        XBot::Utils::FifthOrderTrajectory(start_time, 
                                          q_start, 
                                          q_home, 
                                          max_qdot, 
                                          time, 
                                          q_ref, 
                                          qdot_ref, 
                                          duration);

        robot->setPositionReference(q_ref);
        robot->setVelocityReference(qdot_ref);
        robot->move();

        homing_complete = time >= (start_time + duration);
        time += dt;

        usleep(dt * 1e6);

    }

    return 0;
}