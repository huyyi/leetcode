cmake_minimum_required(VERSION 3.20)
project(Leetcode)
set(CMAKE_CXX_STANDARD 17)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

file(GLOB_RECURSE files "${CMAKE_CURRENT_SOURCE_DIR}/acwing/*.cpp")
file(GLOB_RECURSE files "${CMAKE_CURRENT_SOURCE_DIR}/leetcode/editor/*.cpp")

foreach(file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
endforeach()
add_executable(findRange acmModeIn/findRange.cpp)