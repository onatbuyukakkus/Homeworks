#include "Model.h"


Model::Model(int modelId,  int modelType, size_t triCount, std::vector<Triangle> tris)
        : _modelId(modelId), _modelType(modelType), _triCount(triCount), _tris(tris)
{
}

void Model::SetScene(const Scene *scene)
{
    _scene = scene;
    for (auto& tri : _tris) {
        tri.SetScene(scene);
    }
}
