cmake_minimum_required(VERSION 4.1)
project(javura)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

add_executable(javura src/main.cpp
        src/engine/engine.cpp
        src/engine/engine.h
        src/math/Vec3.h
        src/engine/camera.cpp
        src/engine/camera.h
        src/utils/raysync.h
        src/math/matrix4x4.h
        src/math/math_utils.h
        "src/math/Transformation.h"
        src/map/world.cpp
        src/map/world.h
        src/math/Angle.h
        src/entity/entity.h
        src/entity/impl/player.cpp
        src/entity/impl/player.h
        src/engine/input_controller.cpp
        src/engine/input_controller.h
        src/math/vec2.h
        src/entity/impl/controller/player_controller.cpp
        src/entity/impl/controller/player_controller.h
        src/renderer/renderer.cpp
        src/renderer/renderer.h
        src/renderer/render_exception.h
        src/utils/JavColor.h
)

target_link_libraries(javura PRIVATE raylib)