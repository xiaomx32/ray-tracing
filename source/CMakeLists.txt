cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#if (NOT CMAKE_BUILD_TYPE)
#    set(CMAKE_BUILD_TYPE Release)
#endif()

project(one_weekend LANGUAGES CXX)

add_subdirectory(05-antialiasing)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC antialiasing)