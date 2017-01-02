#ifndef RAYTRACER_VERTEX_H
#define RAYTRACER_VERTEX_H

#include "Vector3.h"
#include "Color.h"

class Vertex {
    Vector3 _position;
    Color _color;

public:
    Vertex() = default;
    explicit Vertex(Vector3 position);

    inline const Vector3& Position() const
    {
        return _position;
    }

    friend std::istream& operator>>(std::istream& stream, Vertex& vertex);

    void setColor(Color color) {
    	_color = color;
    }

    inline const Color& Colors() const
    {
        return _color;
    }

    void setPosition(Vector3 position) {
        _position = position;
    }
};

typedef size_t VertexId;

#endif //RAYTRACER_VERTEX_H
