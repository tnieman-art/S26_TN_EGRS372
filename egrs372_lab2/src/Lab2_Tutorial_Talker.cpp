//Includes all of the ROS libraries needed
#include "ros/ros.h"
#include <sstream>

//Uncomment this and replace {type} with the type of message when needed
#include "std_msgs/UInt64.h"


int main(int argc, char **argv)
{

  //names the program for visual purposes
  ros::init(argc, argv, "Lab2_Tutorial_Talker");
  ros::NodeHandle n;

  ros::Publisher square_pub =
  n.advertise<std_msgs::UInt64>("squared_number", 10);

  //sets the frequency for which the program sleeps at. 10=1/10 second
  ros::Rate loop_rate(10);

  uint64_t input;

  //rosk::ok() will stop when the user inputs Ctrl+C
  while(ros::ok())
  {

    // Get integer from user
    std::cout << "Enter an integer: ";
    std::cin >> input;

    // Create message
    std_msgs::UInt64 msg;
    msg.data = input * input;

    // Publish the squared value
    square_pub.publish(msg);

    ROS_INFO("Published square: %d", msg.data);


    //sends out any data necessary then waits based on the loop rate
    ros::spinOnce();
    loop_rate.sleep();

  }

  return 0;
}

