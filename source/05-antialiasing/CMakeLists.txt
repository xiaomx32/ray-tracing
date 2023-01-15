file(GLOB_RECURSE srcs CONFIGURE_DEPENDS include/*.h src/*.cpp)
add_library(antialiasing STATIC ${srcs})
target_include_directories(antialiasing PUBLIC include)