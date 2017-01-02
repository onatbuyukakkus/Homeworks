#ifndef RAYTRACER_VERTEX_H
#define RAYTRACER_VERTEX_H

#include "Vector3.h"

class Vertex {
    Vector3 _position;

public:
	Vector3 _normal;
    int _triCount;
    Vertex() = default;
    explicit Vertex(Vector3 position);

    inline const Vector3& Position() const
    {
        return _position;
    }

    friend std::istream& operator>>(std::istream& stream, Vertex& vertex);
};

typedef size_t VertexId;

#endif //RAYTRACER_VERTEX_H
