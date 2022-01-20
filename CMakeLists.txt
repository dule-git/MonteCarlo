cmake_minimum_required(VERSION 3.17)
set(CMAKE_TOOLCHAIN_FILE C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake)
project(MonteCarlo)

enable_testing()

find_package(log4cplus REQUIRED)

set(SOURCE_FILES
        src/main.cpp
        src/PhotonGenerator.cpp
        src/Photon.cpp
        src/Vector3D.cpp
        src/GeometryUtils.cpp
        src/Detector.cpp
        src/Phantom.cpp
        src/Ellipsoid.cpp
        src/MiTableProvider.cpp
        src/Interaction.cpp
        src/CoherentRace.cpp
        src/DistributionFunctionTableProvider.cpp
)
set(INCLUDE_FILES
        inc/PhotonGenerator.h
        inc/Photon.h
        inc/stdinc.h
        inc/main.h
        inc/Vector3D.h
        inc/GeometryUtils.h
        inc/Detector.h
        inc/Phantom.h
        inc/Ellipsoid.h
        inc/MiTableProvider.h
        inc/Interaction.h
        inc/CoherentRace.h
        inc/DistributionFunctionTableProvider.h)

add_executable(MonteCarlo ${SOURCE_FILES} ${INCLUDE_FILES})
target_include_directories(MonteCarlo PUBLIC "C:/dev/vcpkg/packages/log4cplus_x86-windows/include")
target_include_directories(MonteCarlo PUBLIC "./inc/")
#target_link_libraries(MonteCarlo "C:/dev/vcpkg/packages/log4cplus_x86-windows/lib/log4cplus.lib")
target_link_libraries(MonteCarlo "C:/dev/vcpkg/packages/log4cplus_x86-windows/debug/lib/log4cplusD.lib")