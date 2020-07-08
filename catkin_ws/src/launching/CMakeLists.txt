cmake_minimum_required(VERSION 3.0.2)
project(launching)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)
# 链接库
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
        geometry_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES launching
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
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


## Declare a C++ library
add_library(launch_node
        include/launching/launch_node.h
        src/launch_node.cpp
        )

set(THIRD_PARTY_LIBS
        # ${GTEST_BOTH_LIBRARIES}
        ${GLOG_LIBRARIES}
        ${GFLAGS_LIBRARIES}
        #        ${Boost_LIBRARIES}
        ${catkin_LIBRARIES}
        )

add_executable(launching
        src/launch_node.cpp include/launching/launch_node.h
        )
target_link_libraries(launching
        ${THIRD_PARTY_LIBS}
        )