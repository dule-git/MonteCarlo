﻿# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\dusan\Desktop\Projects\MonteCarlo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\MonteCarlo.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\MonteCarlo.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\MonteCarlo.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\MonteCarlo.dir\flags.make

CMakeFiles\MonteCarlo.dir\src\main.cpp.obj: CMakeFiles\MonteCarlo.dir\flags.make
CMakeFiles\MonteCarlo.dir\src\main.cpp.obj: ..\src\main.cpp
CMakeFiles\MonteCarlo.dir\src\main.cpp.obj: CMakeFiles\MonteCarlo.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MonteCarlo.dir/src/main.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\MonteCarlo.dir\src\main.cpp.obj.d --working-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\MonteCarlo.dir\src\main.cpp.obj /FdCMakeFiles\MonteCarlo.dir\ /FS -c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\main.cpp
<<

CMakeFiles\MonteCarlo.dir\src\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MonteCarlo.dir/src/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\MonteCarlo.dir\src\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dusan\Desktop\Projects\MonteCarlo\src\main.cpp
<<

CMakeFiles\MonteCarlo.dir\src\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MonteCarlo.dir/src/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MonteCarlo.dir\src\main.cpp.s /c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\main.cpp
<<

CMakeFiles\MonteCarlo.dir\src\PhotonGenerator.cpp.obj: CMakeFiles\MonteCarlo.dir\flags.make
CMakeFiles\MonteCarlo.dir\src\PhotonGenerator.cpp.obj: ..\src\PhotonGenerator.cpp
CMakeFiles\MonteCarlo.dir\src\PhotonGenerator.cpp.obj: CMakeFiles\MonteCarlo.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MonteCarlo.dir/src/PhotonGenerator.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\MonteCarlo.dir\src\PhotonGenerator.cpp.obj.d --working-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\MonteCarlo.dir\src\PhotonGenerator.cpp.obj /FdCMakeFiles\MonteCarlo.dir\ /FS -c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\PhotonGenerator.cpp
<<

CMakeFiles\MonteCarlo.dir\src\PhotonGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MonteCarlo.dir/src/PhotonGenerator.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\MonteCarlo.dir\src\PhotonGenerator.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dusan\Desktop\Projects\MonteCarlo\src\PhotonGenerator.cpp
<<

CMakeFiles\MonteCarlo.dir\src\PhotonGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MonteCarlo.dir/src/PhotonGenerator.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MonteCarlo.dir\src\PhotonGenerator.cpp.s /c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\PhotonGenerator.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Photon.cpp.obj: CMakeFiles\MonteCarlo.dir\flags.make
CMakeFiles\MonteCarlo.dir\src\Photon.cpp.obj: ..\src\Photon.cpp
CMakeFiles\MonteCarlo.dir\src\Photon.cpp.obj: CMakeFiles\MonteCarlo.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MonteCarlo.dir/src/Photon.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\MonteCarlo.dir\src\Photon.cpp.obj.d --working-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\MonteCarlo.dir\src\Photon.cpp.obj /FdCMakeFiles\MonteCarlo.dir\ /FS -c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Photon.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Photon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MonteCarlo.dir/src/Photon.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\MonteCarlo.dir\src\Photon.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Photon.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Photon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MonteCarlo.dir/src/Photon.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MonteCarlo.dir\src\Photon.cpp.s /c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Photon.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Vector3D.cpp.obj: CMakeFiles\MonteCarlo.dir\flags.make
CMakeFiles\MonteCarlo.dir\src\Vector3D.cpp.obj: ..\src\Vector3D.cpp
CMakeFiles\MonteCarlo.dir\src\Vector3D.cpp.obj: CMakeFiles\MonteCarlo.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MonteCarlo.dir/src/Vector3D.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\MonteCarlo.dir\src\Vector3D.cpp.obj.d --working-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\MonteCarlo.dir\src\Vector3D.cpp.obj /FdCMakeFiles\MonteCarlo.dir\ /FS -c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Vector3D.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Vector3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MonteCarlo.dir/src/Vector3D.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\MonteCarlo.dir\src\Vector3D.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Vector3D.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Vector3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MonteCarlo.dir/src/Vector3D.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MonteCarlo.dir\src\Vector3D.cpp.s /c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Vector3D.cpp
<<

