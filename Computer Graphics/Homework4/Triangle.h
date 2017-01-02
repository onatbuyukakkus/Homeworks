#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "Vertex.h"
#include "Material.h"
#include <vector>

class Scene;

class Triangle
{
    const Scene * _scene;


    MaterialId  _materialId;


public:
    VertexId    _vertices[3];
    Vector3     _normal;
    Vector3     _unitNormal;
    void calculateNormals();

    ////////////////
    explicit Triangle(const VertexId (&vertices)[3], MaterialId materialId);
    ////////////////
    void SetScene(const Scene* scene);

	const VertexId(&Vertices()const)[3]
	{
		return _vertices;
	}

    const Vector3& Normal(const Vector3& at) const
    {
        return _unitNormal;
    }
};

#endif //RAYTRACER_TRIANGLE_H

