# ----------- general -----------

cmake_minimum_required(VERSION 3.14)
project(igraphic)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------- project -----------

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(imodule REQUIRED)
find_package(system REQUIRED)

set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/sources/no_source.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC imodule system)


# ----------- include -----------

target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/includes
  ${CMAKE_CURRENT_SOURCE_DIR}/includes/window
  ${CMAKE_CURRENT_SOURCE_DIR}/includes/graphic
  ${CMAKE_CURRENT_SOURCE_DIR}/includes/event
  ${CMAKE_CURRENT_SOURCE_DIR}/includes/audio
)

#----------- dev -----------

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)

#----------- test -----------

find_package(GoogleTest REQUIRED)

enable_testing()

file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)

add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})

target_include_directories(${PROJECT_NAME}_tests PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/tests/includes
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/includes/window
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/includes/graphic
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/includes/event
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/includes/audio
)

target_link_libraries(${PROJECT_NAME}_tests 
	gtest_main
	${PROJECT_NAME}
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)