cmake_minimum_required(VERSION 2.8)

project(meanFilter)

# Find SlicerExecutionModel
find_package(SlicerExecutionModel REQUIRED)
include(${SlicerExecutionModel_USE_FILE})
include(${GenerateCLP_USE_FILE})

# Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

set(meanFilter_Source meanFilter.cxx)

SEMMacroBuildCLI(
    NAME meanFilter
    EXECUTABLE_ONLY
    TARGET_LIBRARIES ${ITK_LIBRARIES}
)
