cmake_minimum_required(VERSION 3.0.2)
project(boost_sample)

find_package(catkin REQUIRED)

## (ref) https://stackoverflow.com/questions/56575376/cmake-with-boost-thread-library
find_package(Boost REQUIRED COMPONENTS thread) ## add

catkin_package(
)

include_directories(
# include
# ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS} ## add 
)

message(${Boost_VERSION_STRING}) ## add

add_executable(thread_sample src/thread_sample.cpp)
target_link_libraries(thread_sample
  Boost::thread ## add 
)
