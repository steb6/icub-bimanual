# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/woolfrey/workspace/icub-bimanual

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/woolfrey/workspace/icub-bimanual/build

# Include any dependencies generated for this target.
include CMakeFiles/icub2_grasp_demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/icub2_grasp_demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/icub2_grasp_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/icub2_grasp_demo.dir/flags.make

CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.o: CMakeFiles/icub2_grasp_demo.dir/flags.make
CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.o: ../src/icub2_grasp_demo.cpp
CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.o: CMakeFiles/icub2_grasp_demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/woolfrey/workspace/icub-bimanual/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.o -MF CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.o.d -o CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.o -c /home/woolfrey/workspace/icub-bimanual/src/icub2_grasp_demo.cpp

CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/woolfrey/workspace/icub-bimanual/src/icub2_grasp_demo.cpp > CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.i

CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/woolfrey/workspace/icub-bimanual/src/icub2_grasp_demo.cpp -o CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.s

CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.o: CMakeFiles/icub2_grasp_demo.dir/flags.make
CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.o: ../include/PositionControl.cpp
CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.o: CMakeFiles/icub2_grasp_demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/woolfrey/workspace/icub-bimanual/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.o -MF CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.o.d -o CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.o -c /home/woolfrey/workspace/icub-bimanual/include/PositionControl.cpp

CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/woolfrey/workspace/icub-bimanual/include/PositionControl.cpp > CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.i

CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/woolfrey/workspace/icub-bimanual/include/PositionControl.cpp -o CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.s

CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.o: CMakeFiles/icub2_grasp_demo.dir/flags.make
CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.o: ../include/iCubBase.cpp
CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.o: CMakeFiles/icub2_grasp_demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/woolfrey/workspace/icub-bimanual/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.o -MF CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.o.d -o CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.o -c /home/woolfrey/workspace/icub-bimanual/include/iCubBase.cpp

CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/woolfrey/workspace/icub-bimanual/include/iCubBase.cpp > CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.i

CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/woolfrey/workspace/icub-bimanual/include/iCubBase.cpp -o CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.s

CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.o: CMakeFiles/icub2_grasp_demo.dir/flags.make
CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.o: ../include/JointInterface.cpp
CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.o: CMakeFiles/icub2_grasp_demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/woolfrey/workspace/icub-bimanual/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.o -MF CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.o.d -o CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.o -c /home/woolfrey/workspace/icub-bimanual/include/JointInterface.cpp

CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/woolfrey/workspace/icub-bimanual/include/JointInterface.cpp > CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.i

CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/woolfrey/workspace/icub-bimanual/include/JointInterface.cpp -o CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.s

# Object files for target icub2_grasp_demo
icub2_grasp_demo_OBJECTS = \
"CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.o" \
"CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.o" \
"CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.o" \
"CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.o"

# External object files for target icub2_grasp_demo
icub2_grasp_demo_EXTERNAL_OBJECTS =

bin/icub2_grasp_demo: CMakeFiles/icub2_grasp_demo.dir/src/icub2_grasp_demo.cpp.o
bin/icub2_grasp_demo: CMakeFiles/icub2_grasp_demo.dir/include/PositionControl.cpp.o
bin/icub2_grasp_demo: CMakeFiles/icub2_grasp_demo.dir/include/iCubBase.cpp.o
bin/icub2_grasp_demo: CMakeFiles/icub2_grasp_demo.dir/include/JointInterface.cpp.o
bin/icub2_grasp_demo: CMakeFiles/icub2_grasp_demo.dir/build.make
bin/icub2_grasp_demo: /home/woolfrey/workspace/robotology-superbuild/build/install/lib/libidyntree-high-level.so
bin/icub2_grasp_demo: /home/woolfrey/workspace/robotology-superbuild/build/install/lib/libYARP_init.so.3.7.2
bin/icub2_grasp_demo: /home/woolfrey/workspace/robotology-superbuild/build/install/lib/libYARP_dev.so.3.7.2
bin/icub2_grasp_demo: /home/woolfrey/workspace/robotology-superbuild/build/install/lib/libYARP_math.so.3.7.2
bin/icub2_grasp_demo: /home/woolfrey/workspace/robotology-superbuild/build/install/lib/libidyntree-modelio.so
bin/icub2_grasp_demo: /home/woolfrey/workspace/robotology-superbuild/build/install/lib/libidyntree-sensors.so
bin/icub2_grasp_demo: /home/woolfrey/workspace/robotology-superbuild/build/install/lib/libidyntree-model.so
bin/icub2_grasp_demo: /home/woolfrey/workspace/robotology-superbuild/build/install/lib/libidyntree-modelio-xml.so
bin/icub2_grasp_demo: /home/woolfrey/workspace/robotology-superbuild/build/install/lib/libidyntree-core.so
bin/icub2_grasp_demo: /home/woolfrey/workspace/robotology-superbuild/build/install/lib/libYARP_sig.so.3.7.2
bin/icub2_grasp_demo: /home/woolfrey/workspace/robotology-superbuild/build/install/lib/libYARP_os.so.3.7.2
bin/icub2_grasp_demo: CMakeFiles/icub2_grasp_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/woolfrey/workspace/icub-bimanual/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bin/icub2_grasp_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/icub2_grasp_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/icub2_grasp_demo.dir/build: bin/icub2_grasp_demo
.PHONY : CMakeFiles/icub2_grasp_demo.dir/build

CMakeFiles/icub2_grasp_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/icub2_grasp_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/icub2_grasp_demo.dir/clean

CMakeFiles/icub2_grasp_demo.dir/depend:
	cd /home/woolfrey/workspace/icub-bimanual/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/woolfrey/workspace/icub-bimanual /home/woolfrey/workspace/icub-bimanual /home/woolfrey/workspace/icub-bimanual/build /home/woolfrey/workspace/icub-bimanual/build /home/woolfrey/workspace/icub-bimanual/build/CMakeFiles/icub2_grasp_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/icub2_grasp_demo.dir/depend

