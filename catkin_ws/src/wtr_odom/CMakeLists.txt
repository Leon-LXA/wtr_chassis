cmake_minimum_required(VERSION 3.0.2)
project(wtr_odom)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
        geometry_msgs
        roscpp
        rospy
        std_msgs
        )


catkin_package(

)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
         include
        ${catkin_INCLUDE_DIRS}
)
# glog
find_package(Glog REQUIRED)
include_directories(${GLOG_INCLUDE_DIRS})

# gtest
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

# gflags
find_package(GFlags REQUIRED)
include_directories(${GFLAGS_INCLUDE_DIRS})

add_library(odom
        include/wtr_odom/node.h
        src/node.cpp
        )

set(THIRD_PARTY_LIBS
        # ${GTEST_BOTH_LIBRARIES}
        ${GLOG_LIBRARIES}
        ${GFLAGS_LIBRARIES}
        #        ${Boost_LIBRARIES}
        ${catkin_LIBRARIES}
        )

add_executable(wtr_odom
        src/node.cpp include/wtr_odom/node.h
        )
target_link_libraries(wtr_odom
        ${THIRD_PARTY_LIBS}
        )