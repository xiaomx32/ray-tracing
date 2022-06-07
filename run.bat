cmake -B build
cmake --build build

@echo off
path = %path%;.\build\Debug\;
rayclass.exe > image.ppm
pause