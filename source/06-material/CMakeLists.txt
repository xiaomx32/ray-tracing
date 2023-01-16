file(GLOB_RECURSE srcs CONFIGURE_DEPENDS include/*.h src/*.cpp)
add_library(material STATIC ${srcs})
target_include_directories(material PUBLIC include)