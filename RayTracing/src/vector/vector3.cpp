#include "vector3.h"
#include <cstdlib>
#include <stdexcept>

vector::Vector3::~Vector3() {
}

vector::Vector3::Vector3() : x_(0),
y_(0),
z_(0)
{}

vector::Vector3::Vector3(float x, float y, float z) : x_(x),
y_(y),
z_(z)
{}

vector::Vector3::Vector3(const vector::Vector3& vect) : x_(vect.get_x()),
y_(vect.get_y()),
z_(vect.get_z())
{}

void vector::Vector3::print() const {
    std::cout << "{ " << x_ << ", " << y_ << ", " << z_ << " }" << std::endl;
}


void vector::Vector3::printwo() const {
    std::cout << "{" << x_ << "," << y_ << "," << z_ << "}";
}

float vector::Vector3::get_x() const {
    return x_;
}

float vector::Vector3::get_y() const {
    return y_;
}

float vector::Vector3::get_z() const {
    return z_;
}

void vector::Vector3::set(float x, float y, float z) {
    x_ = x;
    y_ = y;
    z_ = z;
}

vector::Vector3 vector::Vector3::operator+(const vector::Vector3& v) const {
    return vector::Vector3(x_ + v.get_x(), y_ + v.get_y(), z_ + v.get_z());
}

vector::Vector3 vector::Vector3::operator-(const vector::Vector3& v) const {
    return vector::Vector3(x_ - v.get_x(), y_ - v.get_y(), z_ - v.get_z());
}

vector::Vector3 vector::Vector3::operator*(const float& l) const {
    return vector::Vector3(x_ * l, y_ * l, z_ * l);
}

vector::Vector3 vector::Vector3::operator/(const float& l) const {
    if (l == 0) {
        std::cerr << "Math error : Division by 0";
        return *this;
    }
    return vector::Vector3(x_ / l, y_ / l, z_ / l);
}

vector::Vector3 vector::Vector3::operator+=(const vector::Vector3& v) {
    this->set(x_ + v.get_x(), y_ + v.get_y(), z_ + v.get_z());
    return *this;
}


vector::Vector3 vector::Vector3::operator-=(const vector::Vector3& v) {
    this->set(x_ - v.get_x(), y_ - v.get_y(), z_ - v.get_z());
    return *this;
}

vector::Vector3 vector::Vector3::operator*=(const float& l) {
    this->set(x_ * l, y_ * l, z_ * l);
    return *this;
}

vector::Vector3 vector::Vector3::operator/=(const float& l) {
    if (l == 0) {
        std::cerr << "Math error : Division by 0";
        return *this;
    }
    this->set(x_ / l, y_ / l, z_ / l);
    return *this;
}

float vector::Vector3::norm() {
    return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

float vector::Vector3::normalize() {
    float norm = this->norm();
    *this /= norm;
    return norm;
}

vector::Vector3 vector::Vector3::normalized() {
    float norm = this->norm();
    return *this / norm;
}

float vector::Vector3::dot(Vector3& v) {
    return x_ * v.get_x() + y_ * v.get_y() + z_ * v.get_z();
}

vector::Vector3 vector::Vector3::cross(Vector3& v) {
    return vector::Vector3(y_ * v.get_z() - z_ * v.get_y(),
        z_ * v.get_x() - x_ * v.get_z(),
        x_ * v.get_y() - y_ * v.get_x());
}

vector::Vector3 vector::Vector3::operator-() const {
    return vector::Vector3(-x_, -y_, -z_);
}

bool vector::Vector3::operator==(const vector::Vector3& v) const {
    bool x = std::abs(x_ - v.get_x()) < 1e-6;
    bool y = std::abs(y_ - v.get_y()) < 1e-6;
    bool z = std::abs(z_ - v.get_z()) < 1e-6;
    return x && y && z;
}

bool vector::Vector3::operator!=(const vector::Vector3& v) const {
    return !(*this == v);
}

void vector::Vector3::set(const vector::Vector3& v) {
    this->set(v.get_x(), v.get_y(), v.get_z());
}

vector::Vector3 vector::Vector3::operator*(const vector::Vector3& v) const {
    return vector::Vector3(x_ * v.get_x(),
        y_ * v.get_y(),
        z_ * v.get_z());
}

float vector::dot(Vector3& v1, Vector3& v2)
{
    return v1.get_x() * v2.get_x() + v1.get_y() * v2.get_y() + v1.get_z() * v2.get_z();
}

vector::Vector3 vector::cross(Vector3& v1, Vector3& v2)
{
    return vector::Vector3(v1.get_y() * v2.get_z() - v1.get_z() * v2.get_y(),
        v1.get_z() * v2.get_x() - v1.get_x() * v2.get_z(),
        v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x());
}

vector::Vector3 vector::cross(const Vector3& v1, const Vector3& v2)
{
    return vector::Vector3(v1.get_y() * v2.get_z() - v1.get_z() * v2.get_y(),
        v1.get_z() * v2.get_x() - v1.get_x() * v2.get_z(),
        v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x());
}

std::ostream& vector::operator<<(std::ostream& out, vector::Vector3& vect) {
    out << vect.get_x() << "," << vect.get_y() << "," << vect.get_z();
    return out;
}
