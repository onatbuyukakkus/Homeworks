#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "Vector3.h"
#include "Image.h"
using namespace std;

class Camera {
    struct {
        Vector3 Forward, Up, Left;
    } _space;

    struct {
        float Left, Right, Bottom, Top;
        float Distance;

        int Width;
        int Height;

    } _imagePlane;

    Vector3 _position;
    Vector3 _gaze;

    std::string _outputFile;

    int _id;

public:

    /*
     * BEWARE! You should render each camera by using this function, we will grade it according to regulations!
     */
    Image Render() const;

    //Vector3 calculateDirection(int, int);

    Camera() {}

    void setId(int id) {
        _id=id;
    }

    int getId() {
        return _id;
    }

    void setSpace(Vector3 forward, Vector3 up, Vector3 left) {
        _space.Forward=forward;
        _space.Up=up;
        _space.Left=left;
    }

    Vector3 getSpaceForward() {
        return _space.Forward;
    }

    Vector3 getSpaceUp() {
        return _space.Up;
    }

    Vector3 getSpaceLeft() {
        return _space.Left;
    }

    void setImagePlane(float left, float right, float bottom, float top, float distance, int width, int height) {
        _imagePlane.Left=left;
        _imagePlane.Right=right;
        _imagePlane.Bottom=bottom;
        _imagePlane.Top=top;
        _imagePlane.Distance=distance;
        _imagePlane.Width=width;
        _imagePlane.Height=height;
    }

    float getImagePlaneLeft() {
        return _imagePlane.Left;
    }

    float getImagePlaneRight() {
        return _imagePlane.Right;
    }

    float getImagePlaneBottom() {
        return _imagePlane.Bottom;
    }

    float getImagePlaneTop() {
        return _imagePlane.Top;
    }

    float getImagePlaneDistance() {
        return _imagePlane.Distance;
    }

    float getImagePlaneWidth() {
        return _imagePlane.Width;
    }

    float getImagePlaneHeight() {
        return _imagePlane.Height;
    }

    void setPosition(Vector3 position) {
        _position=position;
    }

    Vector3 getPosition() {
        return _position;
    }

    void setGaze(Vector3 gaze) {
        _gaze=gaze;
    }

    Vector3 getGaze() {
        return _gaze;
    }

    void setOutputFile(string outputFile) {
        _outputFile = outputFile;
    }

    string getOutputFile() {
        return _outputFile;
    }

    const std::string& OutputFile() const
    {
        return _outputFile;
    }
};

#endif //RAYTRACER_CAMERA_H
