cmake_minimum_required(VERSION 2.8.3)
project(data_logger)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    geometry_msgs
    barc
)

find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wfatal-errors")


catkin_package(CATKIN_DEPENDS 
    roscpp
    geometry_msgs
    barc 
)



include_directories(include 
src 
${catkin_INCLUDE_DIRS} 
${Boost_INCLUDE_DIRS} 
${EIGEN3_INCLUDE_DIR})



#add_executable(vicon_logging_node src/vicon_logging_node.cpp)
#target_link_libraries(vicon_logging_node
#    ${catkin_LIBRARIES}
#    ${Boost_LIBRARIES}
#)
#
#add_executable(odroid_logging_node src/odroid_logging_node.cpp)
#target_link_libraries(odroid_logging_node
#    ${catkin_LIBRARIES}
#    ${Boost_LIBRARIES}
#)

add_executable(logger_node src/logger_node.cpp)
target_link_libraries(logger_node
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
)