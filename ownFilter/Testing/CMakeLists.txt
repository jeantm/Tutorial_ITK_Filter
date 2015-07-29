cmake_minimum_required(VERSION 2.8)

# Add external data from midas
list(APPEND ExternalData_URL_TEMPLATES
"http://slicer.kitware.com/midas3/api/rest?method=midas.bitstream.download&checksum=%(hash)"
)

# Set source directory (where the images are)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data)
set(TEMP_DIR ${CMAKE_BINARY_DIR}/Testing/Temporary )

# Set the images used for the tests
set(referenceYinYang DATA{${SOURCE_DIR}/reverseYinYang.png})
set(Input DATA{${SOURCE_DIR}/basicYinYang.png})
set(ResultYinYang ${TEMP_DIR}/testYinYang.png)

include_directories(${CMAKE_SOURCE_DIR})

# Add the executable for the tests and linked the != libraries needed
add_executable(ownFilterTests ownFilterTests.cxx)
target_link_libraries(ownFilterTests ${ITK_LIBRARIES})
target_link_libraries(ownFilterTests multiThreadedOwnFilterLib)

# Test checking that the program cannot run without arguments
ExternalData_add_test(
        MY_DATA
        NAME OpenFileTest
        COMMAND $<TARGET_FILE:multiThreadedOwnFilter>)
set_tests_properties(OpenFileTest PROPERTIES WILL_FAIL true )

#Test checking that a wrong input will prevent the program from running
ExternalData_add_test(
        MY_DATA
        NAME WrongInputFileName
        COMMAND $<TARGET_FILE:multiThreadedOwnFilter>
    WrongInput1.png
    WrongOutput.png
)
set_tests_properties( WrongInputFileName PROPERTIES WILL_FAIL true )
set_tests_properties(
WrongInputFileName PROPERTIES
PASS_REGULAR_EXPRESSION
"Exception"
)

# Tests checking that the output image is what we expect
ExternalData_add_test(
        MY_DATA
        NAME multiThreadedOwnFilterOK
        COMMAND $<TARGET_FILE:ownFilterTests>
    --compare
        ${referenceYinYang}
        ${ResultYinYang}
    ModuleEntryPoint
        ${Input}
        ${ResultYinYang}
)

# Test for the command --help
add_test(NAME PrintHelp COMMAND $<TARGET_FILE:multiThreadedOwnFilter> --help)

ExternalData_Add_Target(MY_DATA)
