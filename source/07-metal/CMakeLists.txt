file(GLOB_RECURSE srcs CONFIGURE_DEPENDS include/*.h src/*.cpp)
add_library(metal STATIC ${srcs})
target_include_directories(metal PUBLIC include)