set(CMAKE_CXX_FLAGS " -g -Wall -Wextra")

enable_testing()

add_executable(TEST_11 Test.cpp solutionOne.cpp solutionTwo.cpp)

target_link_libraries(TEST_11 common)

target_link_libraries(TEST_11 GTest::gtest_main)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_files/ DESTINATION ${CMAKE_BINARY_DIR}/2024/Day11/test_files/)
