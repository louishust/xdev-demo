project(XDEV-DEMO)

cmake_minimum_required(VERSION 3.0.2)

add_subdirectory(third_party/mysql-connector-cpp)
include_directories(third_party/mysql-connector-cpp/include)

add_executable(demo demo.cc)
target_link_libraries(demo connector)

#add_executable(async async.cc)
#target_link_libraries(async connector)
