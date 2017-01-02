#ifndef RAYTRACER_MESH_H
#define RAYTRACER_MESH_H
#include <vector>
#include "Vertex.h"
#include "Triangle.h"
using namespace std;

class Mesh {
public:
	int _id;
	int _triangleCount;
	int _materialId;
	vector <Triangle> _triangles;

	Mesh(int id, int triangleCount, int materialId) {
		_id = id;
		_triangleCount = triangleCount;
		_materialId = materialId;
	}

	void addTriangle(Triangle triangle) {
		_triangles.push_back(triangle);
	}	
};

#endif //RAYTRACER_MESH_H
