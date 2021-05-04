cmake_minimum_required(VERSION 3.19)
project(T1GPU)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_subdirectory(Geometry)
add_subdirectory(GeometryTest)

include_directories( ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/Geometry/inc
        )

add_executable(T1GPU main.cpp)

target_link_libraries(T1GPU Geometry)