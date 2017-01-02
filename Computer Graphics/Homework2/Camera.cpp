#include "Camera.h"
#include "Scene.h"
#include <unistd.h>

Camera::Camera(const Vector3 &position, const Vector3 &up, const Vector3 &gaze, float left, float right, float bottom,
               float top, float dist, size_t horRes, size_t verRes)
{
    _position = position;
    _space.Up = up;
    _gaze     = gaze;

    _imagePlane.Bottom = bottom;
    _imagePlane.Right  = right;
    _imagePlane.Left   = left;
    _imagePlane.Top    = top;

    _imagePlane.Distance = dist;
    _imagePlane.Height   = verRes;
    _imagePlane.Width    = horRes;

    init();
}


std::istream &operator>>(std::istream &stream, Camera &camera)
{
    stream >> camera._position;
    stream >> camera._gaze;
    stream >> camera._space.Up;

    stream >> camera._imagePlane.Left;
    stream >> camera._imagePlane.Right;
    stream >> camera._imagePlane.Bottom;
    stream >> camera._imagePlane.Top;

    stream >> camera._imagePlane.Distance;
    stream >> camera._imagePlane.Width;
    stream >> camera._imagePlane.Height;

    stream >> camera._outputFile >> std::ws;

    camera.init();

    return stream;
}

void Camera::init()
{
    _space.Forward = -_gaze.Normalized();
	_space.Up.Normalize();
    _space.Left = Vector3::Cross(_space.Up, _space.Forward);
    _space.Left.Normalize();

    _space.Up = Vector3::Cross(_space.Forward, _space.Left);
    _space.Up.Normalize();

	_renderInfo.TopLeft = _position + (_space.Forward * -_imagePlane.Distance)
									+ (_space.Left * _imagePlane.Left) 
									+ (_space.Up * _imagePlane.Top);

	float pixelWidth = (_imagePlane.Right - _imagePlane.Left) / _imagePlane.Width;
	float pixelHeight = (_imagePlane.Top - _imagePlane.Bottom) / _imagePlane.Height;

	_renderInfo.OneRight = pixelWidth * _space.Left;
	_renderInfo.OneDown = -pixelHeight * _space.Up;
	Vector3 fullRow = _renderInfo.OneRight * -static_cast<int>(_imagePlane.Width);
	_renderInfo.NextRow = _renderInfo.OneDown + fullRow;
}

void Camera::SetScene(const Scene *scene)
{
    _scene = scene;
}

Image Camera::Render() const
{
    Image output(_imagePlane.Width, _imagePlane.Height);

	std::deque<const Triangle*> hitCache;

	RayHitInfo hitInfo;
	Vector3 worldPosition;
	Vector3 rowBegin = _renderInfo.TopLeft + (_renderInfo.OneRight + _renderInfo.OneDown) / 2;

	Ray rayEquation(_position, Vector3::Zero);

	for (size_t i = 0; i < _imagePlane.Height; i ++){
		worldPosition = rowBegin + (i * _renderInfo.OneDown);

		for (size_t j = 0; j < _imagePlane.Width; j++){
			rayEquation.Direction((worldPosition - _position).Normalized());

			if (_scene->FastRaycast(rayEquation, hitInfo, hitCache)){
				output.Pixel(i, j) =
                        /////////////////////////////////////////////////
						_scene->GetMaterial(hitInfo.Material).Calculate(hitInfo.Normal, hitInfo.Position, - rayEquation.Direction(), _scene, _scene->ReflectionCount(), hitInfo.SphereId, hitInfo.TriangleId, hitInfo.Beta, hitInfo.Gamma);
			             /////////////////////////////////////////////////
            }
			else
			{
				output.Pixel(i, j) = _scene->BackgroundColor();
			}

			worldPosition += _renderInfo.OneRight;
		}
	}

    return output;
}
