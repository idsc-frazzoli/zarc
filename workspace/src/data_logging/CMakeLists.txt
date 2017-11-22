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



add_library(encoder_logger src/encoder_data_logger.cpp)
target_link_libraries(encoder_logger
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
)

add_library(vicon_logger src/vicon_data_logger.cpp)
target_link_libraries(vicon_logger
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
)

add_library(imu_logger src/imu_data_logger.cpp)
target_link_libraries(imu_logger
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
)

add_executable(logger_node src/logger_node.cpp)
target_link_libraries(logger_node
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
    encoder_logger
    vicon_logger
    imu_logger
)