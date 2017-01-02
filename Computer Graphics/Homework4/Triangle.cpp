//
// Created by Fatih on 10/30/15.
//

#include <cassert>
#include "Triangle.h"
#include "Scene.h"

Triangle::Triangle(const VertexId (&vertices)[3], MaterialId materialId)
{
    _vertices[0] = vertices[0];
    _vertices[1] = vertices[1];
    _vertices[2] = vertices[2];

    _materialId = materialId;
}

void Triangle::SetScene(const Scene *scene)
{
    _scene = scene;
    calculateNormals();
}

void Triangle::calculateNormals()
{
    Vector3 normal = Vector3::Cross(
            _scene->GetVertex(_vertices[1]).Position() - _scene->GetVertex(_vertices[0]).Position(),
            _scene->GetVertex(_vertices[2]).Position() - _scene->GetVertex(_vertices[0]).Position()
    );
    _normal = normal;
    _unitNormal = normal.Normalized();
}