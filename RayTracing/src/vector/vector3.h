#pragma once

#include <cmath>
#include <iostream>

#ifndef RAYTRACER_VECTOR3_H
#define RAYTRACER_VECTOR3_H

namespace vector {
    class Vector3 {
    public:
        /**
         * Constructor for Vector3 without Initialization
         */
        Vector3();

        /**
         * Constructor for Vector3
         * @param x float
         * @param y float
         * @param z float
         */
        Vector3(float x, float y, float z);

        /**
         * Copy Contructor for Vector3
         * @param vect
         */
        Vector3(const Vector3& vect);

        /**
         * Destructor for Vector3
         */
        ~Vector3();

        /**
         * PrettyPrint a Vector3
         */
        void print() const;

        /**
         * Concise PrettyPrint a Vector3
         */
        void printwo() const;

        /**
         * Getter for x of Vector3
         * @return float x
         */
        float get_x() const;

        /**
         * Getter for y of Vector3
         * @return float y
         */
        float get_y() const;

        /**
         * Getter for z of Vector3
         * @return float z
         */
        float get_z() const;

        /**
         * Setter for Vector3
         * @param x float
         * @param y float
         * @param z float
         */
        void set(float x, float y, float z);

        /**
         * Setter for Vector3 using another Vector3
         * @param v
         */
        void set(const Vector3& v);

        /**
         * Operator + for adding two Vector3
         * @param v
         * @return Vector3
         */
        Vector3 operator+(const Vector3& v) const;
        /**
         * Operator += for adding fields of a Vector3 by those of another Vector3
         * @param v
         * @return Vector3
         */

        Vector3 operator+=(const Vector3& v);

        /**
         * Operator - for subtracting two Vector3
         * @param v
         * @return Vector3
         */
        Vector3 operator-(const Vector3& v) const;

        /**
         * Operator - return the negative version of the current vector
         * @return Vector3
         */
        Vector3 operator -() const;

        /**
         * Operator == for comparing fields of a Vector3 by those of another Vector3
         * @param v
         * @return bool
         */
        bool operator==(const Vector3& v) const;

        /**
         * Operator != for comparing fields of a Vector3 by those of another Vector3
         * @param v
         * @return bool
         */
        bool operator!=(const Vector3& v) const;

        /**
         * Operator += for subtracting fields of a Vector3 by those of another Vector3
         * @param v
         * @return Vector3
         */
        Vector3 operator-=(const Vector3& v);

        /**
         * Operator * for multiplying Vector3 by a float l
         * @param l
         * @return Vector3
         */
        Vector3 operator*(const float& l) const;

        /**
         * Operator * for multiplying fields of two Vector3
         * @param v
         * @return Vector3
         */
        Vector3 operator*(const Vector3& v) const;

        /**
         * Operator += for multiplying fields of a Vector3 by a given float
         * @param v
         * @return Vector3
         */
        Vector3 operator*=(const float& l);

        /**
         * Operator / for dividing Vector3 by a float l
         * @param l
         * @return Vector3
         */
        Vector3 operator/(const float& l) const;

        /**
        * Operator += for dividing fields of a Vector3 by a given float
        * @param v
        * @return Vector3
        */
        Vector3 operator/=(const float& l);

        /**
         * Returns the Norm of the current vector
         * @return float
         */
        float norm();

        /**
         * Normalizes the current vector an returns the norm of the vector we normalize
         * @return float
         */
        float normalize();

        /**
         * Returns a Normalized copy version of the current vector
         * @return Vector3
         */
        Vector3 normalized();

        /**
         * Returns the result of a dot product between two Vector3
         * @param v
         * @return float
         */
        float dot(Vector3& v);

        /**
         * Returns the result of a cross product between two Vector3
         * @param v
         * @return Vector3
         */
        Vector3 cross(Vector3& v);

    private:
        float x_;
        float y_;
        float z_;
    };

    /**
     * Returns the result of a dot product between two Vector3 v1 & v2
     * @param v1
     * @param v2
     * @return float
     */
    float dot(Vector3& v1, Vector3& v2);

    /**
     * Returns the result of a dot product between two Vector3 v1 & v2
     * @param v1
     * @param v2
     * @return float
     */
    Vector3 cross(Vector3& v1, Vector3& v2);

    Vector3 cross(const Vector3& v1, const Vector3& v2);


    std::ostream& operator<<(std::ostream& out, Vector3& vect);

}

#endif //RAYTRACER_VECTOR3_H
