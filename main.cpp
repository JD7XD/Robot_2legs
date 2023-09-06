#include <iostream>
#include "ros/ros.h"
#include "std_msgs/Float64.h"


int main(int argc, char **argv) {
  ros::init(argc, argv, "Move");
  ros::NodeHandle n;
  
  ros::Publisher left_pub = n.advertise<std_msgs::Float64>("left_arm_controller/command", 1000);
  ros::Publisher right_pub = n.advertise<std_msgs::Float64>("right_arm_controller/command", 1000);

  char inp; int x;
  while(ros::ok()){
    std_msgs::Float64 msg;
    std::cin>> inp;
    switch(inp){
      case 'w': msg.data=1.0; break; x=0;
      case 'a': msg.data=1.0; break; x=-1;
      case 'd': msg.data=1.0; break; x=1;
      case 's': msg.data=-1.0; break; x=0;


    }
    if (x==0){
      left_pub.publish(msg);
      right_pub.publish(msg);
    }
    

  }
  
  return 0;
}