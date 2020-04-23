# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 3.15.0)

set (CMAKE_CXX_COMPILER "/usr/bin/clang++")


# Set the name and the supported language of the project
project (sim68k CXX C)

set (CMAKE_CXX_FLAGS "--std=gnu++14 -Wc++11-extensions ${CMAKE_CXX_FLAGS}")



# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)



# Add other flags to the compiler
add_definitions(${GTK_CFLAGS_OTHER})


find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


#add_subdirectory(exe)

add_subdirectory(sim68k)
