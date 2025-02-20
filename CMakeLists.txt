cmake_minimum_required(VERSION 3.14)
project(igraphic)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
find_package(system REQUIRED)

# library
add_library(${PROJECT_NAME} STATIC no_source.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC system)

target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_SOURCE_DIR}/window
  ${CMAKE_SOURCE_DIR}/graphic
  ${CMAKE_SOURCE_DIR}/event
  ${CMAKE_SOURCE_DIR}/audio
  ${CMAKE_SOURCE_DIR}
)