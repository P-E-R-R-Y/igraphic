cmake_minimum_required(VERSION 3.14)
project(igraphic)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch igraphic (only if not already provided)
include(FetchContent)
# Check if it's already fetched
FetchContent_GetProperties(system)
if (NOT system_POPULATED)
  # If not, fetch it
  FetchContent_Declare(
    system
    GIT_REPOSITORY https://github.com/P-E-R-R-Y/system.git
    GIT_TAG main #v0.1.0
  )
  FetchContent_MakeAvailable(system)
endif()

FetchContent_GetProperties(maths)
if (NOT maths_POPULATED)
  # If not, fetch it
  FetchContent_Declare(
    maths
    GIT_REPOSITORY https://github.com/P-E-R-R-Y/maths.git
    GIT_TAG main #v0.1.0
  )
  FetchContent_MakeAvailable(maths)
endif()

add_library(${PROJECT_NAME} STATIC no_source.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC system math)

target_include_directories(${PROJECT_NAME} PUBLIC
  window
  graphic
  audio
  event
  .
)