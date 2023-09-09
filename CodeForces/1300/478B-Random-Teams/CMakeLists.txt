find_package(Catch2 3 REQUIRED)
add_executable(TEST main.cpp TEST.cpp)
target_link_libraries(TEST PRIVATE Catch2::Catch2WithMain)
