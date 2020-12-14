cmake_minimum_required(VERSION 2.8.3)

project(advanced_experiment)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	rospy
	std_msgs
	genmsg
	sensor_msgs
	geometry_msgs
	opencv_apps
)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})

add_executable(image_acquisition src/image_acquisition.cpp)
target_link_libraries(image_acquisition ${catkin_LIBRARIES})

add_executable(turtle_operation src/turtle_operation.cpp)
target_link_libraries(turtle_operation ${catkin_LIBRARIES})
