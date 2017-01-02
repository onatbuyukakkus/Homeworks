#ifndef RAYTRACER_VERTEX_H
#define RAYTRACER_VERTEX_H

#include "Vector3.h"

class Vertex {
    Vector3 _position;

public:
    Vertex() = default;
    explicit Vertex(Vector3 position);

    inline const Vector3& Position() const
    {
        return _position;
    }

    friend std::istream& operator>>(std::istream& stream, Vertex& vertex);
};

typedef size_t VertexId;

inline Vertex::Vertex(Vector3 position)
{
    _position = position;
}

inline std::istream &operator>>(std::istream &stream, Vertex &vertex)
{
    stream >> vertex._position;
    return stream;
}

#endif //RAYTRACER_VERTEX_H
