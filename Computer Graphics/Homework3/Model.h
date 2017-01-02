#ifndef RAYTRACER_MESH_H
#define RAYTRACER_MESH_H


#include <iosfwd>
#include <vector>
#include "Vertex.h"
#include "Triangle.h"

class Model {
    const Scene* _scene;
    int _modelId;
    size_t _triCount;
    std::vector<Triangle> _tris;

public:

    Model() = default;
    Model(int modelId, int modelType, size_t triCount, std::vector<Triangle> tris);
    int _modelType;

	const std::vector<Triangle>& GetTris() const
	{
		return _tris;
	}

    void SetTris(std::vector<Triangle> tris) {
        _tris = tris;
    }

    void SetId(int id) {
        _modelId = id;
    }

    void SetType(int type) {
        _modelType = type;
    }

    void SetTriCount(size_t triCount) {
        _triCount = triCount;
    }

    void SetScene(const Scene* scene);
};


#endif //RAYTRACER_MESH_H
