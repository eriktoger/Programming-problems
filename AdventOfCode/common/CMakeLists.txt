set(CMAKE_CXX_FLAGS " -g")
add_library(common common.cpp)
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})