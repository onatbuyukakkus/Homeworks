//
// Created by Fatih on 10/30/15.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include <queue>
#include "Camera.h"
#include "Mesh.h"
#include "Color.h"
#include "PointLight.h"
#include <limits>


class Scene {

    std::vector<Vertex> _vertices;

    std::vector<Mesh>   _meshes;

    std::vector<Material> _materials;

    std::vector<PointLight> _lights;

    Color _background;
    Color _ambient;

    

public:
    Camera _camera;
    ///////////////////
    std::vector<Triangle> _triangles;
    std::vector<Vector3> _translations;
    std::vector<Vector3> _rotations;
    std::vector<float> _rotationAngles;
    std::vector<Vector3> _scalings;
    ////////////////////

	Scene() = default;
	Scene(const Scene& rhs);

    const Camera& Cameras() const
    {
        return _camera;
    }

    ///////////////////////////////
    const std::vector<Triangle>& Triangles() const
    {
        return _triangles;
    }

    const std::vector<Vertex>& Vertices() const
    {
        return _vertices;
    }
    ////////////////////////////////

    const std::vector<Mesh>& Meshes() const
    {
        return _meshes;
    }

    const std::vector<PointLight>& Lights() const
    {
        return _lights;
    }

    const Color& AmbientLight() const
    {
        return _ambient;
    }

    const Color& BackgroundColor() const
    {
        return _background;
    }

    const Vertex& GetVertex(VertexId id) const {
        return _vertices[id - 1];
    }
    
    const Material& GetMaterial(MaterialId id) const {
        return _materials[id - 1];
    }

    friend std::istream& operator>>(std::istream& stream, Scene& scene);

	Scene& operator=(const Scene& rhs);

    void AddCameras(std::istream& stream);

};

#endif //RAYTRACER_SCENE_H
