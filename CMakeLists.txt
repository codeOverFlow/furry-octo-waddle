cmake_minimum_required(VERSION 3.0)
project(CxxChip)
file(GLOB_RECURSE sources "src/*.c*")
file(GLOB_RECURSE headers "include/*.h*")
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
include_directories(${CMAKE_CURREND_SOURCE_DIR}/include)

# add a lib
# set (LLIB_LIB libllib.so)
# link_directories(path/to/lib)
# include_directories(path/to/headers)
add_executable(CxxChip ${sources})
# target_lin_libraries(exe ${LLIB_LIB})
