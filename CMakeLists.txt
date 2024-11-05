cmake_minimum_required(VERSION 3.0.2)
project(lane_detector)

add_compile_options(-std=c++14)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
        cv_bridge
)
find_package(OpenCV REQUIRED)

catkin_package(
INCLUDE_DIRS include
#  LIBRARIES lane_detector
CATKIN_DEPENDS geometry_msgs roscpp rospy sensor_msgs std_msgs cv_bridge
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
 include
  ${catkin_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/lane_detector_node.cpp
        src/lane_detector.cpp
        include/lane_detector/lane_detector.h)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
        ${OpenCV_LIBS}
)

add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
