cmake_minimum_required(VERSION 3.8.2)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
project(timetable)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (CMAKE_CXX_STANDARD 11)
set(CXX_FLAGS "-Wall -O3")

# Includes directory
set(INC_DIR ${PROJECT_SOURCE_DIR}/includes)
include_directories(${INC_DIR})

# Sources directories
add_subdirectory(src)
