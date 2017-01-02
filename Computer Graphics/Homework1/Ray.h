#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Material.h"
#include "Vector3.h"

class Ray {
    Vector3 _origin;
    Vector3 _direction;

public:
    Ray(const Vector3& origin, const Vector3& direction) : _origin(origin), _direction(direction) {}

    const Vector3 &Origin() const {
        return _origin;
    }

    const Vector3 &Direction() const {
        return _direction;
    }
};

/////////////////
// BEWARE !
// When an intersection occurs, this struct should be filled !
/////////////////

struct RayHitInfo
{
    MaterialId  Material;
    Vector3     Position;
    Vector3     Normal;

    float       Parameter;
};

#endif //RAYTRACER_RAY_H
