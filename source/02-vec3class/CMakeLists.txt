file(GLOB_RECURSE srcs CONFIGURE_DEPENDS include/*.h src/*.cpp)
add_library(vec3class STATIC ${srcs})
target_include_directories(vec3class PUBLIC include)