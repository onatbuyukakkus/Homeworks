#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

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

class Scene {

    std::vector<Vertex> _vertices;

    std::vector<Sphere> _spheres;
    std::vector<Mesh>   _meshes;
    vector<Camera> _cameras;    


    std::vector<Material> _materials;

    std::vector<PointLight> _lights;

    int _rayReflect;
    Color _background;
    Color _ambient;

public:
    const std::vector<Camera>& Cameras() const {
        return _cameras;
    }

    //////////////////////////////
    // READ SCENE FUNCTIONS HERE !
    //////////////////////////////

    Scene() {}

    void setRayReflect(int rayReflect) {
        _rayReflect = rayReflect;
    }

    int getRayReflect() {
        return _rayReflect;
    }

    void setBackground(float r, float g, float b) {
        Color* temp = new Color(r,g,b);
        _background = *temp;
        delete temp;
    }

    Color getBackground() {
        return _background;
    }

    void setAmbient(float r, float g, float b) {
        Color* temp = new Color(r,g,b);
        _ambient = *temp;
        delete temp;
    }

    Color getAmbient() {
        return _ambient;
    }

    void setPointLight(PointLight* light) {
        _lights.push_back(*light);
    }

    PointLight getPointLight(int index) {
        return _lights.at(index);
    }

    int lightsSize() {
        return _lights.size();
    }

    void setMaterial(Material* material) {
        _materials.push_back(*material);
    }

    Material getMaterial(int index) {
        return _materials.at(index);
    }

    int materialSize() {
        return _materials.size();
    }

    void setVertex(Vertex* vertex) {
        _vertices.push_back(*vertex);
    }

    Vertex getVertex(int index) {
        return _vertices.at(index);
    }

    int verticesSize() {
        return _vertices.size();
    }

    void setSphere(Sphere* sphere) {
        _spheres.push_back(*sphere);
    }

    Sphere getSphere(int index) {
        return _spheres.at(index);
    }

    int spheresSize() {
        return _spheres.size();
    }

    void setMesh(Mesh* mesh) {
        _meshes.push_back(*mesh);
    }

    Mesh getMesh(int index) {
        return _meshes.at(index);
    }

    int meshesSize() {
        return _meshes.size();
    }

    void setCameras(Camera *camera) {
        _cameras.push_back(*camera);
    }

    Camera getCamera(int index) {
        return _cameras.at(index);
    }

    int camerasSize() {
        return _cameras.size();
    }
};

extern Scene* CurrentScene;
void ReadScene(int argc, char** argv);


#endif //RAYTRACER_SCENE_H
