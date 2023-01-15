cmake -S source -B ./build
cmake --build build

cd %~dp0build\Debug
main.exe > ..\..\image\05-antialiasing.ppm
pause