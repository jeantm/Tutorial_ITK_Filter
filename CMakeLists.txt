cmake_minimum_required(VERSION 2.8)

project(projectFilter)

option(ellipseCreation "ellipseCreation executable" ON)
option(meanFilter "meanFilter executable" ON)
option(medianFilter "medianFilter executable" ON)
option(multiThreadedOwnFilter "multiThreadedOwnFilter executable" ON)


if (ellipseCreation)
    add_subdirectory(ellipseCreation)
endif ()

if (meanFilter)
    add_subdirectory(meanFilter)
endif ()

if (medianFilter)
    add_subdirectory(medianFilter)
endif ()

if (multiThreadedOwnFilter)
    add_subdirectory(ownFilter)
endif ()
