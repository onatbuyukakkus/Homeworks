#include <cassert>
#include "Octree.h"
#include "Scene.h"
#include <algorithm>
#include <iostream>


Octree::Octree()
        : Octree(Vector3::Zero, 0)
{ }

Octree::Octree(const Vector3 &backBotLeft, float size)
        : _backBotLeft(backBotLeft), _size(size)
{
    b_min[0] = _backBotLeft.X();
    b_max[0] = b_min[0] + _size;

    b_min[1] = _backBotLeft.Y();
    b_max[1] = b_min[1] + _size;

    b_min[2] = _backBotLeft.Z();
    b_max[2] = b_min[2] + _size;
}


void Octree::SetScene(const Scene *scene)
{
    _scene = scene;
    for (auto &child : _children) {
        child.SetScene(scene);
    }
}

void Octree::Partition(size_t depth)
{
    if (!depth) {
        return;
    }
    /*
     * 0 -> bottom, left, back
     * 1 -> bottom, right, back
     * 2 -> bottom, left, front
     * 3 -> bottom, right, front
     * 4 -> top, left, back
     * 5 -> top, right, back
     * 6 -> top, left, front
     * 7 -> top, right, front
     */

    float newSize = _size * 0.5f;

    Vector3 right(newSize, 0, 0);
    Vector3 front(0, 0, newSize);
    Vector3 up(0, newSize, 0);

    _children.resize(8);
    _children[0] = Octree(_backBotLeft, newSize);
    _children[1] = Octree(_backBotLeft + right, newSize);
    _children[2] = Octree(_backBotLeft + front, newSize);
    _children[3] = Octree(_backBotLeft + right + front, newSize);

    _children[4] = Octree(_backBotLeft + up, newSize);
    _children[5] = Octree(_backBotLeft + up + right, newSize);
    _children[6] = Octree(_backBotLeft + up + front, newSize);
    _children[7] = Octree(_backBotLeft + up + right + front, newSize);

    for (auto &child : _children) {
        child.Partition(depth - 1);
    }
}

bool Octree::RayHit(const Ray &ray) const
{
    using std::min;
    using std::max;

    float t1 = (b_min[0] - ray.Origin()[0]) * ray.InverseDirection()[0];
    float t2 = (b_max[0] - ray.Origin()[0]) * ray.InverseDirection()[0];

    float tMin = min(t1, t2);
    float tMax = max(t1, t2);

    for (int i = 1; i < 3; ++i) {
        t1 = (b_min[i] - ray.Origin()[i]) * ray.InverseDirection()[i];
        t2 = (b_max[i] - ray.Origin()[i]) * ray.InverseDirection()[i];

        tMin = max(tMin, min(t1, t2));
        tMax = min(tMax, max(t1, t2));
    }

    return tMax >= max(tMin, 0.0f);
}

inline bool Octree::Contains(const Vertex &vertex) const
{
    return Contains(vertex.Position());
}

inline bool Octree::Contains(const Vector3& pos) const
{
    const float &x = pos.X(), &y = pos.Y(), &z = pos.Z();

    return
            (x > b_min[0] && x <= b_max[0]) &&
            (y > b_min[1] && y <= b_max[1]) &&
            (z > b_min[2] && z <= b_max[2]);
}

bool Octree::Contains(const Triangle &triangle) const
{
    return
            Contains(_scene->GetVertex(triangle.Vertices()[0])) &&
            Contains(_scene->GetVertex(triangle.Vertices()[1])) &&
            Contains(_scene->GetVertex(triangle.Vertices()[2]));
}

void Octree::Insert(const Triangle &tri)
{
    Octree *containing;
    if ((containing = ContainingChild(tri))) {
        containing->Insert(tri);
        return;
    }

    _tris.push_back(&tri);
}

void Octree::CountObjects()
{
    _recTriCount = _tris.size();

    for (auto& child : _children)
    {
        child.CountObjects();
        _recTriCount += child._recTriCount;
    }
}

void Octree::Optimize()
{
    std::vector<Octree> newChildren;

    for (auto i = 0U; i < _children.size(); ++i) {
        if(_children[i]._recTriCount > 0)
        {
            newChildren.push_back(_children[i]);
            newChildren.back().Optimize();
        }
    }

    _children = newChildren;
}
