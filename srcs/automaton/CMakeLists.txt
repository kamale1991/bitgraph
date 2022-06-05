cmake_minimum_required(VERSION 3.16.0)
get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB_RECURSE srcs *.cpp)

add_library(${DIR_NAME} STATIC ${srcs})
set_target_properties(${DIR_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
target_include_directories(${DIR_NAME} PUBLIC include)

