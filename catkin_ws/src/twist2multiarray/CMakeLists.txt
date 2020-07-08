cmake_minimum_required(VERSION 3.0.2)
project(twist2multiarray)
add_compile_options(-std=c++11)

# 链接库
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
# 链接头文件
include_directories(${PROJECT_SOURCE_DIR}/include)



find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
)
include_directories(
        # include
        ${catkin_INCLUDE_DIRS}
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES twist2multiarray
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
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
add_library(node
        include/twist2multiarray/Node.h
        src/Node.cpp
        )

set(THIRD_PARTY_LIBS
        # ${GTEST_BOTH_LIBRARIES}
        ${GLOG_LIBRARIES}
        ${GFLAGS_LIBRARIES}
        #        ${Boost_LIBRARIES}
        ${catkin_LIBRARIES}
        )

add_executable(TR
        App/main_tr.cpp
        src/Node.cpp
        src/ThreeWheelControl.cpp
        src/FourWheelControl.cpp)
target_link_libraries(TR
        ${THIRD_PARTY_LIBS}
        )

add_executable(PR
        App/main_pr.cpp
        src/Node.cpp
        src/ThreeWheelControl.cpp
        src/FourWheelControl.cpp)
target_link_libraries(PR
        ${THIRD_PARTY_LIBS}
        )