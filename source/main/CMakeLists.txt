file(GLOB_RECURSE srcs CONFIGURE_DEPENDS include/*.h src/*.cpp)
add_library(weekend STATIC ${srcs})
target_include_directories(weekend PUBLIC include)