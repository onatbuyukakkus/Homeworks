#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "Ray.h"
#include <vector>
using namespace std;

class Triangle
{
public:
	vector <Vector3> _positions;
	int _materialId;
	Triangle() {}
    // This function gets a ray, and if the triangle intersects with the ray, returns true and fills the hitInfo struct
    // Else return false and leave hitInfo unchanged
    bool Intersect(const Ray& ray, RayHitInfo& hitInfo) const;
};

#endif //RAYTRACER_TRIANGLE_H

