set(CMAKE_CXX_FLAGS " -g -Wall -Wextra")

enable_testing()

add_executable(TEST_06 Test.cpp solutionOne.cpp solutionTwo.cpp)

target_link_libraries(TEST_06 common)

target_link_libraries(TEST_06 GTest::gtest_main)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_files/ DESTINATION ${CMAKE_BINARY_DIR}/2024/Day06/test_files/)
