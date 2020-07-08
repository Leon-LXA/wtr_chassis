cmake_minimum_required(VERSION 3.5)
project(joy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Load catkin and all dependencies required for this package
set(CATKIN_DEPS roscpp diagnostic_updater sensor_msgs roslint)
find_package(catkin REQUIRED ${CATKIN_DEPS})

roslint_cpp()

catkin_package(DEPENDS sensor_msgs)

# Look for <linux/joystick.h>
include(CheckIncludeFiles)
check_include_files(linux/joystick.h HAVE_LINUX_JOYSTICK_H)

if(CATKIN_ENABLE_TESTING)
  roslint_add_test()
endif()

if(HAVE_LINUX_JOYSTICK_H)
  include_directories(msg/cpp ${catkin_INCLUDE_DIRS})
  add_executable(joy_node src/joy_node.cpp)
  target_link_libraries(joy_node ${catkin_LIBRARIES})

# Install targets
  install(TARGETS joy_node
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
else()
  message("Warning: no <linux/joystick.h>; won't build joy node")
endif()

install(DIRECTORY migration_rules scripts config launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  USE_SOURCE_PERMISSIONS)
  
  
add_executable(xbox
  src/xbox.cpp
)
add_dependencies(xbox ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(xbox
  ${catkin_LIBRARIES}
)

add_executable(gpio_joy
        src/gpio_joy.cpp
        )
add_dependencies(gpio_joy ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(gpio_joy
        ${catkin_LIBRARIES}
        )

