#include "Mesh.h"


Mesh::Mesh(size_t triCount, MaterialId matId, std::vector<Triangle> tris)
        : _triCount(triCount), _materialId(matId), _tris(tris)
{
}

void Mesh::SetScene(const Scene *scene)
{
    _scene = scene;
    for (auto& tri : _tris) {
        tri.SetScene(scene);
    }
}