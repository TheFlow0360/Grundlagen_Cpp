project(Grundlagen_Cpp)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wpedantic -Wall -Werror")
set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
add_subdirectory("${PROJECT_SOURCE_DIR}/common")
add_subdirectory("${PROJECT_SOURCE_DIR}/Task1")
add_subdirectory("${PROJECT_SOURCE_DIR}/Task2")
add_subdirectory("${PROJECT_SOURCE_DIR}/Task3")
add_subdirectory("${PROJECT_SOURCE_DIR}/Task4")
add_subdirectory("${PROJECT_SOURCE_DIR}/Task5")
add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})

