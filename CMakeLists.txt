cmake_minimum_required(VERSION 4.1)
project(untitled)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

add_executable(untitled main.cpp
        engine/engine.cpp
        engine/engine.h
        math/Vec3.h
        renderer/camera.cpp
        renderer/camera.h
        engine/raysync.h
        math/matrix4x4.h)

target_link_libraries(untitled PRIVATE raylib)