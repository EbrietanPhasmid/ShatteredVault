# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/marcinzawadiak/Desk/SDLGAME

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/marcinzawadiak/Desk/SDLGAME/build

# Include any dependencies generated for this target.
include CMakeFiles/Shattered-Vault.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Shattered-Vault.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Shattered-Vault.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Shattered-Vault.dir/flags.make

CMakeFiles/Shattered-Vault.dir/codegen:
.PHONY : CMakeFiles/Shattered-Vault.dir/codegen

CMakeFiles/Shattered-Vault.dir/src/main.cc.o: CMakeFiles/Shattered-Vault.dir/flags.make
CMakeFiles/Shattered-Vault.dir/src/main.cc.o: /Users/marcinzawadiak/Desk/SDLGAME/src/main.cc
CMakeFiles/Shattered-Vault.dir/src/main.cc.o: CMakeFiles/Shattered-Vault.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/marcinzawadiak/Desk/SDLGAME/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Shattered-Vault.dir/src/main.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shattered-Vault.dir/src/main.cc.o -MF CMakeFiles/Shattered-Vault.dir/src/main.cc.o.d -o CMakeFiles/Shattered-Vault.dir/src/main.cc.o -c /Users/marcinzawadiak/Desk/SDLGAME/src/main.cc

CMakeFiles/Shattered-Vault.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shattered-Vault.dir/src/main.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marcinzawadiak/Desk/SDLGAME/src/main.cc > CMakeFiles/Shattered-Vault.dir/src/main.cc.i

CMakeFiles/Shattered-Vault.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shattered-Vault.dir/src/main.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marcinzawadiak/Desk/SDLGAME/src/main.cc -o CMakeFiles/Shattered-Vault.dir/src/main.cc.s

# Object files for target Shattered-Vault
Shattered__Vault_OBJECTS = \
"CMakeFiles/Shattered-Vault.dir/src/main.cc.o"

# External object files for target Shattered-Vault
Shattered__Vault_EXTERNAL_OBJECTS =

Shattered-Vault: CMakeFiles/Shattered-Vault.dir/src/main.cc.o
Shattered-Vault: CMakeFiles/Shattered-Vault.dir/build.make
Shattered-Vault: CMakeFiles/Shattered-Vault.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/marcinzawadiak/Desk/SDLGAME/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Shattered-Vault"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Shattered-Vault.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Shattered-Vault.dir/build: Shattered-Vault
.PHONY : CMakeFiles/Shattered-Vault.dir/build

CMakeFiles/Shattered-Vault.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Shattered-Vault.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Shattered-Vault.dir/clean

CMakeFiles/Shattered-Vault.dir/depend:
	cd /Users/marcinzawadiak/Desk/SDLGAME/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/marcinzawadiak/Desk/SDLGAME /Users/marcinzawadiak/Desk/SDLGAME /Users/marcinzawadiak/Desk/SDLGAME/build /Users/marcinzawadiak/Desk/SDLGAME/build /Users/marcinzawadiak/Desk/SDLGAME/build/CMakeFiles/Shattered-Vault.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Shattered-Vault.dir/depend

