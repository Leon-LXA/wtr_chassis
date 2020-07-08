# 设置CMake最低版本
cmake_minimum_required(VERSION 2.8)
# 设置项目名
project(wtr_usb2ros)
# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
add_compile_options(-std=c++11)

# 链接头文件
include_directories(${PROJECT_SOURCE_DIR}/include)

# 链接库
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)



set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
link_directories(${LIB_DIR})
MESSAGE( STATUS "LIB_PATH = ${LIB_DIR}.")
link_libraries(USB2XXX)
link_libraries(usb-1.0)

## ros
#set(catkin_DIR /opt/ros/noetic/share/catkin/cmake)
find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        std_msgs
        message_generation
        )


add_message_files(FILES
        motor_msgs.msg
        Test.msg
        )
generate_messages(DEPENDENCIES
        std_msgs
        )

catkin_package(
        CATKIN_DEPENDS
)

# glog
find_package(Glog REQUIRED)
include_directories(${GLOG_INCLUDE_DIRS})

# gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# gflags
find_package(GFlags REQUIRED)
include_directories(${GFLAGS_INCLUDE_DIRS})



include_directories(
        include
        ${catkin_INCLUDE_DIRS}
)




set(THIRD_PARTY_LIBS
        ${GTEST_BOTH_LIBRARIES}
        ${GLOG_LIBRARIES}
        ${GFLAGS_LIBRARIES}
#        ${Boost_LIBRARIES}
        ${catkin_LIBRARIES}
        )

#生成可执行未见


#add_executable(motor src/motor_test.cpp
#                     src/can_motor.cpp src/linux_can.cpp)
#add_dependencies(motor ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
## 链接动态库
#target_link_libraries(motor
#        ${THIRD_PARTY_LIBS}
#        )

add_executable(controller src/controller.cpp include/wtr_can_motor/can_commute.h include/wtr_can_motor/vesc_Tmotor.h)
add_dependencies(controller ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(controller
        ${THIRD_PARTY_LIBS}
        )


add_executable(main App/main.cpp include/wtr_can_motor/common_include.h include/wtr_can_motor/can_commute.h include/wtr_can_motor/gpio.h)
add_dependencies(main ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(main
        ${THIRD_PARTY_LIBS}
        )

add_executable(gpio App/gpio.cpp include/wtr_can_motor/common_include.h include/wtr_can_motor/can_commute.h include/wtr_can_motor/gpio.h)
add_dependencies(gpio ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(gpio
        ${THIRD_PARTY_LIBS}
        )



