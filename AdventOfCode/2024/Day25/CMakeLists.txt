set(CMAKE_CXX_FLAGS " -g -Wall -Wextra")

enable_testing()

add_executable(TEST_25 Test.cpp solutionOne.cpp solutionTwo.cpp)

target_link_libraries(TEST_25 common)

target_link_libraries(TEST_25 GTest::gtest_main)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_files/ DESTINATION ${CMAKE_BINARY_DIR}/2024/Day25/test_files/)
