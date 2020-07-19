cmake_minimum_required(VERSION 3.0)
project(CharScreen)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)

file(GLOB SRC_LIBCHARSCREEN 
  "${PROJECT_SOURCE_DIR}/src/charScreen/*.cpp")

add_library(charScreen SHARED ${SRC_LIBCHARSCREEN} )

file(GLOB SRC_TESTCHARSCREEN
  "${PROJECT_SOURCE_DIR}/src/test/*.cpp")
add_executable(testCharScreen ${SRC_TESTCHARSCREEN})

target_link_libraries(testCharScreen charScreen)

