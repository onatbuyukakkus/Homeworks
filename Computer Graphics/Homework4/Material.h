#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "Color.h"
#include "Vector3.h"

class Scene;

class Material {
    public:
        Color _ambient;
        Color _diffuse;
        Color _specular;
        size_t _phong;
};

typedef size_t MaterialId;

#endif //RAYTRACER_MATERIAL_H
