#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include <queue>
#include "Camera.h"
#include "Sphere.h"
#include "Mesh.h"
#include "Color.h"
#include "PointLight.h"
#include "Octree.h"
extern "C" {
#include "jpeg_reader/aoa_jpeg.h"
}
#include <limits>


class Scene {

    Octree _root;

    std::vector<Vertex> _vertices;

    std::vector<Camera> _cameras;
    std::vector<Sphere> _spheres;
    std::vector<Mesh>   _meshes;

    std::vector<Material> _materials;

    std::vector<PointLight> _lights;

    int _rayReflect;
    Color _background;
    Color _ambient;

    ////////////////////
    std::vector<Triangle> _triangles;
    std::vector<UCOLOR**> _textures;
    std::vector<int> _textureHeight;
    std::vector<int> _textureWidth;
    std::vector<Vector3> _translations;
    std::vector<Vector3> _rotations;
    std::vector<float> _rotationAngles;
    std::vector<Vector3> _scalings;
    ////////////////////

public:

	Scene() = default;
	Scene(const Scene& rhs);

    const std::vector<Camera>& Cameras() const
    {
        return _cameras;
    }

    const std::vector<Sphere>& Spheres() const
    {
        return _spheres;
    }

    ///////////////////////////////
    const std::vector<Triangle>& Triangles() const
    {
        return _triangles;
    }
    ////////////////////////////////

    const std::vector<Mesh>& Meshes() const
    {
        return _meshes;
    }

    const std::vector<PointLight>& Lights() const
    {
        return _lights;
    }

    const Color& AmbientLight() const
    {
        return _ambient;
    }

    const Color& BackgroundColor() const
    {
        return _background;
    }

    int ReflectionCount() const
    {
        return _rayReflect;
    }

    const Vertex& GetVertex(VertexId id) const {
        return _vertices[id - 1];
    }
    
    const Material& GetMaterial(MaterialId id) const {
        return _materials[id - 1];
    }

    ///////////////////////////////////////
    UCOLOR** GetTexture(int id) const {
        return _textures[id-1];
    }

    int GetTextureHeight(int id) const {
        return _textureHeight[id-1];
    }

    int GetTextureWidth(int id) const {
        return _textureWidth[id-1];
    }
    ///////////////////////////////////////

    friend std::istream& operator>>(std::istream& stream, Scene& scene);

	Scene& operator=(const Scene& rhs);

    void AddCameras(std::istream& stream);

    static Scene GetMockScene();

    template <bool CalculateNormal = true>
    bool Raycast(const Ray& ray, RayHitInfo& hitInfo) const;

    template <bool CalculateNormal = true>
    bool FastRaycast(const Ray& ray, RayHitInfo& hitInfo) const;

    template <bool CalculateNormal = true>
    bool FastRaycast(const Ray& ray, RayHitInfo& hitInfo, std::deque<const Triangle*> cache) const;
};

template <bool CalculateNormal>
bool Scene::FastRaycast(const Ray& ray, RayHitInfo& hitInfo, std::deque<const Triangle*> cache) const
{
    RayHitInfo info;
    const Triangle * hitTri = nullptr;
    float nearestParam = std::numeric_limits<float>::infinity();
    bool hasHit = false;
    float param;

    bool fromCache;
    for (const auto& tri : cache)
    {
        if (tri->HitParameter(ray, param) && param < nearestParam && param > 0)
        {
            if (tri->RayHit(ray, param, info)) {
                hitTri = tri;
                hasHit = true;
                fromCache = true;
                if (CalculateNormal) {
                    info.Normal = hitTri->Normal(info.Position);
                }
                hitInfo = info;
                nearestParam = info.Parameter;
            }
        }
    }

    for (const auto& sph : _spheres)
    {
        if (sph.RayHit(ray, info))
        {
            if (info.Parameter > 0 && info.Parameter < nearestParam)
            {
                hitTri = nullptr;
                hasHit = true;
                if (CalculateNormal) {
                    info.Normal = sph.Normal(info.Position);
                }
                hitInfo = info;
                nearestParam = info.Parameter;
            }
        }
    }

    std::queue<const Octree*> nodes;
    nodes.push(&_root);

    while (!nodes.empty())
    {
        if (nodes.front()->RayHit(ray))
        {
            const auto& tris = nodes.front()->Triangles();
            for (const auto& tri : tris)
            {
                if (tri->HitParameter(ray, param) && param < nearestParam && param > 0)
                {
                    if (tri->RayHit(ray, param, info)) {
                        hitTri = tri;
                        hasHit = true;
                        fromCache = false;
                        if (CalculateNormal) {
                            info.Normal = hitTri->Normal(info.Position);
                        }
                        hitInfo = info;
                        nearestParam = info.Parameter;
                    }
                }
            }
            for (const auto& child : nodes.front()->Children())
            {
                nodes.push(&child);
            }
        }
        nodes.pop();
    }

    if (hitTri) {
        if (!fromCache)
        {
            cache.push_back(hitTri);
        }
    }

    if (cache.size() > 4)
    {
        cache.pop_front();
    }

    return hasHit;
}

template <bool CalculateNormal>
bool Scene::FastRaycast(const Ray& ray, RayHitInfo& hitInfo) const
{
    RayHitInfo info;
    const Triangle * hitTri = nullptr;
    float nearestParam = std::numeric_limits<float>::infinity();
    bool hasHit = false;

    for (const auto& sph : _spheres)
    {
        if (sph.RayHit(ray, info))
        {
            if (info.Parameter > 0 && info.Parameter < nearestParam)
            {
                hasHit = true;
                if (CalculateNormal) {
                    info.Normal = sph.Normal(info.Position);
                }
                hitInfo = info;
                nearestParam = info.Parameter;
            }
        }
    }

    std::queue<const Octree*> nodes;
    nodes.push(&_root);

    float param;
    while (!nodes.empty())
    {
        if (nodes.front()->RayHit(ray))
        {
            const auto& tris = nodes.front()->Triangles();
            for (const auto& tri : tris)
            {
                if (tri->HitParameter(ray, param) && param < nearestParam && param > 0)
                {
                    if (tri->RayHit(ray, param, info)) {
                        hitTri = tri;
                        hasHit = true;
                        if (CalculateNormal) {
                            info.Normal = hitTri->Normal(info.Position);
                        }
                        hitInfo = info;
                        nearestParam = info.Parameter;
                    }
                }
            }
            for (const auto& child : nodes.front()->Children())
            {
                nodes.push(&child);
            }
        }
        nodes.pop();
    }

    return hasHit;
}

template <bool CalculateNormal>
bool Scene::Raycast(const Ray& ray, RayHitInfo& hitInfo) const
{
    return FastRaycast(ray, hitInfo);
}

#endif //RAYTRACER_SCENE_H
