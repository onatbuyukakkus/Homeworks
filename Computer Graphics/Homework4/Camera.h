#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "Vector3.h"
#include "Image.h"

class Scene;

class Camera {
    public:
        struct {
            Vector3 Forward, Up, Left;
        } _space;

        struct {
            float Left, Right, Bottom, Top;
            float Distance;

            float Near;
            float Far;
            
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

        
        Vector3 _gaze;

        const Scene* _scene;

        void init();

        Vector3 _position;
        Camera() = default;
        Camera(const Vector3 &position, const Vector3 &up, const Vector3 &gaze, float left, float right, float bottom,
                   float top, float near, float far, size_t horRes, size_t verRes);

        void SetScene(const Scene* scene);

        void SetGaze(Vector3 gaze) {
            _gaze = gaze;
        }

        friend std::istream& operator>>(std::istream& stream, Camera& camera);
};


#endif //RAYTRACER_CAMERA_H
