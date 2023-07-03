cmake_minimum_required(VERSION 3.26)

project(${PROJECT_NAME}Test LANGUAGES CXX)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
find_package(GTest CONFIG REQUIRED)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#add_compile_definitions($<$<CONFIG:Debug>:_ITERATOR_DEBUG_LEVEL=2>)

# These examples use the standard separate compilation
set(TEST_SOURCES
        CommonTest.cpp
        )

string(REPLACE ".cpp" "" TEST_NAMES "${TEST_SOURCES}")
set(TEST_TARGET_NAMES ${TEST_NAMES})

set(${CMAKE_CURRENT_BINARY_DIR})
message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

foreach (NAME ${TEST_TARGET_NAMES})
    add_executable(${NAME} ${NAME}.cpp)
    set_property(TARGET ${NAME} PROPERTY FOLDER "Tests")

    target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Sources)
    target_link_libraries(${NAME} PUBLIC GTest::gtest GTest::gtest_main Opal::Core)
    set_property(TARGET ${NAME} PROPERTY CXX_STANDARD 23)

    add_test(NAME "${NAME}Test" COMMAND ${NAME}
            WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endforeach ()
