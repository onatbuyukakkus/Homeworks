//
// Created by Fatih on 8/29/15.
//

#ifndef MATH_VECTOR3_H
#define MATH_VECTOR3_H

#include <iostream>

class Vector3 {

    float _components[4];

    void W(float w);
    float W() const;
public:
    Vector3();
    Vector3(float x, float y, float z);

    float X() const;
    float Y() const;
    float Z() const;

    void X(float x);
    void Y(float y);
    void Z(float z);

    float SquaredMagnitude() const;
    float Magnitude() const;

    Vector3 Normalized() const;
    void Normalize();

    // Scalar operators
    Vector3 operator*(float scalar) const;
    Vector3 operator/(float scalar) const;
    Vector3& operator*=(float scalar);
    Vector3& operator/=(float scalar);

    // Vector operators
    Vector3 operator+(const Vector3& vector) const;
    Vector3 operator-(const Vector3& vector) const;
    Vector3& operator+=(const Vector3& vector);
    Vector3& operator-=(const Vector3& vector);
    Vector3& operator*=(const Vector3& vector);


    // Logical operators
    bool operator==(const Vector3& vector) const;
    bool operator!=(const Vector3& vector) const;

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const Vector3& vector);
    friend std::istream& operator>>(std::istream& is, Vector3& vector);

    float& operator[](int index);
    float operator[](int index) const;

    static float Dot(const Vector3& v1, const Vector3& v2);
    static Vector3 Cross(const Vector3& v1, const Vector3& v2);

    static float Distance(const Vector3& v1, const Vector3& v2);

    static const Vector3 Zero;
};

Vector3 operator-(const Vector3& vector);
Vector3 operator*(float scalar, const Vector3& vector);

#endif //MATH_VECTOR3_H
