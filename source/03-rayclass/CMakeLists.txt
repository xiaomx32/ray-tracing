file(GLOB_RECURSE srcs CONFIGURE_DEPENDS include/*.h src/*.cpp)
add_library(rayclass STATIC ${srcs})
target_include_directories(rayclass PUBLIC include)