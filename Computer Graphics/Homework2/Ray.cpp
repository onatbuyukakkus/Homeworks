#include "Ray.h"

Ray::Ray(const Vector3 &origin, const Vector3 &direction)
    : _origin(origin), _direction(direction)
{
}


void Ray::Direction(const Vector3 &dir)
{
    _direction = dir;
    _inv_direction.X(1 / dir.X());
    _inv_direction.Y(1 / dir.Y());
    _inv_direction.Z(1 / dir.Z());
}


std::ostream &operator<<(std::ostream &out, const Ray &ray)
{
    out << "(" << ray.Origin() << ", " << ray.Direction() << ")";
	return out;
}
