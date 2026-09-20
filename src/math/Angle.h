//
// Created by wexshuq on 16.09.2026.
//

#pragma once
#include <cmath>

#include "math_utils.h"


class Angle {
public:

    float getYaw(const bool radians) const {
        return radians ? radYaw : yaw;
    }
    float getPitch(const bool radians) const {
        return radians ? radPitch : pitch;
    }
    void setMaximumPitch(const float _maximumPitch) {
        maximumPitch = _maximumPitch;
    }

    void setYaw(const float _yaw) {
        yaw = fmodf(_yaw, 360.0f);
        if (yaw < 0.0f) yaw += 360.0f;

        radYaw = Math::ToRadians(yaw);
    }
    void setPitch(const float _pitch) {
        if (_pitch > maximumPitch) {
            pitch = maximumPitch;
        } else if (_pitch < -maximumPitch) {
            pitch = -maximumPitch;
        } else {
            pitch = _pitch;
        }

        radPitch = Math::ToRadians(pitch);
    }
    void add(const float dYaw, const float dPitch) {
        setYaw(yaw + dYaw);
        setPitch(pitch + dPitch);
    }

private:
    float yaw = 0, pitch = 0;
    float maximumPitch = 89.0f;
    float radYaw = Math::ToRadians(yaw), radPitch = Math::ToRadians(pitch);
};
