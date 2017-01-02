#ifndef RAYTRACER_OCTREE_H
#define RAYTRACER_OCTREE_H

#include <vector>
#include "Mesh.h"
#include "Sphere.h"

class Octree
{
	const Scene *_scene;

	std::vector<Octree> _children;

	std::vector<const Triangle*> _tris;

	size_t _recTriCount;

	Vector3 _backBotLeft;
	float _size;

	float b_min[3];
	float b_max[3];

	bool Contains(const Vertex& vertex) const;
	bool Contains(const Vector3& vertex) const;

	template <class T>
	Octree* ContainingChild(const T& obj);


public:
	void Partition(size_t depth);

	void SetScene(const Scene* scene);

	bool Contains(const Triangle& triangle) const;

	Octree();
	Octree(const Vector3& backBotLeft, float size);

	void Insert(const Triangle& tri);

	bool RayHit(const Ray& ray) const;

	const std::vector<Octree>& Children() const
	{
		return _children;
	}

	const std::vector<const Triangle*>& Triangles() const
	{
		return _tris;
	}

	void CountObjects();
	void Optimize();
};

template <class T>
Octree* Octree::ContainingChild(const T& obj)
{
	for (auto& child : _children) {
		if (child.Contains(obj))
		{
			return &child;
		}
	}

	return nullptr;
}

#endif //RAYTRACER_OCTREE_H
