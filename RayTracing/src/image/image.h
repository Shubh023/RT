#pragma once

#include <vector>
#include <fstream>
#include <cstdio>
#include <string>

#include "../color/color.h"

using namespace scene;

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

namespace image {
    class Image {
    public:

        Image(int height, int width);

        ~Image();

        [[nodiscard]] int get_height() const;

        [[nodiscard]] int get_width() const;

        Color* get_pixels();
        void set_pixels(Color* pixels);
        Color* getPixel(int x, int y);

        void saveImage(std::string filename, float exposure = 1.0f, float gamma = 1.0f) const;

    private:
        int height;
        int width;
        Color* pixels;
    };
}

#endif //RAYTRACER_IMAGE_H
