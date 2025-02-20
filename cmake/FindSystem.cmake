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