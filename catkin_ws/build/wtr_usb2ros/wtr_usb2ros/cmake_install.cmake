# Install script for directory: /home/ruoyo/WTR/wtr_chassis/catkin_ws/src/wtr_usb2ros/wtr_usb2ros

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ruoyo/WTR/wtr_chassis/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/wtr_usb2ros/msg" TYPE FILE FILES
    "/home/ruoyo/WTR/wtr_chassis/catkin_ws/src/wtr_usb2ros/wtr_usb2ros/msg/motor_msgs.msg"
    "/home/ruoyo/WTR/wtr_chassis/catkin_ws/src/wtr_usb2ros/wtr_usb2ros/msg/Test.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/wtr_usb2ros/cmake" TYPE FILE FILES "/home/ruoyo/WTR/wtr_chassis/catkin_ws/build/wtr_usb2ros/wtr_usb2ros/catkin_generated/installspace/wtr_usb2ros-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/ruoyo/WTR/wtr_chassis/catkin_ws/devel/include/wtr_usb2ros")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/ruoyo/WTR/wtr_chassis/catkin_ws/devel/share/roseus/ros/wtr_usb2ros")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/ruoyo/WTR/wtr_chassis/catkin_ws/devel/share/common-lisp/ros/wtr_usb2ros")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/ruoyo/WTR/wtr_chassis/catkin_ws/devel/share/gennodejs/ros/wtr_usb2ros")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/ruoyo/WTR/wtr_chassis/catkin_ws/devel/lib/python2.7/dist-packages/wtr_usb2ros")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/ruoyo/WTR/wtr_chassis/catkin_ws/devel/lib/python2.7/dist-packages/wtr_usb2ros")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/ruoyo/WTR/wtr_chassis/catkin_ws/build/wtr_usb2ros/wtr_usb2ros/catkin_generated/installspace/wtr_usb2ros.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/wtr_usb2ros/cmake" TYPE FILE FILES "/home/ruoyo/WTR/wtr_chassis/catkin_ws/build/wtr_usb2ros/wtr_usb2ros/catkin_generated/installspace/wtr_usb2ros-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/wtr_usb2ros/cmake" TYPE FILE FILES
    "/home/ruoyo/WTR/wtr_chassis/catkin_ws/build/wtr_usb2ros/wtr_usb2ros/catkin_generated/installspace/wtr_usb2rosConfig.cmake"
    "/home/ruoyo/WTR/wtr_chassis/catkin_ws/build/wtr_usb2ros/wtr_usb2ros/catkin_generated/installspace/wtr_usb2rosConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/wtr_usb2ros" TYPE FILE FILES "/home/ruoyo/WTR/wtr_chassis/catkin_ws/src/wtr_usb2ros/wtr_usb2ros/package.xml")
endif()

