#include "Triangle.h"
#include <math.h>
using namespace std;

float determinant(Vector3 vect1, Vector3 vect2, Vector3 vect3) {
	return vect1._data[0] * 
	((vect2._data[1]*vect3._data[2]) - (vect3._data[1]*vect2._data[2])) - 
		vect1._data[1] * (vect2._data[0] * vect3._data[2] - vect3._data[0] * 
			vect2._data[2]) + vect1._data[2] * (vect2._data[0] * vect3._data[1] -
			 vect3._data[0] * vect2._data[1]);
}

Vector3 crossProduct2(Vector3 vect1, Vector3 vect2) {
    Vector3 result;
    result._data[0] = vect1._data[1]*vect2._data[2] - vect1._data[2]*vect2._data[1];
    result._data[1] = vect1._data[2]*vect2._data[0] - vect1._data[0]*vect2._data[2];
    result._data[2] = vect1._data[0]*vect2._data[1] - vect1._data[1]*vect2._data[0];
    return result;
}

bool Triangle::Intersect(const Ray& ray, RayHitInfo& hitInfo) const {

	Vector3 vect1;
	Vector3 vect2;
	Vector3 vect3;

	vect1._data[0] = _positions[0]._data[0] - _positions[1]._data[0];
	vect1._data[1] = _positions[0]._data[0] - _positions[2]._data[0];
	vect1._data[2] = ray.Direction()._data[0];

	vect2._data[0] = _positions[0]._data[1] - _positions[1]._data[1];
	vect2._data[1] = _positions[0]._data[1] - _positions[2]._data[1];
	vect2._data[2] = ray.Direction()._data[1];

	vect3._data[0] = _positions[0]._data[2] - _positions[1]._data[2];
	vect3._data[1] = _positions[0]._data[2] - _positions[2]._data[2];
	vect3._data[2] = ray.Direction()._data[2];
	float a = determinant(vect1, vect2, vect3);

	vect1._data[0] = _positions[0]._data[0] - ray.Origin()._data[0];
	vect1._data[1] = _positions[0]._data[0] - _positions[2]._data[0];
	vect1._data[2] = ray.Direction()._data[0];

	vect2._data[0] = _positions[0]._data[1] - ray.Origin()._data[1];
	vect2._data[1] = _positions[0]._data[1] - _positions[2]._data[1];
	vect2._data[2] = ray.Direction()._data[1];

	vect3._data[0] = _positions[0]._data[2] - ray.Origin()._data[2];
	vect3._data[1] = _positions[0]._data[2] - _positions[2]._data[2];
	vect3._data[2] = ray.Direction()._data[2];
	float beta = determinant(vect1, vect2, vect3)/a;

	vect1._data[0] = _positions[0]._data[0] - _positions[1]._data[0];
	vect1._data[1] = _positions[0]._data[0] - ray.Origin()._data[0];
	vect1._data[2] = ray.Direction()._data[0];

	vect2._data[0] = _positions[0]._data[1] - _positions[1]._data[1];
	vect2._data[1] = _positions[0]._data[1] - ray.Origin()._data[1];
	vect2._data[2] = ray.Direction()._data[1];

	vect3._data[0] = _positions[0]._data[2] - _positions[1]._data[2];
	vect3._data[1] = _positions[0]._data[2] - ray.Origin()._data[2];
	vect3._data[2] = ray.Direction()._data[2];
	float gama = determinant(vect1, vect2, vect3)/a;

	vect1._data[0] = _positions[0]._data[0] - _positions[1]._data[0];
	vect1._data[1] = _positions[0]._data[0] - _positions[2]._data[0];
	vect1._data[2] = _positions[0]._data[0] - ray.Origin()._data[0];

	vect2._data[0] = _positions[0]._data[1] - _positions[1]._data[1];
	vect2._data[1] = _positions[0]._data[1] - _positions[2]._data[1];
	vect2._data[2] = _positions[0]._data[1] - ray.Origin()._data[1];

	vect3._data[0] = _positions[0]._data[2] - _positions[1]._data[2];
	vect3._data[1] = _positions[0]._data[2] - _positions[2]._data[2];
	vect3._data[2] = _positions[0]._data[2] - ray.Origin()._data[2];
	float param = determinant(vect1, vect2, vect3)/a;
	
	if((beta + gama)>1.0f || gama<0.0f) {
		return false;
	}
	else if(param >0.001 && beta>0.0f){
		hitInfo.Parameter = param;
		hitInfo.Material = _materialId;
		hitInfo.Position._data[0] = ray.Origin()._data[0] + param*ray.Direction()._data[0];
		hitInfo.Position._data[1] = ray.Origin()._data[1] + param*ray.Direction()._data[1];
		hitInfo.Position._data[2] = ray.Origin()._data[2] + param*ray.Direction()._data[2];

		Vector3 ab;
		ab._data[0] = _positions[1]._data[0] - _positions[0]._data[0];
		ab._data[1] = _positions[1]._data[1] - _positions[0]._data[1];
		ab._data[2] = _positions[1]._data[2] - _positions[0]._data[2];

		Vector3 ac;
		ac._data[0] = _positions[2]._data[0] - _positions[0]._data[0];
		ac._data[1] = _positions[2]._data[1] - _positions[0]._data[1];
		ac._data[2] = _positions[2]._data[2] - _positions[0]._data[2];
		
		Vector3 n = crossProduct2(ab, ac);
		hitInfo.Normal._data[0]=n._data[0]/sqrt((n._data[0]*n._data[0])+ (n._data[1]*n._data[1])+(n._data[2]*n._data[2]));
		hitInfo.Normal._data[1]=n._data[1]/sqrt((n._data[0]*n._data[0])+ (n._data[1]*n._data[1])+(n._data[2]*n._data[2]));
		hitInfo.Normal._data[2]=n._data[2]/sqrt((n._data[0]*n._data[0])+ (n._data[1]*n._data[1])+(n._data[2]*n._data[2]));	
		return true;
	}
	else {
		return false;
	}
}