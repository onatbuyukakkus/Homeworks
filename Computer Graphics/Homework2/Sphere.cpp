#include "Sphere.h"
#include "Scene.h"
#include <cmath>
using namespace std;

Sphere::Sphere(VertexId center, float radius, MaterialId material, int textureId, int id)
{
    _center = center;
    _radius = radius;
    _material = material;
    _textureId = textureId;
    _id = id;
    _up.X(0);
    _up.Y(1);
    _up.Z(0);
    _right.X(1);
    _right.Y(0);
    _right.Z(0);
}

Vector3 Sphere::Normal(const Vector3 &at) const
{
    return (at - _scene->GetVertex(_center).Position()) / _radius;
}

void Sphere::SetScene(const Scene *scene)
{
    _scene = scene;
}

bool Sphere::RayHit(const Ray& ray, RayHitInfo& hitInfo) const
{
    Vector3 line = ray.Origin() - _scene->GetVertex(_center).Position();        // (o - c)

    float B = 2 * (Vector3::Dot(ray.Direction(), line));                        // Dot(d, (o - c))
    float C = line.SquaredMagnitude() - (_radius * _radius);                   // Dot((o - c), (o - c)) - r^2

    float Delta = B * B - 4 * C;

    if (Delta < -0.00001f) {
        return false;
    }

	float root = (-B - std::sqrt(Delta)) / 2;

	hitInfo.Position = ray.Origin() + (root * ray.Direction());
	hitInfo.Material = _material;
	hitInfo.Parameter = root;
    /////////////////////////
    hitInfo.SphereId = _id;
    hitInfo.TriangleId = -1;
    /////////////////////////
    return true;
}

std::istream &operator>>(std::istream &stream, Sphere &sphere)
{
    stream >> sphere._material;
    stream >> sphere._radius;
    stream >> sphere._center;

    return stream;
}


///////////////////////////////////////////
void Sphere::printSphere() {
    cout << "materialID " << _material << endl;
    cout << "center " << _center << endl;
    cout << "radius " << _radius << endl;
    cout << "textureID " << _textureId << endl;
}
//////////////////////////////////////////
