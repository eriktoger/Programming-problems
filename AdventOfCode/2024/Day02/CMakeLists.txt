set(CMAKE_CXX_FLAGS " -g")

enable_testing()

add_executable(TEST_02 TEST.cpp solutionOne.cpp solutionTwo.cpp utils.cpp)

target_link_libraries(TEST_02 common)

target_link_libraries(TEST_02 GTest::gtest_main)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_files/ DESTINATION ${CMAKE_BINARY_DIR}/2024/Day02/test_files/)

## Enable timer to access the code
add_library(Day02Lib solutionTwo.cpp utils.cpp)
target_include_directories(Day02Lib PUBLIC ${CMAKE_SOURCE_DIR}/common)