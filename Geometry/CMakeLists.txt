cmake_minimum_required(VERSION 3.15)
project(Geometry)

set(CMAKE_CXX_STANDARD 11)

set(Headers
        inc/Punto.hpp
        )

include_directories(${PROJECT_SOURCE_DIR}/inc)

add_library(${PROJECT_NAME} SHARED ${Headers})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)