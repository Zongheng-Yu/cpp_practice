# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/data/code/github/cpp_practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/data/code/github/cpp_practice

# Include any dependencies generated for this target.
include src/template/CMakeFiles/template.dir/depend.make

# Include the progress variables for this target.
include src/template/CMakeFiles/template.dir/progress.make

# Include the compile flags for this target's objects.
include src/template/CMakeFiles/template.dir/flags.make

src/template/CMakeFiles/template.dir/compare.cpp.o: src/template/CMakeFiles/template.dir/flags.make
src/template/CMakeFiles/template.dir/compare.cpp.o: src/template/compare.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/data/code/github/cpp_practice/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/template/CMakeFiles/template.dir/compare.cpp.o"
	cd /cygdrive/c/data/code/github/cpp_practice/src/template && /usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/template.dir/compare.cpp.o -c /cygdrive/c/data/code/github/cpp_practice/src/template/compare.cpp

src/template/CMakeFiles/template.dir/compare.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template.dir/compare.cpp.i"
	cd /cygdrive/c/data/code/github/cpp_practice/src/template && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/data/code/github/cpp_practice/src/template/compare.cpp > CMakeFiles/template.dir/compare.cpp.i

src/template/CMakeFiles/template.dir/compare.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template.dir/compare.cpp.s"
	cd /cygdrive/c/data/code/github/cpp_practice/src/template && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/data/code/github/cpp_practice/src/template/compare.cpp -o CMakeFiles/template.dir/compare.cpp.s

src/template/CMakeFiles/template.dir/compare.cpp.o.requires:

.PHONY : src/template/CMakeFiles/template.dir/compare.cpp.o.requires

src/template/CMakeFiles/template.dir/compare.cpp.o.provides: src/template/CMakeFiles/template.dir/compare.cpp.o.requires
	$(MAKE) -f src/template/CMakeFiles/template.dir/build.make src/template/CMakeFiles/template.dir/compare.cpp.o.provides.build
.PHONY : src/template/CMakeFiles/template.dir/compare.cpp.o.provides

src/template/CMakeFiles/template.dir/compare.cpp.o.provides.build: src/template/CMakeFiles/template.dir/compare.cpp.o


# Object files for target template
template_OBJECTS = \
"CMakeFiles/template.dir/compare.cpp.o"

# External object files for target template
template_EXTERNAL_OBJECTS =

build/libtemplate.a: src/template/CMakeFiles/template.dir/compare.cpp.o
build/libtemplate.a: src/template/CMakeFiles/template.dir/build.make
build/libtemplate.a: src/template/CMakeFiles/template.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/data/code/github/cpp_practice/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../build/libtemplate.a"
	cd /cygdrive/c/data/code/github/cpp_practice/src/template && $(CMAKE_COMMAND) -P CMakeFiles/template.dir/cmake_clean_target.cmake
	cd /cygdrive/c/data/code/github/cpp_practice/src/template && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/template.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/template/CMakeFiles/template.dir/build: build/libtemplate.a

.PHONY : src/template/CMakeFiles/template.dir/build

src/template/CMakeFiles/template.dir/requires: src/template/CMakeFiles/template.dir/compare.cpp.o.requires

.PHONY : src/template/CMakeFiles/template.dir/requires

src/template/CMakeFiles/template.dir/clean:
	cd /cygdrive/c/data/code/github/cpp_practice/src/template && $(CMAKE_COMMAND) -P CMakeFiles/template.dir/cmake_clean.cmake
.PHONY : src/template/CMakeFiles/template.dir/clean

src/template/CMakeFiles/template.dir/depend:
	cd /cygdrive/c/data/code/github/cpp_practice && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/data/code/github/cpp_practice /cygdrive/c/data/code/github/cpp_practice/src/template /cygdrive/c/data/code/github/cpp_practice /cygdrive/c/data/code/github/cpp_practice/src/template /cygdrive/c/data/code/github/cpp_practice/src/template/CMakeFiles/template.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/template/CMakeFiles/template.dir/depend