CMakeFiles\MonteCarlo.dir\src\GeometryUtils.cpp.obj: CMakeFiles\MonteCarlo.dir\flags.make
CMakeFiles\MonteCarlo.dir\src\GeometryUtils.cpp.obj: ..\src\GeometryUtils.cpp
CMakeFiles\MonteCarlo.dir\src\GeometryUtils.cpp.obj: CMakeFiles\MonteCarlo.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MonteCarlo.dir/src/GeometryUtils.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\MonteCarlo.dir\src\GeometryUtils.cpp.obj.d --working-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\MonteCarlo.dir\src\GeometryUtils.cpp.obj /FdCMakeFiles\MonteCarlo.dir\ /FS -c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\GeometryUtils.cpp
<<

CMakeFiles\MonteCarlo.dir\src\GeometryUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MonteCarlo.dir/src/GeometryUtils.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\MonteCarlo.dir\src\GeometryUtils.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dusan\Desktop\Projects\MonteCarlo\src\GeometryUtils.cpp
<<

CMakeFiles\MonteCarlo.dir\src\GeometryUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MonteCarlo.dir/src/GeometryUtils.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MonteCarlo.dir\src\GeometryUtils.cpp.s /c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\GeometryUtils.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Detector.cpp.obj: CMakeFiles\MonteCarlo.dir\flags.make
CMakeFiles\MonteCarlo.dir\src\Detector.cpp.obj: ..\src\Detector.cpp
CMakeFiles\MonteCarlo.dir\src\Detector.cpp.obj: CMakeFiles\MonteCarlo.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MonteCarlo.dir/src/Detector.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\MonteCarlo.dir\src\Detector.cpp.obj.d --working-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\MonteCarlo.dir\src\Detector.cpp.obj /FdCMakeFiles\MonteCarlo.dir\ /FS -c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Detector.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MonteCarlo.dir/src/Detector.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\MonteCarlo.dir\src\Detector.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Detector.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MonteCarlo.dir/src/Detector.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MonteCarlo.dir\src\Detector.cpp.s /c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Detector.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Phantom.cpp.obj: CMakeFiles\MonteCarlo.dir\flags.make
CMakeFiles\MonteCarlo.dir\src\Phantom.cpp.obj: ..\src\Phantom.cpp
CMakeFiles\MonteCarlo.dir\src\Phantom.cpp.obj: CMakeFiles\MonteCarlo.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/MonteCarlo.dir/src/Phantom.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\MonteCarlo.dir\src\Phantom.cpp.obj.d --working-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\MonteCarlo.dir\src\Phantom.cpp.obj /FdCMakeFiles\MonteCarlo.dir\ /FS -c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Phantom.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Phantom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MonteCarlo.dir/src/Phantom.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\MonteCarlo.dir\src\Phantom.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Phantom.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Phantom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MonteCarlo.dir/src/Phantom.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MonteCarlo.dir\src\Phantom.cpp.s /c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Phantom.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Ellipsoid.cpp.obj: CMakeFiles\MonteCarlo.dir\flags.make
CMakeFiles\MonteCarlo.dir\src\Ellipsoid.cpp.obj: ..\src\Ellipsoid.cpp
CMakeFiles\MonteCarlo.dir\src\Ellipsoid.cpp.obj: CMakeFiles\MonteCarlo.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/MonteCarlo.dir/src/Ellipsoid.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\MonteCarlo.dir\src\Ellipsoid.cpp.obj.d --working-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\MonteCarlo.dir\src\Ellipsoid.cpp.obj /FdCMakeFiles\MonteCarlo.dir\ /FS -c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Ellipsoid.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Ellipsoid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MonteCarlo.dir/src/Ellipsoid.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\MonteCarlo.dir\src\Ellipsoid.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Ellipsoid.cpp
<<

