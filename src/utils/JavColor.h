//
// Created by wexshuq on 20.09.2026.
//

#pragma once


class JavColor {
public:
    float r, g, b, a;
    JavColor();
    JavColor(const float r, const float g, const float b, const float a) : r(r), g(g), b(b), a(a) {}

    void normalize() {
        r = r / 255.0f;
        g = g / 255.0f;
        b = b / 255.0f;
        a = a / 255.0f;
    }
    bool isNormalized() const {
        return a <= 1.0f && b <= 1.0f && r <= 1.0f && g <= 1.0f && a <= 1.0f;
    }

};

