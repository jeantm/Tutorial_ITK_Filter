cmake_minimum_required(VERSION 2.8)

project(multiThreadedOwnFilter)

# Find SlicerExecutionModel
find_package(SlicerExecutionModel REQUIRED)
include(${SlicerExecutionModel_USE_FILE})
include(${GenerateCLP_USE_FILE})

# Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

set(multiThreadedOwnFilter_Source multiThreadedOwnFilter.cxx)


SEMMacroBuildCLI(
    NAME multiThreadedOwnFilter
    EXECUTABLE_ONLY
    TARGET_LIBRARIES ${ITK_LIBRARIES}
)

if (BUILD_TESTING)
    add_subdirectory(Testing)
endif ()
