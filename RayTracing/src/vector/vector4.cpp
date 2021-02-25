#include "vector4.h"
#include <stdexcept>

vector::Vector4::~Vector4() {
}

vector::Vector4::Vector4() : x_(0),
y_(0),
z_(0),
w_(0)
{}

vector::Vector4::Vector4(float x, float y, float z, float w) : x_(x),
y_(y),
z_(z),
w_(w)
{}

vector::Vector4::Vector4(const vector::Vector4& vect) : x_(vect.get_x()),
y_(vect.get_y()),
z_(vect.get_z()),
w_(vect.get_w())
{}

void vector::Vector4::print() const {
    std::cout << "{ " << x_ << ", " << y_ << ", " << z_ << ", " << w_ << " }" << std::endl;
}

void vector::Vector4::printwo() const {
    std::cout << "{" << x_ << "," << y_ << "," << z_ << "," << w_ << "}";
}


float vector::Vector4::get_x() const {
    return x_;
}

float vector::Vector4::get_y() const {
    return y_;
}

float vector::Vector4::get_z() const {
    return z_;
}

float vector::Vector4::get_w() const {
    return w_;
}


void vector::Vector4::set(float x, float y, float z, float w) {
    x_ = x;
    y_ = y;
    z_ = z;
    w_ = w;
}

vector::Vector4 vector::Vector4::operator+(const vector::Vector4& v) const {
    return vector::Vector4(x_ + v.get_x(), y_ + v.get_y(), z_ + v.get_z(), w_ + v.get_w());
}


vector::Vector4 vector::Vector4::operator-(const vector::Vector4& v) const {
    return vector::Vector4(x_ - v.get_x(), y_ - v.get_y(), z_ - v.get_z(), w_ - v.get_w());
}

vector::Vector4 vector::Vector4::operator*(const float& l) const {
    return vector::Vector4(x_ * l, y_ * l, z_ * l, w_ * l);
}

vector::Vector4 vector::Vector4::operator/(const float& l) const {
    if (l == 0) {
        std::cerr << "Math error : Division by 0";
        return *this;
    }
    return vector::Vector4(x_ / l, y_ / l, z_ / l, w_ / l);
}

vector::Vector4 vector::Vector4::operator+=(const vector::Vector4& v) {
    this->set(x_ + v.get_x(), y_ + v.get_y(), z_ + v.get_z(), w_ + v.get_w());
    return *this;
}


vector::Vector4 vector::Vector4::operator-=(const vector::Vector4& v) {
    this->set(x_ - v.get_x(), y_ - v.get_y(), z_ - v.get_z(), w_ - v.get_w());
    return *this;
}

vector::Vector4 vector::Vector4::operator*=(const float& l) {
    this->set(x_ * l, y_ * l, z_ * l, w_ * l);
    return *this;
}

vector::Vector4 vector::Vector4::operator/=(const float& l) {
    if (l == 0) {
        std::cerr << "Math error : Division by 0";
        return *this;
    }
    this->set(x_ / l, y_ / l, z_ / l, w_ / l);
    return *this;
}

float vector::Vector4::norm() {
    //return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_);
    return std::sqrt(this->dot(*this));
}

float vector::Vector4::normalize() {
    float norm = this->norm();
    *this /= norm;
    return norm;
}

vector::Vector4 vector::Vector4::normalized() {
    float norm = this->norm();
    return *this / norm;
}

float vector::Vector4::dot(Vector4& v) {
    return x_ * v.get_x() + y_ * v.get_y() +
        z_ * v.get_z() + w_ * v.get_w();
}

vector::Vector4 vector::Vector4::cross(vector::Vector4& v) {
    return vector::Vector4(
        x_ * v.get_x() - y_ * v.get_y() - z_ * v.get_z() - w_ * v.get_w(),
        y_ * v.get_x() + x_ * v.get_y() - w_ * v.get_z() + z_ * v.get_w(),
        z_ * v.get_x() + w_ * v.get_y() + x_ * v.get_z() - y_ * v.get_w(),
        w_ * v.get_x() - z_ * v.get_y() + y_ * v.get_z() + x_ * v.get_w());
}

vector::Vector4 vector::Vector4::operator-() const {
    return vector::Vector4(-x_, -y_, -z_, -w_);
}

bool vector::Vector4::operator==(const vector::Vector4& v) const {
    bool x = std::abs(x_ - v.get_x()) < 1e-6;
    bool y = std::abs(y_ - v.get_y()) < 1e-6;
    bool z = std::abs(z_ - v.get_z()) < 1e-6;
    bool w = std::abs(w_ - v.get_w()) < 1e-6;
    return x && y && z && w;
}

bool vector::Vector4::operator!=(const vector::Vector4& v) const {
    return !(*this == v);
}

void vector::Vector4::set(const Vector4& v) {
    this->set(v.get_x(), v.get_y(), v.get_z(), v.get_w());
}

vector::Vector4 vector::Vector4::operator*(const vector::Vector4& v) const {
    return vector::Vector4(x_ * v.get_x(),
        y_ * v.get_y(),
        z_ * v.get_z(),
        w_ * v.get_w());
}

float vector::dot(Vector4& v1, Vector4& v2)
{
    return v1.get_x() * v2.get_x() +
        v1.get_y() * v2.get_y() +
        v1.get_z() * v2.get_z() +
        v1.get_w() * v2.get_w();
}

vector::Vector4 vector::cross(vector::Vector4& v1, vector::Vector4& v2)
{
    return vector::Vector4(
        v1.get_x() * v2.get_x() - v1.get_y() * v2.get_y() - v1.get_z() * v2.get_z() - v1.get_w() * v2.get_w(),
        v1.get_y() * v2.get_x() + v1.get_x() * v2.get_y() - v1.get_w() * v2.get_z() + v1.get_z() * v2.get_w(),
        v1.get_z() * v2.get_x() + v1.get_w() * v2.get_y() + v1.get_x() * v2.get_z() - v1.get_y() * v2.get_w(),
        v1.get_w() * v2.get_x() - v1.get_z() * v2.get_y() + v1.get_y() * v2.get_z() + v1.get_x() * v2.get_w()
    );
}

std::ostream& vector::operator<<(std::ostream& out, vector::Vector4& vect) {
    out << vect.get_x() << "," << vect.get_y() << "," << vect.get_z() << "," << vect.get_w();
    return out;
}
