//
// Created by ruoyo on 2020/6/27.
//
#include "twist2multiarray/Node.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "twist2multiarray");
    wtr::Node node(PR);

    ros::spin();

    return 0;
}