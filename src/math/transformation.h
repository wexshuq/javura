//
// Created by wexshuq on 14.09.2026.
//

#pragma once
#include "matrix4x4.h"
#include "vec3.h"

class Transformation {
public:
    Vec3 pos;
    Vec3 scale{1,1,1};
    Vec3 rot;


    Matrix4x4 getMatrix() const {
        const Matrix4x4 mat = Matrix4x4::CreateTranslation(pos) * Matrix4x4::CreateZRotation(rot.z) * Matrix4x4::CreateYRotation(rot.y) * Matrix4x4::CreateXRotation(rot.x) * Matrix4x4::CreateScale(scale);
        return mat;
    };

};
