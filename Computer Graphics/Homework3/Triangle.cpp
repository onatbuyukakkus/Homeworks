#include <cassert>
#include "Triangle.h"
#include "Scene.h"

Triangle::Triangle(std::vector<Vertex> vertices, int id, std::vector<Color> colors)
{
    _vertices = vertices;
    _colors = colors;
    _id = id;
}

void Triangle::SetScene(const Scene *scene)
{
    _scene = scene;
    calculateNormals();
}

void Triangle::calculateNormals()
{
    Vector3 normal = Vector3::Cross(
            _vertices[1].Position()-_vertices[0].Position(), _vertices[2].Position()-_vertices[0].Position()
    );
    _normal = normal;
    _unitNormal = normal.Normalized();
}