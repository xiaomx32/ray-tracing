cmake -B build
cmake --build build

@echo off
path = %path%;.\build\Debug\;
vec3class.exe > image.ppm
pause