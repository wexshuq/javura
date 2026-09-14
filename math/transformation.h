//
// Created by wexshuq on 14.09.2026.
//

#pragma once
#include "matrix4x4.h"
#include "vec3.h"

class transformation {
public:
    Vec3 pos;
    Vec3 scale{1,1,1};
    Vec3 rot;


    Matrix4x4 getMatrix() const {
        Matrix4x4 mat = Matrix4x4::Identity();

        mat.Scale(scale);
        mat.RotateX(rot.x);
        mat.RotateY(rot.y);
        mat.RotateZ(rot.z);
        mat.Translate(pos);
        return mat;
    };

};
