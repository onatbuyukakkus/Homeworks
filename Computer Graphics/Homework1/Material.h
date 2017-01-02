#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "Color.h"
#include "Vector3.h"

class Scene;

class Material {
    //////////////////
    /// PUT YOUR VARIABLES, HELPER FUNCTIONS HERE !
    //////////////////
    int _id;
    Color _ambient;
    Color _diffuse;
    Color _specular;
    int _specularSpecExp;
    Color _reflectance;

public:
    Material() {}

    void setID(int id) {
    	_id = id;
    }

    int getID() {
    	return _id;
    }

    void setAmbient(float r, float g, float b) {
    	Color* temp = new Color(r,g,b);
        _ambient = *temp;
        delete temp;
    }

    Color getAmbient() {
    	return _ambient;
    }

    void setDiffuse(float r, float g, float b) {
    	Color* temp = new Color(r,g,b);
        _diffuse = *temp;
        delete temp;
    }

    Color getDiffuse() {
    	return _diffuse;
    }

    void setSpecular(float r, float g, float b, int specExp) {
    	Color* temp = new Color(r,g,b);
        _specular = *temp;
        delete temp;
        _specularSpecExp = specExp;
    }

    Color getSpecular() {
    	return _specular;
    }

    int getSpecularSpecExp() {
    	return _specularSpecExp;
    }

    void setReflectance(float r, float g, float b) {
    	Color* temp = new Color(r,g,b);
        _reflectance = *temp;
        delete temp;
    }

    Color getReflectance() {
    	return _reflectance;
    }



    /*
     * Implement a Calculate function that does Diffuse, Specular and Ambient, Reflective shading
     */
    Color calculateColor(Vector3 rayHitNormal, Vector3 rayHitPosition, Vector3 position, int reflectionCounter);

    Color calculateAmbient();

    friend std::istream& operator>>(std::istream& stream, Material& mat);
};

using MaterialId = int;

#endif //RAYTRACER_MATERIAL_H
