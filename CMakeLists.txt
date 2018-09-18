cmake_minimum_required(VERSION 2.8.3)
project(amada_forcegauge)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
)

add_message_files(
  FILES
  ForceGaugeData.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
   CATKIN_DEPENDS message_runtime message_generation rospy std_msgs
)

include_directories(
  include
  src
  ${catkin_INCLUDE_DIRS}
)

add_executable( amada_forcegauge_test src/amada_forcegauge_test.cpp src/amada_forcegauge.cpp src/serial_device_class.cpp)
add_definitions(-std=c++11)

install(PROGRAMS
  scripts/print.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(PROGRAMS
  scripts/publish.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
