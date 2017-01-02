#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Material.h"
#include "Vector3.h"
#include "Color.h"
extern "C" {
#include "jpeg_reader/aoa_jpeg.h"
}

class Ray {

    Vector3 _origin;
    Vector3 _direction;
    Vector3 _inv_direction;

public:

    Ray(const Vector3& origin, const Vector3& direction);

    const Vector3 &Origin() const {
        return _origin;
    }

    const Vector3 &Direction() const {
        return _direction;
    }

    const Vector3 &InverseDirection() const {
        return _inv_direction;
    }


    void Direction(const Vector3& dir);
};

std::ostream& operator<<(std::ostream& out, const Ray& ray);

struct RayHitInfo {

	MaterialId Material;
	Vector3 Position;
	Vector3 Normal;

    float Parameter;

    ////////////////////
    int SphereId;
    int TriangleId;
    float Beta;
    float Gamma;
    ///////////////////////
};

#endif //RAYTRACER_RAY_H
