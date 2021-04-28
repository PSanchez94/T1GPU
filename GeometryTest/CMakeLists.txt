cmake_minimum_required(VERSION 3.15)
project(GeometryTest)

set(CMAKE_CXX_STANDARD 11)

set(Sources
        PuntoFloatTest.cpp)

add_subdirectory(googletest)

include_directories(../Geometry/inc)

add_executable(${PROJECT_NAME} ${Sources})
target_link_libraries(${PROJECT_NAME} PUBLIC
        gtest_main
        Geometry)

add_test(
        NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME}
)

