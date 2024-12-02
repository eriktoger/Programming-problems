cd ../build
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release && cmake --build . --target Main && ./timer/Main.exe