#include <cmath>

#include "color.h"

using namespace scene;

Color::Color() : r(0),
g(0),
b(0),
RGB(r, g, b)
{}

Color::Color(float r, float g, float b) : r(r),
g(g),
b(b),
RGB(r, g, b)
{}

Color::Color(float gray) : r(0 * gray),
g(0 * gray),
b(0 * gray),
RGB(r, g, b)
{}

Color::Color(vector::Vector3& v) : r(v.get_x()),
g(v.get_y()),
b(v.get_z()),
RGB(r, g, b)
{}

Color::Color(Color& c) : vector::Vector3(c),
r(c.r),
g(c.g),
b(c.b),
RGB(r, g, b)
{}

Color::~Color()
{}

void Color::clamp(float min, float max)
{
    RGB.set(std::max(min, std::min(max, r)),
        std::max(min, std::min(max, g)),
        std::max(min, std::min(max, b)));
}

void Color::applyGammeCorrection(float exposure, float gamma)
{
    RGB.set(std::pow(r * exposure, gamma),
        std::pow(g * exposure, gamma),
        std::pow(b * exposure, gamma));
}

Color& Color::operator=(const Color& c) {
    r = c.r;
    g = c.g;
    b = c.b;
    this->RGB.set(r, g, b);
    return *this;
}

Color& Color::operator+=(const Color& c) {
    this->RGB += c.RGB;
    r = RGB.get_x();
    g = RGB.get_y();
    b = RGB.get_z();
    return *this;
}

Color& Color::operator*=(float l) {
    this->RGB *= l;
    r = RGB.get_x();
    g = RGB.get_y();
    b = RGB.get_z();
    return *this;
}

Color& Color::operator*=(const Color& c) {
    r *= c.r;
    g *= c.g;
    b *= c.b;
    RGB.set(r, g, b);
    return *this;
}

Color Color::operator*(const Color& c) {
    return Color(r * c.r, g * c.g, b * c.b);
}

bool Color::operator==(const Color& c) {
    return r == c.r && g == c.g && b == c.b;
}

bool Color::operator!=(const Color& c) {
    return !(*this == c);
}