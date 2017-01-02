#ifndef RAYTRACER_POINTLIGHT_H
#define RAYTRACER_POINTLIGHT_H

#include "Vector3.h"
#include "Color.h"

const float PI = 3.1415926535f;

class PointLight {
    Vector3 _position;
    Color _intensity;

public:

    /*
     * Calculates this light's intensity at the given point.
     */
    inline Color Intensity(const Vector3& point) const
    {
        return _intensity / (4 * PI * (point - _position).SquaredMagnitude());
    }

    inline const Vector3& Position() const
    {
        return _position;
    }

    friend std::istream &operator>>(std::istream &stream, PointLight &light);
};


#endif //RAYTRACER_POINTLIGHT_H
