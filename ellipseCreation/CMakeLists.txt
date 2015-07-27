cmake_minimum_required(VERSION 2.8)

project(ellipseCreation)

# Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(ellipseCreation ellipseCreation.cxx)

target_link_libraries(ellipseCreation ${ITK_LIBRARIES})
