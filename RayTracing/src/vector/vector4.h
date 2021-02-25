#pragma once

#include <cmath>
#include <iostream>

#ifndef RAYTRACER_VECTOR4_H
#define RAYTRACER_VECTOR4_H

namespace vector {
    class Vector4 {
    public:
        /**
         * Constructor for Vector3 without Initialization
         */
        Vector4();

        /**
        * Constructor for Vector4
        * @param x float
        * @param y float
        * @param z float
        * @param w float
        */
        Vector4(float x, float y, float z, float w);

        /**
         * Copy Contructor for Vector4
         * @param vect
         */
        Vector4(const Vector4& vect);

        /**
         * Destructor for Vector4
         */
        ~Vector4();

        /**
         * PrettyPrint a Vector4
         */
        void print() const;

        /**
         * Concise PrettyPrint a Vector4
         */
        void printwo() const;

        /**
         * Getter for x of Vector4
         * @return float x
         */
        float get_x() const;

        /**
         * Getter for y of Vector4
         * @return float y
         */
        float get_y() const;

        /**
         * Getter for z of Vector4
         * @return float z
         */
        float get_z() const;

        /**
         * Getter for w of Vector4
         * @return float w
         */
        float get_w() const;

        /**
         * Setter for Vector4
         * @param x float
         * @param y float
         * @param z float
         * @param w float
         */
        void set(float x, float y, float z, float w);

        /**
         * Setter for Vector4 using another Vector4
         * @param v
         */
        void set(const Vector4& v);

        /**
         * Operator + for adding two Vector4
         * @param v
         * @return Vector4
         */
        Vector4 operator+(const Vector4& v) const;
        /**
         * Operator += for adding fields of a Vector4 by those of another Vector4
         * @param v
         * @return Vector4
         */
        Vector4 operator+=(const Vector4& v);

        /**
         * Operator - for subtracting two Vector4
         * @param v
         * @return Vector4
         */
        Vector4 operator-(const Vector4& v) const;

        /**
         * Operator == for comparing fields of a Vector4 by those of another Vector4
         * @param v
         * @return bool
         */
        bool operator==(const Vector4& v) const;

        /**
         * Operator != for comparing fields of a Vector4 by those of another Vector4
         * @param v
         * @return bool
         */
        bool operator!=(const Vector4& v) const;

        /**
        * Operator - return the negative version of the current vector
        * @return Vector4
        */
        Vector4 operator-() const;

        /**
         * Operator += for subtracting fields of a Vector4 by those of another Vector4
         * @param v
         * @return Vector4
         */
        Vector4 operator-=(const Vector4& v);


        /**
         * Operator * for multiplying Vector3 by a float l
         * @param l
         * @return Vector3
         */
        Vector4 operator*(const float& l) const;

        /**
         * Operator * for multiplying fields of two Vector4
         * @param v
         * @return Vector4
         */
        Vector4 operator*(const Vector4& v) const;

        /**
         * Operator += for multiplying fields of a Vector4 by a given float
         * @param v
         * @return Vector4
         */
        Vector4 operator*=(const float& l);

        /**
         * Operator / for dividing Vector4 by a float l
         * @param l
         * @return Vector4
         */
        Vector4 operator/(const float& l) const;
        /**
        * Operator += for dividing fields of a Vector4 by a given float
        * @param v
        * @return Vector4
        */
        Vector4 operator/=(const float& l);

        /**
         * Returns the Norm of the current vector
         * @return float
         */
        float norm();

        /**
         * Normalizes the current vector
         * @return Vector4
         */
        float normalize();

        /**
         * Returns a Normalized version of the current vector
         * @return Vector4
         */
        Vector4 normalized();

        /**
         * Returns the result of a dot product between two Vector4
         * @param v
         * @return float
         */
        float dot(Vector4& v);

        /**
         * Returns the result of a cross product between two Vector4
         * @param v
         * @return Vector4
         */
        Vector4 cross(Vector4& v);

    private:
        float x_;
        float y_;
        float z_;
        float w_;
    };

    /**
     * Returns the result of a dot product between two Vector4 v1 & v2
     * @param v1
     * @param v2
     * @return
     */
    float dot(Vector4& v1, Vector4& v2);

    /**
     * Returns the result of a cross product between two Vector4 v1 & v2
     * @param v1
     * @param v2
     * @return
     */
    Vector4 cross(Vector4& v1, Vector4& v2);


    std::ostream& operator<<(std::ostream& out, Vector4& vect);
}

#endif //RAYTRACER_VECTOR4_H
