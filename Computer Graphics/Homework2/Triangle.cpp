#include <cassert>
#include "Triangle.h"
#include "Scene.h"

Triangle::Triangle(const VertexId (&vertices)[3], MaterialId materialId, int textureId, int id, std::vector<std::vector<float> > uvs)
{
    _vertices[0] = vertices[0];
    _vertices[1] = vertices[1];
    _vertices[2] = vertices[2];

    _materialId = materialId;
    /////////////////////////////
    _textureId = textureId;
    _id = id;
    for(int i=0; i<uvs.size(); i++) {
        std::vector<float> tmp;
        tmp.push_back(uvs[i][0]);
        tmp.push_back(uvs[i][1]);
        _uvs.push_back(tmp);
    }
    /////////////////////////////
}

void Triangle::SetScene(const Scene *scene)
{
    _scene = scene;
    calculateNormals();
}

void Triangle::calculateNormals()
{
    Vector3 normal = Vector3::Cross(
            _scene->GetVertex(_vertices[1]).Position() - _scene->GetVertex(_vertices[0]).Position(),
            _scene->GetVertex(_vertices[2]).Position() - _scene->GetVertex(_vertices[0]).Position()
    );
    _normal = normal;
    _unitNormal = normal.Normalized();
}


bool Triangle::HitParameter(const Ray &ray, float& parameter) const
{
    if (Vector3::Dot(_normal, ray.Direction()) == 0)
    {
        // Plane normal and the ray direction are perpendicular to each other,
        // therefore no intersection between the surface and the ray.
        return false;
    }

    const Vector3& point0 = _scene->GetVertex(_vertices[0]).Position();
    Vector3 aToO = point0 - ray.Origin();

    parameter = Vector3::Dot(_normal, aToO) / Vector3::Dot(ray.Direction(), _normal);
    return true;
}

bool Triangle::RayHit(const Ray& ray, float t, RayHitInfo& hitInfo) const
{
    Vector3 pointOfIntersection = ray.Origin() + ray.Direction() * t;
    const Vector3& point0 = _scene->GetVertex(_vertices[0]).Position();

    float alpha, beta, gamma;

    float squaredNormalMag = _normal.SquaredMagnitude();

    Vector3 subTriangleNormals[2];
    const Vector3& point1 = _scene->GetVertex(_vertices[2]).Position();
    const Vector3& point2 = _scene->GetVertex(_vertices[1]).Position();

    subTriangleNormals[0] = Vector3::Cross (point1 - point2, pointOfIntersection - point2);
    subTriangleNormals[1] = Vector3::Cross (point0 - point1, pointOfIntersection - point1);

    alpha = Vector3::Dot(_normal, subTriangleNormals[0]) / squaredNormalMag;

    if (alpha > 1.000001f || alpha < -0.000001f)
    {
        return false;
    }

    beta = Vector3::Dot(_normal, subTriangleNormals[1]) / squaredNormalMag;

    if (beta > 1.000001f || beta < -0.000001f)
    {
        return false;
    }

    gamma = 1 - alpha - beta;

    if (gamma > 1.000001f || gamma < -0.000001f)
    {
        return false;
    }

    hitInfo.Parameter = t;
    hitInfo.Position = pointOfIntersection;
    hitInfo.Material = _materialId;
    ////////////////////////////
    hitInfo.TriangleId = _id;
    hitInfo.SphereId = -1;
    hitInfo.Gamma = gamma;
    hitInfo.Beta = beta;
    ////////////////////////////

    return true;
}
