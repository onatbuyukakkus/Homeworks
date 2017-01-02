#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "Vertex.h"
#include <vector>

class Scene;

class Triangle
{
    const Scene * _scene;
    
    int _textureId;
    int _id;
    std::vector<std::vector<float> > _uvs;

public:
    std::vector<Vertex> _vertices;
    std::vector<Color> _colors;
    Vector3     _normal;
    Vector3     _unitNormal;
    int _culling;
    void calculateNormals();
    explicit Triangle(std::vector<Vertex> vertices, int id, std::vector<Color> colors);    
    void SetScene(const Scene* scene);

    std::vector<Vertex> Vertices()
	{
		return _vertices;
	}

    const Vector3& Normal(const Vector3& at) const
    {
        return _unitNormal;
    }

    int GetTextureId() const{
        return _textureId;
    }

    std::vector<std::vector<float> > GetUvs() const {
        return _uvs;
    }

    int GetId() const {
        return _id;
    }

};

#endif //RAYTRACER_TRIANGLE_H

