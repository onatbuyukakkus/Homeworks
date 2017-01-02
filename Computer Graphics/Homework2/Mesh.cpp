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

/*std::istream &operator>>(std::istream &stream, Mesh &mesh)
{
    stream >> mesh._triCount;
    stream >> mesh._materialId;

    VertexId ids[3];
    mesh._tris.reserve(mesh._triCount);
    for (auto i = 0U; i < mesh._triCount; ++i) {
        stream >> ids[0] >> ids[1] >> ids[2];
        mesh._tris.push_back(Triangle(ids, mesh._materialId));
    }

    return stream;
}*/
