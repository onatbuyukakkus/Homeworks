#include "Vertex.h"

Vertex::Vertex(Vector3 position)
{
    _position = position;
}

std::istream &operator>>(std::istream &stream, Vertex &vertex)
{
    stream >> vertex._position;
    return stream;
}
