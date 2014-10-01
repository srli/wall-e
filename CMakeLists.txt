cmake_minimum_required(VERSION 2.8.3)
project(walle)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#Generates defined messages
rosbuild_genmsg()

include_directories("${PROJECT_SOURCE_DIR}/include/walle")
find_package(OpenCV)
include_directories("${OpenCV_INCLUDE_DIRS}")
   #target_link_libraries(my_awesome_library ${OpenCV_LIBRARIES})

rosbuild_add_executable(test_walle src/detectpeople.cpp)
  target_link_libraries(test_walle ${OpenCV_LIBRARIES})
