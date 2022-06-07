cmake_minimum_required(VERSION 3.21)
project(vec3class LANGUAGES CXX)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp src/*.h)
add_executable(vec3class ${sources} ${headfiles})