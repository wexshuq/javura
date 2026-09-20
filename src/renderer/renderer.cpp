//
// Created by wexshuq on 19.09.2026.
//

#include "renderer.h"
#include <raylib.h>
#include "../utils/raysync.h"

#include "render_exception.h"


void Renderer::BeginRender() {
    BeginDrawing();
    renderEnabled = true;
}

void Renderer::EndRender() {
    EndDrawing();
    renderEnabled = false;
    if (render3DMode) render3DMode = false;
}


void Renderer::BeginRender3D(const MainCamera &camera) {
    if (!renderEnabled) {
        throw RenderException("Failed to enable 3D mode because drawing mode is disabled.");
    }
    if (render3DMode) return;
    BeginMode3D(camera.GetRayCamera());
    render3DMode = true;

}

void Renderer::EndRender3D() {
    if (!renderEnabled) {
        throw RenderException("Failed to disable 3D mode because drawing mode is disabled.");
    }
    if (!render3DMode) return;
    EndMode3D();
    render3DMode = false;
}

void Renderer::DrawCube3D(const Vec3& position, const Vec3& size, const JavColor& color) {
    if (!render3DMode) throw RenderException("Unable to draw the cube because 3D mode is disabled.");


    const float x = position.x;
    const float y = position.y;
    const float z = position.z;

    const float width = size.x;
    const float height = size.y;
    const float length = size.z;

    const Color ray_color = RaySync::ToRay(color,color.isNormalized());

    DrawCube({x,y,z},width,height,length, ray_color);

}

void Renderer::DrawCube3D(const JavColor& color) {
    if (!render3DMode) throw RenderException("Unable to draw the cube because 3D mode is disabled.");

    const Color ray_color = RaySync::ToRay(color,color.isNormalized());

    DrawCube({0,0,0},1,1,1, ray_color);
}

void Renderer::DrawCube3DWires(const Vec3& position, const Vec3& size, const JavColor& color) {
    if (!render3DMode) throw RenderException("Unable to draw the cube wires because 3D mode is disabled.");

    const float x = position.x;
    const float y = position.y;
    const float z = position.z;

    const float width = size.x;
    const float height = size.y;
    const float length = size.z;

    const Color ray_color = RaySync::ToRay(color,color.isNormalized());

    DrawCubeWires({x,y,z},width,height,length, ray_color);
}

void Renderer::DrawCube3DWires(const JavColor& color) {
    if (!render3DMode) throw RenderException("Unable to draw the cube wires because 3D mode is disabled.");
    const Color ray_color = RaySync::ToRay(color,color.isNormalized());

    DrawCubeWires({0,0,0},1,1,1, ray_color);
}

void Renderer::DrawRectangle(const Vec2& position, const Vec2& size, float radius, const JavColor& color) {
    if (render3DMode) {
        throw RenderException("Unable to draw the rectangle because 3D mode is enabled.");
    }
}

void Renderer::DrawRectangle(const Vec2& position, const Vec2& size, const JavColor& color) {
    if (render3DMode) {
        throw RenderException("Unable to draw the rectangle because 3D mode is enabled.");
    }
}
