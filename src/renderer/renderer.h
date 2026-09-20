//
// Created by wexshuq on 19.09.2026.
//

#pragma once
#include "../engine/camera.h"
#include "../math/vec3.h"
#include "../utils/JavColor.h"


class Renderer {

public:
    static void BeginRender();
    static void EndRender();

    static void BeginRender3D(const MainCamera& camera);

    static void EndRender3D();

    static void DrawCube3D(const Vec3& position, const Vec3& size, const JavColor& color);
    // if matrix transformation.
    static void DrawCube3D(const JavColor& color);
    static void DrawCube3DWires(const Vec3& position, const Vec3& size, const JavColor& color);
    static void DrawCube3DWires(const JavColor& color);

    static void DrawRectangle(const Vec2& position,const Vec2&,float radius,const JavColor& color);
    static void DrawRectangle(const Vec2& position,const Vec2& size,const JavColor& color);


private:
    inline static bool renderEnabled = false;
    inline static bool render3DMode = false;
};