CMakeFiles\MonteCarlo.dir\src\Ellipsoid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MonteCarlo.dir/src/Ellipsoid.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MonteCarlo.dir\src\Ellipsoid.cpp.s /c C:\Users\dusan\Desktop\Projects\MonteCarlo\src\Ellipsoid.cpp
<<

# Object files for target MonteCarlo
MonteCarlo_OBJECTS = \
"CMakeFiles\MonteCarlo.dir\src\main.cpp.obj" \
"CMakeFiles\MonteCarlo.dir\src\PhotonGenerator.cpp.obj" \
"CMakeFiles\MonteCarlo.dir\src\Photon.cpp.obj" \
"CMakeFiles\MonteCarlo.dir\src\Vector3D.cpp.obj" \
"CMakeFiles\MonteCarlo.dir\src\GeometryUtils.cpp.obj" \
"CMakeFiles\MonteCarlo.dir\src\Detector.cpp.obj" \
"CMakeFiles\MonteCarlo.dir\src\Phantom.cpp.obj" \
"CMakeFiles\MonteCarlo.dir\src\Ellipsoid.cpp.obj"

# External object files for target MonteCarlo
MonteCarlo_EXTERNAL_OBJECTS =

MonteCarlo.exe: CMakeFiles\MonteCarlo.dir\src\main.cpp.obj
MonteCarlo.exe: CMakeFiles\MonteCarlo.dir\src\PhotonGenerator.cpp.obj
MonteCarlo.exe: CMakeFiles\MonteCarlo.dir\src\Photon.cpp.obj
MonteCarlo.exe: CMakeFiles\MonteCarlo.dir\src\Vector3D.cpp.obj
MonteCarlo.exe: CMakeFiles\MonteCarlo.dir\src\GeometryUtils.cpp.obj
MonteCarlo.exe: CMakeFiles\MonteCarlo.dir\src\Detector.cpp.obj
MonteCarlo.exe: CMakeFiles\MonteCarlo.dir\src\Phantom.cpp.obj
MonteCarlo.exe: CMakeFiles\MonteCarlo.dir\src\Ellipsoid.cpp.obj
MonteCarlo.exe: CMakeFiles\MonteCarlo.dir\build.make
MonteCarlo.exe: C:\dev\vcpkg\packages\log4cplus_x86-windows\debug\lib\log4cplusD.lib
MonteCarlo.exe: CMakeFiles\MonteCarlo.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable MonteCarlo.exe"
	"C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\MonteCarlo.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2017\ENTERP~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\MonteCarlo.dir\objects1.rsp @<<
 /out:MonteCarlo.exe /implib:MonteCarlo.lib /pdb:C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug\MonteCarlo.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  C:\dev\vcpkg\packages\log4cplus_x86-windows\debug\lib\log4cplusD.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe -noprofile -executionpolicy Bypass -file C:/dev/vcpkg/scripts/buildsystems/msbuild/applocal.ps1 -targetBinary C:/Users/dusan/Desktop/Projects/MonteCarlo/cmake-build-debug/MonteCarlo.exe -installedDir C:/dev/vcpkg/installed/x86-windows/debug/bin -OutVariable out

# Rule to build all files generated by this target.
CMakeFiles\MonteCarlo.dir\build: MonteCarlo.exe
.PHONY : CMakeFiles\MonteCarlo.dir\build

CMakeFiles\MonteCarlo.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MonteCarlo.dir\cmake_clean.cmake
.PHONY : CMakeFiles\MonteCarlo.dir\clean

CMakeFiles\MonteCarlo.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\dusan\Desktop\Projects\MonteCarlo C:\Users\dusan\Desktop\Projects\MonteCarlo C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug C:\Users\dusan\Desktop\Projects\MonteCarlo\cmake-build-debug\CMakeFiles\MonteCarlo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\MonteCarlo.dir\depend
