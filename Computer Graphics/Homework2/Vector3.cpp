#include <math.h>
#include <assert.h>
#include "Vector3.h"

Vector3::Vector3() : Vector3(0 , 0, 0) {}

Vector3::Vector3(float x, float y, float z) {
    X(x);
    Y(y);
    Z(z);
    W(0);
}



float Vector3::X() const {
    return _components[0];
}

float Vector3::Y() const {
    return _components[1];
}

float Vector3::Z() const {
    return _components[2];
}

float Vector3::W() const {
    return _components[3];
}

void Vector3::X(float x) {
    _components[0] = x;
}

void Vector3::Y(float y) {
    _components[1] = y;
}

void Vector3::Z(float z) {
    _components[2] = z;
}

void Vector3::W(float w) {
    _components[3] = w;
}

float Vector3::SquaredMagnitude() const {
    return Dot(*this, *this);
}

float Vector3::Magnitude() const {
    return sqrtf(SquaredMagnitude());
}

Vector3 Vector3::Normalized() const {
    assert(SquaredMagnitude() > 0);
    return (*this) / Magnitude();
}

void Vector3::Normalize() {
    (*this) = Normalized();
}

Vector3 operator*(float scalar, const Vector3& vector)
{
    return vector * scalar;
}

Vector3 Vector3::operator*(float scalar) const {
    return Vector3(X() * scalar, Y() * scalar, Z() * scalar);
}

Vector3 Vector3::operator/(float scalar) const {
    assert(scalar != 0);
    float multiplier = 1 / scalar;
    return *this * multiplier;
}

Vector3 &Vector3::operator*=(float scalar) {
    _components[0] *= scalar;
    _components[1] *= scalar;
    _components[2] *= scalar;

    return *this;
}

Vector3 &Vector3::operator/=(float scalar) {
    assert(scalar != 0);
    float multiplier = 1 / scalar;
    return *this *= multiplier;
}

Vector3 Vector3::operator+(const Vector3 &vector) const {
    return Vector3(X() + vector.X(), Y() + vector.Y(), Z() + vector.Z());
}

Vector3 operator-(const Vector3& vector)
{
    return -1 * vector;
}

Vector3 Vector3::operator-(const Vector3 &vector) const {
    return Vector3(X() - vector.X(), Y() - vector.Y(), Z() - vector.Z());
}

Vector3 &Vector3::operator+=(const Vector3 &vector) {
    _components[0] += vector._components[0];
    _components[1] += vector._components[1];
    _components[2] += vector._components[2];

    return *this;
}

Vector3 &Vector3::operator*=(const Vector3 &vector) {
    _components[0] *= vector._components[0];
    _components[1] *= vector._components[1];
    _components[2] *= vector._components[2];

    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &vector) {
    _components[0] -= vector._components[0];
    _components[1] -= vector._components[1];
    _components[2] -= vector._components[2];

    return *this;
}

bool Vector3::operator==(const Vector3 &vector) const {
    return  _components[0] == vector._components[0] &&
            _components[1] == vector._components[1] &&
            _components[2] == vector._components[2];
}

bool Vector3::operator!=(const Vector3 &vector) const {
    return  _components[0] != vector._components[0] ||
            _components[1] != vector._components[1] ||
            _components[2] != vector._components[2];
}

float &Vector3::operator[](int index) {
    return _components[index];
}

float Vector3::operator[](int index) const {
    return _components[index];
}

float Vector3::Dot(const Vector3 &v1, const Vector3 &v2) {
    return
            v1.X() * v2.X() +
            v1.Y() * v2.Y() +
            v1.Z() * v2.Z();
}

Vector3 Vector3::Cross(const Vector3 &v1, const Vector3 &v2) {
    float x, y, z;
    x = v1.Y() * v2.Z() - v1.Z() * v2.Y();
    y = v1.Z() * v2.X() - v1.X() * v2.Z();
    z = v1.X() * v2.Y() - v1.Y() * v2.X();
    return Vector3(x, y, z);
}

float Vector3::Distance(const Vector3 &v1, const Vector3 &v2) {
    return (v2 - v1).Magnitude();
}

const Vector3 Vector3::Zero = Vector3(0, 0, 0);

std::ostream &operator<<(std::ostream &os, const Vector3 &vector) {
    os << "(" << vector.X() << ", " << vector.Y() << ", " << vector.Z() << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Vector3 &vector) {
    return is >> vector._components[0] >> vector._components[1] >> vector._components[2];
}
