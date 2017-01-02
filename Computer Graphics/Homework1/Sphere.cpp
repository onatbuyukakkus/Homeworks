#include "Sphere.h"
#include <math.h>
using namespace std;

float dotProduct(Vector3 vect1, Vector3 vect2) {
	return vect1._data[0]*vect2._data[0]+vect1._data[1]*vect2._data[1]+vect1._data[2]*vect2._data[2];
}

bool Sphere::Intersect(const Ray& ray, RayHitInfo& hitInfo) const {
	Vector3 posMinusCenter;
	posMinusCenter._data[0]=ray.Origin()._data[0] - _center._data[0];
	posMinusCenter._data[1]=ray.Origin()._data[1] - _center._data[1];
	posMinusCenter._data[2]=ray.Origin()._data[2] - _center._data[2];

	Vector3 minusDirection;
	minusDirection._data[0]=-1*ray.Direction()._data[0];
	minusDirection._data[1]=-1*ray.Direction()._data[1];
	minusDirection._data[2]=-1*ray.Direction()._data[2];

	float param1= (dotProduct(minusDirection,posMinusCenter) + sqrt((dotProduct(ray.Direction(),posMinusCenter)*dotProduct(ray.Direction(),posMinusCenter)) - (dotProduct(ray.Direction(),ray.Direction())*(dotProduct(posMinusCenter,posMinusCenter)-(_radius*_radius)))))/dotProduct(ray.Direction(),ray.Direction());
	float param2= (dotProduct(minusDirection,posMinusCenter) - sqrt((dotProduct(ray.Direction(),posMinusCenter)*dotProduct(ray.Direction(),posMinusCenter)) - (dotProduct(ray.Direction(),ray.Direction())*(dotProduct(posMinusCenter,posMinusCenter)-(_radius*_radius)))))/dotProduct(ray.Direction(),ray.Direction());

	if(param1>=0.0f && param1<=param2) {
		hitInfo.Parameter = param1;
		hitInfo.Material = _materialId;
		hitInfo.Position._data[0] = ray.Origin()._data[0] + param1*ray.Direction()._data[0];
		hitInfo.Position._data[1] = ray.Origin()._data[1] + param1*ray.Direction()._data[1];
		hitInfo.Position._data[2] = ray.Origin()._data[2] + param1*ray.Direction()._data[2];

		hitInfo.Normal._data[0] = (hitInfo.Position._data[0] - _center._data[0])/_radius;
		hitInfo.Normal._data[1] = (hitInfo.Position._data[1] - _center._data[1])/_radius;
		hitInfo.Normal._data[2] = (hitInfo.Position._data[2] - _center._data[2])/_radius;
		return true;
	}

	else if(param2>=0.0f && param1>param2) {
		hitInfo.Parameter = param2;
		hitInfo.Material = _materialId;
		hitInfo.Position._data[0] = ray.Origin()._data[0] + param2*ray.Direction()._data[0];
		hitInfo.Position._data[1] = ray.Origin()._data[1] + param2*ray.Direction()._data[1];
		hitInfo.Position._data[2] = ray.Origin()._data[2] + param2*ray.Direction()._data[2];

		hitInfo.Normal._data[0] = (hitInfo.Position._data[0] - _center._data[0])/_radius;
		hitInfo.Normal._data[1] = (hitInfo.Position._data[1] - _center._data[1])/_radius;
		hitInfo.Normal._data[2] = (hitInfo.Position._data[2] - _center._data[2])/_radius;
		return true;
	}

	else {
		return false;
	}	
}