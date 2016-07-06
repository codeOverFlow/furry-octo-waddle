cmake_minimum_required(VERSION 3.0)

project(CxxChip)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

find_package(SFML REQUIRED)

file(GLOB_RECURSE sources "src/*.c*")
file(GLOB_RECURSE headers "include/*.h*")

include_directories(${CMAKE_CURREND_SOURCE_DIR}/include)


add_executable(CxxChip ${sources})

# add SFML
target_link_libraries(CxxChip ${SFML_LIBRARY})
