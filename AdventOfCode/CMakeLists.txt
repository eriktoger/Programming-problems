cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0135 NEW)
project(AdventOfCode)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b10fad38c4026a29ea6561ab15fc4818170d1c10.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(common)
add_subdirectory(timer)

add_subdirectory("2024/Day01")
add_subdirectory("2024/Day02")

add_subdirectory("2024/Day03")

add_subdirectory("2024/Day04")
