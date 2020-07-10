//
// Created by ruoyo on 2020/7/10.
//
#include "wtr_odom/node.h"



wtr::odom::odom() {
    sub = nh.subscribe<geometry_msgs::Twist>("/cmd_vel",10,&wtr::odom::cmdCallback,this);
    now = last = ros::Time::now();
    duration = now-last;

    pose.x = 0;
    pose.y = 0;
    pose.theta = 0;
}

void wtr::odom::cmdCallback(const geometry_msgs::Twist::ConstPtr &msg) {
    twist = *msg;
//    LOG(INFO)<<twist.angular.z;
}

void wtr::odom::calculate_pos() {
    if (count >= 1000000)
    {

//        LOG(INFO)<<duration.nsec;
        pose.x += (twist.linear.x*cos(pose.theta)-twist.linear.y*sin(pose.theta))* dura;
        pose.y += (twist.linear.x*sin(pose.theta)+twist.linear.y*cos(pose.theta))* dura;
        pose.theta += twist.angular.z * dura;

        LOG(INFO)<<"x = "<<pose.x<<"; y = "<<pose.y<<"; theta = "<<pose.theta;
        count = 0;

        now = ros::Time::now();
        duration.sec = now.sec - last.sec;
        duration.nsec = now.nsec - last.nsec;
        dura = duration.sec + 0.000000001*(duration.nsec);
//        LOG(INFO)<<dura;
        last = now;
    }
    count++;


}

int main(int argc, char** argv)
{
    ros::init(argc,argv,"wtr_odom");
    wtr::odom odom;


    while(!ros::isShuttingDown())
    {
        odom.calculate_pos();


        ros::spinOnce();
    }
    LOG(INFO)<<"Shutdown";
    google::ShutdownGoogleLogging();

    return 0;
}