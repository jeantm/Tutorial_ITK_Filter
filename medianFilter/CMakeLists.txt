cmake_minimum_required(VERSION 2.8)

project(medianFilter)

# Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(medianFilter medianFilter.cxx)

target_link_libraries(medianFilter ${ITK_LIBRARIES})
