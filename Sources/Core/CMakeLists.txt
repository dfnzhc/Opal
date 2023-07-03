project(Core)

file(GLOB CORE_FILES *.hpp *.cpp)

set(CORE_FILES
        Core.hpp
        Core.cpp
        Defines.hpp
        )

add_library(${PROJECT_NAME} ${CORE_FILES})

# Set compiler warnings 
set_project_warnings(${PROJECT_NAME})
add_library(Opal::Core ALIAS ${PROJECT_NAME})