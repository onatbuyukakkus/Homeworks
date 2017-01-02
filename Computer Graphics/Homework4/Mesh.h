#ifndef RAYTRACER_MESH_H
#define RAYTRACER_MESH_H


#include <iosfwd>
#include <vector>
#include <iostream>
#include "Material.h"
#include "Vertex.h"
#include "Triangle.h"
#include <tuple>
using namespace std;

class Mesh {
    

public:
    const Scene* _scene;

    size_t _triCount;
    MaterialId _materialId;
    std::vector<Triangle> _tris;
    int _type;
    std::vector< tuple <char, int> > _transformations;
    int _transformationsCount;


    Mesh() = default;
    Mesh(size_t triCount, MaterialId matId, std::vector<Triangle> tris);

    void SetScene(const Scene* scene);
};


#endif //RAYTRACER_MESH_H