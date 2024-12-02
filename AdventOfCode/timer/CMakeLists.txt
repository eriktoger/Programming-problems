set(CMAKE_CXX_FLAGS "-O3 -march=native -flto -funroll-loops --static")

add_executable(Main main.cpp)
target_link_libraries(Main common)
target_link_libraries(Main Day02Lib) #Day that will be used for timing, you also need to make a library out if that day

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/files DESTINATION ${CMAKE_BINARY_DIR} )