// Includes all of the ROS libraries needed
#include "ros/ros.h"
#include <sstream>
#include <iostream>
#include <string>

// Include String message type
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  // Names the program for visual purposes
  ros::init(argc, argv, "Lab2_String_Input");
  ros::NodeHandle n;

  // Sets the frequency for which the program sleeps at. 10 = 1/10 second
  ros::Rate loop_rate(10);

  // Declare variables
  std::string string_input;
  std_msgs::String string_pub;

  // Declare publisher
  ros::Publisher chatter = n.advertise<std_msgs::String>("Lab2_String", 1);

  // ros::ok() will stop when the user inputs Ctrl+C
  while (ros::ok())
  {
    // Prompt the user for an input
    std::cout << "Enter a string: ";

    // Get the input from the user
    std::getline(std::cin, string_input);

    // Confirm the string is being sent
    std::cout << "Sending the string: " << string_input << std::endl;

    // Set the message value
    string_pub.data = string_input;

    // Publish the data
    chatter.publish(string_pub);

    // Sends out any data necessary then waits based on the loop rate
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

