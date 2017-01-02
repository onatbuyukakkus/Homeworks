#ifndef RAYTRACER_POINTLIGHT_H
#define RAYTRACER_POINTLIGHT_H
#include <vector>
#include <fstream>
#include "Camera.h"
#include "Sphere.h"
#include "Mesh.h"
#include "Color.h"
#include "PointLight.h"
#include "Vertex.h"
#include <string>
using namespace std;

class PointLight {
public:
	float _X;
	float _Y;
	float _Z;
	Vector3 _intensity;
	PointLight() {}
	PointLight(float X, float Y, float Z, float r, float g, float b) {
		_X = X;
		_Y = Y;
		_Z = Z;
		_intensity._data[0]=r;
		_intensity._data[1]=g;
		_intensity._data[2]=b;
	}

};

#endif //RAYTRACER_POINTLIGHT_H
