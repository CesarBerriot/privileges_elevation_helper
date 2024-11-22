cmake_minimum_required(VERSION 3.29)
project(privileges_elevation_helper C)

include(FetchContent)

FetchContent_Declare(
        hard_assert
        GIT_REPOSITORY https://github.com/CesarBerriot/hard_assert.git
        GIT_TAG master
)
FetchContent_MakeAvailable(hard_assert)


add_library(privileges_elevation_helper STATIC privileges_elevation_helper.c)
target_include_directories(privileges_elevation_helper PUBLIC include)
target_compile_options(privileges_elevation_helper PRIVATE -ansi -pedantic-errors -std=c11 -Wall -Wextra)
target_link_libraries(privileges_elevation_helper PRIVATE hard_assert)