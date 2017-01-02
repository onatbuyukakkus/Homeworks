#include "Camera.h"
#include "Scene.h"
#include "Ray.h"
#include <cfloat>
#include <math.h>

/*Vector3 Camera::calculateDirection(int x, int y) {
	/*Vector3 m;
	m._data[0] = _position._data[0] + _gaze._data[0] * _imagePlane.Distance;
	m._data[1] = _position._data[1] + _gaze._data[1] * _imagePlane.Distance;
	m._data[2] = _position._data[2] + _gaze._data[2] * _imagePlane.Distance;
	Vector3 direction;
	float s_u = _imagePlane.Left + ((_imagePlane.Right-_imagePlane.Left)*(y+0.5)/_imagePlane.Width);
	float s_v = _imagePlane.Bottom + ((_imagePlane.Top-_imagePlane.Bottom)*(x+0.5)/_imagePlane.Height);

	direction._data[0] = s_u*_space.Left._data[0] + s_v*_space.Up._data[0] + _gaze._data[0]*_imagePlane.Distance;
	direction._data[1] = s_u*_space.Left._data[1] + s_v*_space.Up._data[1] + _gaze._data[1]*_imagePlane.Distance;
	direction._data[2] = s_u*_space.Left._data[2] + s_v*_space.Up._data[2] + _gaze._data[2]*_imagePlane.Distance;

	return direction;
}*/

Image Camera::Render() const {

	Image img(_imagePlane.Width, _imagePlane.Height, CurrentScene->getBackground());

	for(int i=0; i<_imagePlane.Height; i++) {
		for(int j=0; j<_imagePlane.Width; j++) {
			float t_max = FLT_MAX;
			Vector3 direction;
			Vector3 m;
			m._data[0] = _position._data[0] - _space.Forward._data[0]*_imagePlane.Distance;
			m._data[1] = _position._data[1] - _space.Forward._data[1]*_imagePlane.Distance;
			m._data[2] = _position._data[2] - _space.Forward._data[2]*_imagePlane.Distance;
			Vector3 q;
			q._data[0] = m._data[0] + _imagePlane.Left*_space.Left._data[0] + _imagePlane.Top*_space.Up._data[0];
			q._data[1] = m._data[1] + _imagePlane.Left*_space.Left._data[1] + _imagePlane.Top*_space.Up._data[1];
			q._data[2] = m._data[2] + _imagePlane.Left*_space.Left._data[2] + _imagePlane.Top*_space.Up._data[2];

			float s_u = ((_imagePlane.Right-_imagePlane.Left)*(j+0.5))/_imagePlane.Width;
			float s_v = ((_imagePlane.Top-_imagePlane.Bottom)*(i+0.5))/_imagePlane.Height;

			Vector3 s;
			s._data[0] = q._data[0] + s_u*_space.Left._data[0] - s_v*_space.Up._data[0];
			s._data[1] = q._data[1] + s_u*_space.Left._data[1] - s_v*_space.Up._data[1];
			s._data[2] = q._data[2] + s_u*_space.Left._data[2] - s_v*_space.Up._data[2];

			direction._data[0] = s._data[0] - _position._data[0];
			direction._data[1] = s._data[1] - _position._data[1];
			direction._data[2] = s._data[2] - _position._data[2];

			Ray currentRay(_position, direction);
			RayHitInfo saveInfo;
			int spheresSize = CurrentScene->spheresSize();
			int meshesSize = CurrentScene->meshesSize();

			RayHitInfo rayHit;
			for(int k=0; k<spheresSize; k++) {
				if((CurrentScene->getSphere(k).Intersect(currentRay, rayHit))==true) {
					if(rayHit.Parameter < t_max) {
						t_max=rayHit.Parameter;
						saveInfo = rayHit;
					}
				}
			}

			for(int l=0; l<meshesSize; l++) {
				Mesh currentMesh = CurrentScene->getMesh(l);
				int size = currentMesh._triangles.size();
				for(int m=0; m<size; m++) {
					if((currentMesh._triangles[m].Intersect(currentRay, rayHit))==true) {
						if(rayHit.Parameter < t_max) {
							t_max=rayHit.Parameter;
							saveInfo=rayHit;
						}
					}
				}
			}
			if(t_max != FLT_MAX){
				Material currentMaterial=CurrentScene->getMaterial(saveInfo.Material-1);
				Color result;
				result = currentMaterial.calculateColor(saveInfo.Normal, saveInfo.Position, _position, 0);
				//cout << result.R() << " " << result.G() << " " << result.B() << endl;
				img.Pixel(i,j) = result;
			}
		}
	}
	return img;
}
