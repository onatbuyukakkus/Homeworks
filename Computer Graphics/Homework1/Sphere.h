#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Ray.h"

class Sphere {

public:
	int _id;
	int _materialId;
	float _radius;
	Vector3 _center;

	Sphere(int id, int materialId, float radius, Vector3 center) {
		_id = id;
		_materialId = materialId;
		_radius = radius;
		_center = center;
	}
    // This function gets a ray, and if the sphere intersects with the ray, returns true and fills the hitInfo struct
    // Else return false and leave hitInfo unchanged
    bool Intersect(const Ray& ray, RayHitInfo& hitInfo) const;
};


#endif //RAYTRACER_SPHERE_H
