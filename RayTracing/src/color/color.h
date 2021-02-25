#pragma once

#ifndef RAYTRACER_COLOR_HH
#define RAYTRACER_COLOR_HH

#include "../vector/vector3.h"

namespace scene {
    class Color : vector::Vector3 {
    public:
        Color();

        Color(float gray);

        Color(float r, float g, float b);

        Color(vector::Vector3& v);

        Color(Color& c);

        ~Color();

        void clamp(float min = 0.0f, float max = 1.0f);

        void applyGammeCorrection(float exposure, float gamme);

        Color& operator=(const Color& c);

        Color& operator+=(const Color& c);

        Color& operator*=(float l);

        Color& operator*=(const Color& c);

        Color operator*(const Color& c);

        bool operator==(const Color& c);
        bool operator!=(const Color& c);

        float r;
        float g;
        float b;
        vector::Vector3 RGB;
    };
}

#endif //RAYTRACER_COLOR_HH
