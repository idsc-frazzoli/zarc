cmake_minimum_required(VERSION 2.8.3)
project(data_logger)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    geometry_msgs
    barc
)

find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)


catkin_package(CATKIN_DEPENDS 
    roscpp
    geometry_msgs
    barc 
)



include_directories(src 
${catkin_INCLUDE_DIRS} 
${Boost_INCLUDE_DIRS} 
${EIGEN3_INCLUDE_DIR})



add_executable(logging_node src/logging_node.cpp)
target_link_libraries(logging_node
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
)

