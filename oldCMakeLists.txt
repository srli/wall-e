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

include_directories("nite/Include")
include_directories("nite/Source/XnCommon")
include_directories("/usr/include/ni")
include_directories("${PROJECT_SOURCE_DIR}/include/walle")
find_package(OpenCV)
find_package(OpenGL)
include_directories("${OpenCV_INCLUDE_DIRS}")

rosbuild_add_executable(detectfinger src/SingleControl/main.cpp)
	target_link_libraries(detectfinger ${OpenCV_LIBRARIES} -lOpenNI -lXnVNite_1_5_2)

#rosbuild_add_executable(sceneanalysis src/SceneAnalysis/main.cpp src/SceneAnalysis/SceneDrawer.cpp src/SceneAnalysis/signal_catch.cpp src/SceneAnalysis/opengles.cpp src/SceneAnalysis/kbhit.cpp)
#	target_link_libraries(sceneanalysis ${OpenCV_LIBRARIES} -lOpenNI -lXnVNite_1_5_2 -lGL -lGLU glut64 /usr/lib/x86_64-linux-gnu/libglut.a /usr/lib/x86_64-linux-gnu/libGL.a)


#rosbuild_add_executable(detectfingerviewer src/PointViewer/main.cpp src/PointViewer/PointDrawer.cpp)
#	target_link_libraries(detectfingerviewer ${OpenCV_LIBRARIES} -lOpenNI -lXnVNite_1_5_2 -lGL -lGLU)#-lGL -lGLU) # glut64) #/usr/lib/x86_64-linux-gnu/libglut.a /usr/lib/x86_64-linux-gnu/libGL.a)
#rosbuild_add_executable(detectpeople src/detectpeople.cpp)
#  target_link_libraries(detectpeople ${OpenCV_LIBRARIES})

rosbuild_add_executable(image_converter src/image_converter.cpp)
  target_link_libraries(image_converter ${OpenCV_LIBRARIES})
