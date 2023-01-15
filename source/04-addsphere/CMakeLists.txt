file(GLOB_RECURSE srcs CONFIGURE_DEPENDS include/*.h src/*.cpp)
add_library(addsphere STATIC ${srcs})
target_include_directories(addsphere PUBLIC include)