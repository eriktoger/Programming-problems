set(CMAKE_CXX_FLAGS " -g -Wall -Wextra")

enable_testing()

add_executable(TEST_05 Test.cpp solutionOne.cpp solutionTwo.cpp utils.cpp)

target_link_libraries(TEST_05 common)

target_link_libraries(TEST_05 GTest::gtest_main)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_files/ DESTINATION ${CMAKE_BINARY_DIR}/2024/Day05/test_files/)
