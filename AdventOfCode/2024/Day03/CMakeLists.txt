set(CMAKE_CXX_FLAGS " -g")

enable_testing()

add_executable(TEST_03 Test.cpp solutionOne.cpp solutionTwo.cpp utils.cpp)

target_link_libraries(TEST_03 common)

target_link_libraries(TEST_03 GTest::gtest_main)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_files/ DESTINATION ${CMAKE_BINARY_DIR}/2024/Day03/test_files/)
