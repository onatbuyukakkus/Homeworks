#ifndef RAYTRACER_MESH_H
#define RAYTRACER_MESH_H


#include <iosfwd>
#include <vector>
#include "Material.h"
#include "Vertex.h"
#include "Triangle.h"

class Mesh {
    const Scene* _scene;

    size_t _triCount;
    MaterialId _materialId;
    std::vector<Triangle> _tris;

public:

    Mesh() = default;
    Mesh(size_t triCount, MaterialId matId, std::vector<Triangle> tris);

	const std::vector<Triangle>& GetTris() const
	{
		return _tris;
	}

    /////////////////////////////////////
    void SetTris(Triangle tri) {
        _tris.push_back(tri);
    }
    /////////////////////////////////////

    //friend std::istream& operator>>(std::istream& stream, Mesh& mesh);

    void SetScene(const Scene* scene);
};


#endif //RAYTRACER_MESH_H
