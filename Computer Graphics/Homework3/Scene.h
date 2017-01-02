#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include <queue>
#include "Camera.h"
#include "Model.h"
#include "Color.h"
#include <limits>


class Scene {

    std::vector<Vertex> _vertices;

    std::vector<Camera> _cameras;
    std::vector<Model>   _meshes;

    int _rayReflect;
    Color _background;
    Color _ambient;

    std::vector<Triangle> _triangles;
    std::vector<int> _textureHeight;
    std::vector<int> _textureWidth;
    std::vector<Vector3> _translations;
    std::vector<Vector3> _rotations;
    std::vector<float> _rotationAngles;
    std::vector<Vector3> _scalings;

public:

	Scene() = default;
	Scene(const Scene& rhs);

    const std::vector<Camera>& Cameras() const
    {
        return _cameras;
    }

    const std::vector<Triangle>& Triangles() const
    {
        return _triangles;
    }

    const std::vector<Model>& Meshes() const
    {
        return _meshes;
    }

    const Color& AmbientLight() const
    {
        return _ambient;
    }

    const Color& BackgroundColor() const
    {
        return _background;
    }

    int ReflectionCount() const
    {
        return _rayReflect;
    }

    const Vertex& GetVertex(VertexId id) const {
        return _vertices[id - 1];
    }
    

    int GetTextureHeight(int id) const {
        return _textureHeight[id-1];
    }

    int GetTextureWidth(int id) const {
        return _textureWidth[id-1];
    }

    friend std::istream& operator>>(std::istream& stream, Scene& scene);

	Scene& operator=(const Scene& rhs);

    void AddCameras(std::istream& stream);

};

#endif //RAYTRACER_SCENE_H
