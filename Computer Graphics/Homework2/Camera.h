#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "Vector3.h"
#include "Image.h"

class Scene;

class Camera {
    struct {
        Vector3 Forward, Up, Left;
    } _space;

    struct {
        float Left, Right, Bottom, Top;
        float Distance;

        size_t Width;
        size_t Height;

    } _imagePlane;

	struct
	{
		Vector3 TopLeft;
		
		Vector3 OneRight;
		Vector3 OneDown;
		Vector3 NextRow;
	} _renderInfo;

    Vector3 _position;
    Vector3 _gaze;

    const Scene* _scene;

    std::string _outputFile;

    void init();

public:

    Camera() = default;
    Camera(const Vector3& position, const Vector3& up, const Vector3& gaze,
           float left, float right, float bottom, float top, float dist, size_t horRes, size_t verRes);

	Image Render() const;

    void SetScene(const Scene* scene);

    friend std::istream& operator>>(std::istream& stream, Camera& camera);

    const std::string& OutputFile() const
    {
        return _outputFile;
    }
};


#endif //RAYTRACER_CAMERA_H
