#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "Vertex.h"
#include "Ray.h"
#include "Material.h"
#include <vector>

class Scene;

class Triangle
{
    const Scene * _scene;


    MaterialId  _materialId;

    Vector3     _normal;
    Vector3     _unitNormal;
    ////////////////////////////////////
    int _textureId;
    int _id;
    std::vector<std::vector<float> > _uvs;
    /////////////////////////////////////
    void calculateNormals();

public:
        VertexId    _vertices[3];

    ////////////////
    explicit Triangle(const VertexId (&vertices)[3], MaterialId materialId, int textureId, int id, std::vector<std::vector<float> > uvs);
    ////////////////
    void SetScene(const Scene* scene);

	const VertexId(&Vertices()const)[3]
	{
		return _vertices;
	}

    bool HitParameter(const Ray& ray, float& parameter) const;

    bool RayHit(const Ray& ray, float t, RayHitInfo& hitInfo) const;

    const Vector3& Normal(const Vector3& at) const
    {
        return _unitNormal;
    }

    //////////////////////////
    int GetTextureId() const{
        return _textureId;
    }

    std::vector<std::vector<float> > GetUvs() const {
        return _uvs;
    }

    int GetId() const {
        return _id;
    }
    //////////////////////////

};

#endif //RAYTRACER_TRIANGLE_H

