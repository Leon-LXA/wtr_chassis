# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/kevin/Apps/Clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kevin/Apps/Clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TR.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TR.dir/flags.make

CMakeFiles/TR.dir/App/main_tr.cpp.o: CMakeFiles/TR.dir/flags.make
CMakeFiles/TR.dir/App/main_tr.cpp.o: ../App/main_tr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TR.dir/App/main_tr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TR.dir/App/main_tr.cpp.o -c /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/App/main_tr.cpp

CMakeFiles/TR.dir/App/main_tr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TR.dir/App/main_tr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/App/main_tr.cpp > CMakeFiles/TR.dir/App/main_tr.cpp.i

CMakeFiles/TR.dir/App/main_tr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TR.dir/App/main_tr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/App/main_tr.cpp -o CMakeFiles/TR.dir/App/main_tr.cpp.s

CMakeFiles/TR.dir/src/Node.cpp.o: CMakeFiles/TR.dir/flags.make
CMakeFiles/TR.dir/src/Node.cpp.o: ../src/Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TR.dir/src/Node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TR.dir/src/Node.cpp.o -c /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/src/Node.cpp

CMakeFiles/TR.dir/src/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TR.dir/src/Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/src/Node.cpp > CMakeFiles/TR.dir/src/Node.cpp.i

CMakeFiles/TR.dir/src/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TR.dir/src/Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/src/Node.cpp -o CMakeFiles/TR.dir/src/Node.cpp.s

CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.o: CMakeFiles/TR.dir/flags.make
CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.o: ../src/ThreeWheelControl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.o -c /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/src/ThreeWheelControl.cpp

CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/src/ThreeWheelControl.cpp > CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.i

CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/src/ThreeWheelControl.cpp -o CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.s

CMakeFiles/TR.dir/src/FourWheelControl.cpp.o: CMakeFiles/TR.dir/flags.make
CMakeFiles/TR.dir/src/FourWheelControl.cpp.o: ../src/FourWheelControl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TR.dir/src/FourWheelControl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TR.dir/src/FourWheelControl.cpp.o -c /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/src/FourWheelControl.cpp

CMakeFiles/TR.dir/src/FourWheelControl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TR.dir/src/FourWheelControl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/src/FourWheelControl.cpp > CMakeFiles/TR.dir/src/FourWheelControl.cpp.i

CMakeFiles/TR.dir/src/FourWheelControl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TR.dir/src/FourWheelControl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/src/FourWheelControl.cpp -o CMakeFiles/TR.dir/src/FourWheelControl.cpp.s

# Object files for target TR
TR_OBJECTS = \
"CMakeFiles/TR.dir/App/main_tr.cpp.o" \
"CMakeFiles/TR.dir/src/Node.cpp.o" \
"CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.o" \
"CMakeFiles/TR.dir/src/FourWheelControl.cpp.o"

# External object files for target TR
TR_EXTERNAL_OBJECTS =

devel/lib/twist2multiarray/TR: CMakeFiles/TR.dir/App/main_tr.cpp.o
devel/lib/twist2multiarray/TR: CMakeFiles/TR.dir/src/Node.cpp.o
devel/lib/twist2multiarray/TR: CMakeFiles/TR.dir/src/ThreeWheelControl.cpp.o
devel/lib/twist2multiarray/TR: CMakeFiles/TR.dir/src/FourWheelControl.cpp.o
devel/lib/twist2multiarray/TR: CMakeFiles/TR.dir/build.make
devel/lib/twist2multiarray/TR: /usr/local/lib/libglog.a
devel/lib/twist2multiarray/TR: /usr/local/lib/libgflags.a
devel/lib/twist2multiarray/TR: /opt/ros/noetic/lib/libroscpp.so
devel/lib/twist2multiarray/TR: /usr/lib/x86_64-linux-gnu/libpthread.so
devel/lib/twist2multiarray/TR: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
devel/lib/twist2multiarray/TR: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
devel/lib/twist2multiarray/TR: /opt/ros/noetic/lib/librosconsole.so
devel/lib/twist2multiarray/TR: /opt/ros/noetic/lib/librosconsole_log4cxx.so
devel/lib/twist2multiarray/TR: /opt/ros/noetic/lib/librosconsole_backend_interface.so
devel/lib/twist2multiarray/TR: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
devel/lib/twist2multiarray/TR: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
devel/lib/twist2multiarray/TR: /opt/ros/noetic/lib/libxmlrpcpp.so
devel/lib/twist2multiarray/TR: /opt/ros/noetic/lib/libroscpp_serialization.so
devel/lib/twist2multiarray/TR: /opt/ros/noetic/lib/librostime.so
devel/lib/twist2multiarray/TR: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
devel/lib/twist2multiarray/TR: /opt/ros/noetic/lib/libcpp_common.so
devel/lib/twist2multiarray/TR: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
devel/lib/twist2multiarray/TR: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
devel/lib/twist2multiarray/TR: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
devel/lib/twist2multiarray/TR: CMakeFiles/TR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable devel/lib/twist2multiarray/TR"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TR.dir/build: devel/lib/twist2multiarray/TR

.PHONY : CMakeFiles/TR.dir/build

CMakeFiles/TR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TR.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TR.dir/clean

CMakeFiles/TR.dir/depend:
	cd /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/cmake-build-debug /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/cmake-build-debug /home/kevin/Desktop/wtrCanInterface/catkin_ws/src/twist2multiarray/cmake-build-debug/CMakeFiles/TR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TR.dir/depend

