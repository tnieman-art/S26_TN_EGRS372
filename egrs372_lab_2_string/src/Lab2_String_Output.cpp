// Includes all of the ROS libraries needed
#include "ros/ros.h"
#include <sstream>
#include <iostream>
#include <string>

// Include String message type
#include "std_msgs/String.h"

// Callback function for string messages
void string_function(const std_msgs::String::ConstPtr& msg)
{
  // Get the string
  std::string received_string = msg->data;

  // Get the length of the string
  unsigned int string_length = received_string.length();

  // Output the data
  std::cout << "The string \"" << received_string
            << "\" was published and has length "
            << string_length << std::endl;
}

int main(int argc, char **argv)
{
  // Names the program for visual purposes
  ros::init(argc, argv, "Lab2_String_Output");
  ros::NodeHandle n;

  // Declare subscriber (topic name must match publisher)
  ros::Subscriber sub = n.subscribe("Lab2_String", 1, string_function);

  // Listen for incoming data
  ros::spin();

  return 0;
}


