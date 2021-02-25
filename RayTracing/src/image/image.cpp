
#include "image.h"

image::Image::Image(int height, int width) : height(height),
                                             width(width)
{
    pixels = new scene::Color[(long long)height * (long long)width];
}

image::Image::~Image()
{}

int image::Image::get_height() const {
    return height;
}

int image::Image::get_width() const {
    return width;
}

Color* image::Image::getPixel(int x, int y) {
    return pixels + (x + (long long)y * (long long)width);
}

Color* image::Image::get_pixels() {
    return pixels;
}

typedef unsigned char uchar;
void image::Image::saveImage(std::string filename, float exposure, float gamma) const
{
    if (width == 0 || height == 0)
    {
        fprintf(stderr, "Can't save an empty image\n");
        return;
    }
    std::ofstream ofs;
    try {
        ofs.open(filename, std::ios::binary);
        if (ofs.fail())
            throw("Can't open output file");
        ofs << "P6\n" << width << " " << height << "\n255\n";
        unsigned char r, g, b;
        for (int i = 0; i < width * height; ++i) {
            pixels[i].applyGammeCorrection(exposure, gamma);
            pixels[i].clamp();
            r = static_cast<uchar>(pixels[i].r);
            g = static_cast<uchar>(pixels[i].g);
            b = static_cast<uchar>(pixels[i].b);
            ofs << r << g << b;
        }
        ofs.close();
    }
    catch (const char* err) {
        fprintf(stderr, "%s\n", err);
        ofs.close();
    }
}

void image::Image::set_pixels(Color* pix) {
    this->pixels = pix;
}
