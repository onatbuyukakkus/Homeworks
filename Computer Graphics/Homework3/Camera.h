#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "Vector3.h"
#include "Image.h"
#include <vector>
using namespace std;

class Scene;

class Camera {
    struct {
        Vector3 Forward, Up, Left;
    } _space;

    struct {
        float Left, Right, Bottom, Top;

        size_t Width;
        size_t Height;

        float Near;
        float Far;

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
    //////////////////////////////
    Camera(const Vector3& position, const Vector3& up, const Vector3& gaze,
           float left, float right, float bottom, float top, float near, float far, size_t horRes, size_t verRes);
    /////////////////////////////
	Image Render() const;

    void SetScene(const Scene* scene);

    friend std::istream& operator>>(std::istream& stream, Camera& camera);

    const std::string& OutputFile() const
    {
        return _outputFile;
    }

    ////////////////////////////////
    float getNear() {
        return _imagePlane.Near;
    }
    float getFar() {
        return _imagePlane.Far;
    }
    std::vector< std::vector<float> > CameraTransformation() const;
    std::vector< std::vector<float> > PerspectiveTransformation() const;
    std::vector< std::vector<float> > ViewportTransformation() const;
    void Line(Vector3 v0, Vector3 v1, Image &output, Color color1, Color color2, float* zBuffer) const;
    ////////////////////////////////
};


#endif //RAYTRACER_CAMERA_H
