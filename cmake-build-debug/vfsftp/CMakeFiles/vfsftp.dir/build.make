# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/andrey/clion-2020.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/andrey/clion-2020.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrey/fineftpvfs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrey/fineftpvfs/cmake-build-debug

# Include any dependencies generated for this target.
include vfsftp/CMakeFiles/vfsftp.dir/depend.make

# Include the progress variables for this target.
include vfsftp/CMakeFiles/vfsftp.dir/progress.make

# Include the compile flags for this target's objects.
include vfsftp/CMakeFiles/vfsftp.dir/flags.make

vfsftp/CMakeFiles/vfsftp.dir/src/main.cpp.o: vfsftp/CMakeFiles/vfsftp.dir/flags.make
vfsftp/CMakeFiles/vfsftp.dir/src/main.cpp.o: ../vfsftp/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrey/fineftpvfs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object vfsftp/CMakeFiles/vfsftp.dir/src/main.cpp.o"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vfsftp.dir/src/main.cpp.o -c /home/andrey/fineftpvfs/vfsftp/src/main.cpp

vfsftp/CMakeFiles/vfsftp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vfsftp.dir/src/main.cpp.i"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrey/fineftpvfs/vfsftp/src/main.cpp > CMakeFiles/vfsftp.dir/src/main.cpp.i

vfsftp/CMakeFiles/vfsftp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vfsftp.dir/src/main.cpp.s"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrey/fineftpvfs/vfsftp/src/main.cpp -o CMakeFiles/vfsftp.dir/src/main.cpp.s

vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.o: vfsftp/CMakeFiles/vfsftp.dir/flags.make
vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.o: ../vfsftp/src/plugins/gcfselement.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrey/fineftpvfs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.o"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.o -c /home/andrey/fineftpvfs/vfsftp/src/plugins/gcfselement.cpp

vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.i"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrey/fineftpvfs/vfsftp/src/plugins/gcfselement.cpp > CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.i

vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.s"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrey/fineftpvfs/vfsftp/src/plugins/gcfselement.cpp -o CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.s

vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.o: vfsftp/CMakeFiles/vfsftp.dir/flags.make
vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.o: ../vfsftp/src/plugins/gcfilesystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrey/fineftpvfs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.o"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.o -c /home/andrey/fineftpvfs/vfsftp/src/plugins/gcfilesystem.cpp

vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.i"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrey/fineftpvfs/vfsftp/src/plugins/gcfilesystem.cpp > CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.i

vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.s"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrey/fineftpvfs/vfsftp/src/plugins/gcfilesystem.cpp -o CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.s

vfsftp/CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.o: vfsftp/CMakeFiles/vfsftp.dir/flags.make
vfsftp/CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.o: ../vfsftp/src/plugins/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrey/fineftpvfs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object vfsftp/CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.o"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.o -c /home/andrey/fineftpvfs/vfsftp/src/plugins/utils.cpp

vfsftp/CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.i"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrey/fineftpvfs/vfsftp/src/plugins/utils.cpp > CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.i

vfsftp/CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.s"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrey/fineftpvfs/vfsftp/src/plugins/utils.cpp -o CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.s

# Object files for target vfsftp
vfsftp_OBJECTS = \
"CMakeFiles/vfsftp.dir/src/main.cpp.o" \
"CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.o" \
"CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.o" \
"CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.o"

# External object files for target vfsftp
vfsftp_EXTERNAL_OBJECTS =

vfsftp/vfsftp: vfsftp/CMakeFiles/vfsftp.dir/src/main.cpp.o
vfsftp/vfsftp: vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfselement.cpp.o
vfsftp/vfsftp: vfsftp/CMakeFiles/vfsftp.dir/src/plugins/gcfilesystem.cpp.o
vfsftp/vfsftp: vfsftp/CMakeFiles/vfsftp.dir/src/plugins/utils.cpp.o
vfsftp/vfsftp: vfsftp/CMakeFiles/vfsftp.dir/build.make
vfsftp/vfsftp: fineftp-server/libfineftp-server.a
vfsftp/vfsftp: vfsftp/fmt/libfmtd.a
vfsftp/vfsftp: vfsftp/CMakeFiles/vfsftp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrey/fineftpvfs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable vfsftp"
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vfsftp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vfsftp/CMakeFiles/vfsftp.dir/build: vfsftp/vfsftp

.PHONY : vfsftp/CMakeFiles/vfsftp.dir/build

vfsftp/CMakeFiles/vfsftp.dir/clean:
	cd /home/andrey/fineftpvfs/cmake-build-debug/vfsftp && $(CMAKE_COMMAND) -P CMakeFiles/vfsftp.dir/cmake_clean.cmake
.PHONY : vfsftp/CMakeFiles/vfsftp.dir/clean

vfsftp/CMakeFiles/vfsftp.dir/depend:
	cd /home/andrey/fineftpvfs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrey/fineftpvfs /home/andrey/fineftpvfs/vfsftp /home/andrey/fineftpvfs/cmake-build-debug /home/andrey/fineftpvfs/cmake-build-debug/vfsftp /home/andrey/fineftpvfs/cmake-build-debug/vfsftp/CMakeFiles/vfsftp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vfsftp/CMakeFiles/vfsftp.dir/depend
