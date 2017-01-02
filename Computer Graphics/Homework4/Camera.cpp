#include "Camera.h"
#include "Scene.h"
#include <unistd.h>

Camera::Camera(const Vector3 &position, const Vector3 &up, const Vector3 &gaze, float left, float right, float bottom,
               float top, float near, float far, size_t horRes, size_t verRes)
{
    _position = position;
    _space.Up = up;
    _gaze     = gaze;

    _imagePlane.Bottom = bottom;
    _imagePlane.Right  = right;
    _imagePlane.Left   = left;
    _imagePlane.Top    = top;

    _imagePlane.Near = near;
    _imagePlane.Far = far;

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
    stream >> camera._imagePlane.Near;
    stream >> camera._imagePlane.Far;
    stream >> camera._imagePlane.Width;
    stream >> camera._imagePlane.Height;

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
