year=$1
day=$2

cd build
cmake .. -G "MinGW Makefiles" && cmake --build . --target TEST_$day && ./$year/Day$day/TEST_$day.exe