project(Grundlagen_Cpp)
cmake_minimum_required(VERSION 2.8)
set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  )
add_subdirectory("${PROJECT_SOURCE_DIR}/common")
add_subdirectory("${PROJECT_SOURCE_DIR}/Task1")
add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})

