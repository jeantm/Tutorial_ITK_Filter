cmake_minimum_required(VERSION 2.8)

project(ownFilter)

# Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(ownFilter ownFilter.cpp)

target_link_libraries(ownFilter ${ITK_LIBRARIES})
