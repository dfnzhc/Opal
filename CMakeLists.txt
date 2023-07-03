cmake_minimum_required(VERSION 3.26)

#################################################################
# Project details
project(Opal
        VERSION 0.0.1
        DESCRIPTION ""
        LANGUAGES CXX
        )

#################################################################
# Setup alternative names
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWERCASE)
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)

#################################################################
# Set project options
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

set(PROJECT_WORK_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_DATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Data)

#################################################################
# add the path of local cmake scripts
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake)

include(CMake/CommonSettings.cmake)
include(CMake/CompilerWarnings.cmake)

# set project configure
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CMake/Config.hpp.in ${PROJECT_NAME}Config.hpp @ONLY)

set(${PROJECT_NAME}_BUILD_SAMPLES ON CACHE BOOL "Enable generation and building of samples.")
set(${PROJECT_NAME}_BUILD_TESTS ON CACHE BOOL "Enable generation and building of tests.")

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
)

#################################################################
# Third-party support libraries.
add_subdirectory(External)

#################################################################
# Add sources
add_subdirectory(Sources)

#########################################################
# Samples
#if (${PROJECT_NAME}_BUILD_SAMPLES)
#    add_subdirectory(Samples)
#endif ()

#########################################################
# Tests
if (${PROJECT_NAME}_BUILD_TESTS)
    enable_testing()
    add_subdirectory(Tests)
endif ()

#################################################################
# Now that everything is done, indicate that we have finished configuring at least once.
# We use this variable to set certain defaults only on the first pass, so that we don't
# continually set them over and over again.
set(PASSED_FIRST_CONFIGURE ON CACHE INTERNAL "Already Configured once?")