#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H


#include "Vertex.h"
#include "Material.h"
#include "Ray.h"
#include <vector>

class Scene;

class Sphere {
    const Scene * _scene;

    VertexId    _center;

    MaterialId  _material;

    float       _radius;

    //////////////////////////////////////
    int _id;

    int _textureId;

    Vector3 _up;
    Vector3 _right;
    /////////////////////////////////////

public:
    Sphere() = default;
    explicit Sphere(VertexId center, float radius, MaterialId material, int textureId, int id);

    void SetScene(const Scene* scene);

    bool RayHit(const Ray& ray, RayHitInfo& hitInfo) const;

    Vector3 Normal(const Vector3& at) const;

    friend std::istream& operator>>(std::istream& stream, Sphere& sphere);

    ////////////////////////////////////
    void SetUp(Vector3 vect) {
        _up = vect;
    }
    void SetRight(Vector3 vect) {
        _right = vect;
    }
    Vector3 GetUp() const{
        return _up;
    }
    Vector3 GetRight() const{
        return _right;
    }
    void SetRadius(float radius) {
        _radius = radius;
    }
    void SetCenter(VertexId center) {
        _center = center;
    }
    int GetTextureId() const{
        return _textureId;
    }
    float GetRadius() const{
        return _radius;
    }
    VertexId GetCenterId() const{
        return _center;
    }
    void printSphere();
    ////////////////////////////////////
};


#endif //RAYTRACER_SPHERE_H
