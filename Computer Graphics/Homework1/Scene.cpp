#include "Scene.h"

Scene* CurrentScene = new Scene;

Vector3 crossProduct(Vector3 vect1, Vector3 vect2) {
    Vector3 result;
    result._data[0] = vect1._data[1]*vect2._data[2] - vect1._data[2]*vect2._data[1];
    result._data[1] = vect1._data[2]*vect2._data[0] - vect1._data[0]*vect2._data[2];
    result._data[2] = vect1._data[0]*vect2._data[1] - vect1._data[1]*vect2._data[0];
    return result;
}

void ReadScene(int argc, char** argv) {
    /*
     * Reads the scene and cameras from arguments
     * Then sets the CurrentScene pointer
     */
    
    string sceneFile = argv[1];
    string cameraFile = argv[2];
    int intTemp0;
    int intTemp;
    int intTemp2;
    int intTemp3;
    float floatTemp;
    float floatTemp2;
    string stringTemp;
    vector <int> intTempVector;
    vector <float> floatTempVector;
    vector <float> floatTempVector2;

    ifstream stream;
    stream.open(sceneFile);
    stream >> intTemp; CurrentScene->setRayReflect(intTemp);

    stream >> floatTemp; floatTempVector.push_back(floatTemp);
    stream >> floatTemp; floatTempVector.push_back(floatTemp);
    stream >> floatTemp; floatTempVector.push_back(floatTemp);
    CurrentScene->setBackground(floatTempVector[0], floatTempVector[1], floatTempVector[2]);
    floatTempVector.clear();

    stream >> floatTemp; floatTempVector.push_back(floatTemp);
    stream >> floatTemp; floatTempVector.push_back(floatTemp);
    stream >> floatTemp; floatTempVector.push_back(floatTemp);
    CurrentScene->setAmbient(floatTempVector[0], floatTempVector[1], floatTempVector[2]);
    floatTempVector.clear();

    stream >> intTemp;
    for(int i=0; i<intTemp; i++) {
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> floatTemp; floatTempVector2.push_back(floatTemp);
        stream >> floatTemp; floatTempVector2.push_back(floatTemp); 
        stream >> floatTemp; floatTempVector2.push_back(floatTemp);
        PointLight* currentPoingtLight = new PointLight(floatTempVector[0], floatTempVector[1], floatTempVector[2], floatTempVector2[0], floatTempVector2[1], floatTempVector2[2]);
        CurrentScene->setPointLight(currentPoingtLight);
        floatTempVector.clear();
        floatTempVector2.clear();
    }

    stream >> intTemp;
    for(int i=0; i<intTemp; i++) {
        Material* currentMaterial = new Material();
        stream >> stringTemp;
        stream >> intTemp2; currentMaterial->setID(intTemp2);
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        currentMaterial->setAmbient(floatTempVector[0], floatTempVector[1], floatTempVector[2]);
        floatTempVector.clear();
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        currentMaterial->setDiffuse(floatTempVector[0], floatTempVector[1], floatTempVector[2]);
        floatTempVector.clear();
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> intTemp2;
        currentMaterial->setSpecular(floatTempVector[0], floatTempVector[1], floatTempVector[2], intTemp2);
        floatTempVector.clear();        
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        stream >> floatTemp; floatTempVector.push_back(floatTemp);
        currentMaterial->setReflectance(floatTempVector[0], floatTempVector[1], floatTempVector[2]);
        floatTempVector.clear();
        CurrentScene->setMaterial(currentMaterial);
    }

    stream >> intTemp;
    stream >> stringTemp;
    stream >> stringTemp;
    for(int i=0; i<intTemp; i++) {
        Vector3 tempVector3;
        stream >> floatTemp; tempVector3._data[0]=floatTemp;
        stream >> floatTemp; tempVector3._data[1]=floatTemp;
        stream >> floatTemp; tempVector3._data[2]=floatTemp;
        Vertex* currentVertex = new Vertex(tempVector3);
        CurrentScene->setVertex(currentVertex);
    }

    stream >> intTemp0;
    for(int i=0; i<intTemp0; i++) {
        stream >> stringTemp;
        if(stringTemp == "#Mesh") {
            stream >> intTemp; //mesh id
            stream >> intTemp2; //triangle count
            stream >> intTemp3; //material id
            Mesh* currentMesh = new Mesh(intTemp, intTemp2, intTemp3);
            for(int j=0; j<intTemp2; j++) {
                Triangle currentTriangle;
                currentTriangle._materialId = intTemp3;
                Vector3 vect;
                stream >> intTemp;
                vect._data[0] = CurrentScene->getVertex(intTemp-1).Position()._data[0];
                vect._data[1] = CurrentScene->getVertex(intTemp-1).Position()._data[1];
                vect._data[2] = CurrentScene->getVertex(intTemp-1).Position()._data[2];
                currentTriangle._positions.push_back(vect);
                stream >> intTemp;
                vect._data[0] = CurrentScene->getVertex(intTemp-1).Position()._data[0];
                vect._data[1] = CurrentScene->getVertex(intTemp-1).Position()._data[1];
                vect._data[2] = CurrentScene->getVertex(intTemp-1).Position()._data[2];
                currentTriangle._positions.push_back(vect);
                stream >> intTemp;
                vect._data[0] = CurrentScene->getVertex(intTemp-1).Position()._data[0];
                vect._data[1] = CurrentScene->getVertex(intTemp-1).Position()._data[1];
                vect._data[2] = CurrentScene->getVertex(intTemp-1).Position()._data[2];
                currentTriangle._positions.push_back(vect);
                currentMesh->addTriangle(currentTriangle);
            }
            CurrentScene->setMesh(currentMesh);
        }
        if(stringTemp == "#Sphere") {
            stream >> intTemp; //sphere id
            stream >> intTemp2; //material id
            stream >> floatTemp; //radius
            stream >> intTemp3; //center
            Vector3 center;
            center._data[0]=CurrentScene->getVertex(intTemp3-1).Position()._data[0];
            center._data[1]=CurrentScene->getVertex(intTemp3-1).Position()._data[1];
            center._data[2]=CurrentScene->getVertex(intTemp3-1).Position()._data[2];
            Sphere* currentSphere = new Sphere(intTemp, intTemp2, floatTemp, center);
            CurrentScene->setSphere(currentSphere);
        }
    }

    stream.close();
    stream.open(cameraFile);

    stream >> intTemp;
    for(int i=0; i<intTemp; i++) {
        Camera* currentCamera = new Camera();
        stream >> stringTemp;
        stream >> intTemp2; currentCamera->setId(intTemp2); //camera id
        Vector3 tempVector3;
        Vector3 tempVector3_1;
        Vector3 tempVector3_2;
        Vector3 tempVector3_3;
        Vector3 tempVector3_4;

        stream >> floatTemp; tempVector3._data[0]=floatTemp;
        stream >> floatTemp; tempVector3._data[1]=floatTemp;
        stream >> floatTemp; tempVector3._data[2]=floatTemp; //position
        currentCamera->setPosition(tempVector3);
        stream >> floatTemp; tempVector3_1._data[0]=floatTemp;
        stream >> floatTemp; tempVector3_1._data[1]=floatTemp;
        stream >> floatTemp; tempVector3_1._data[2]=floatTemp; //gaze
        currentCamera->setGaze(tempVector3_1);
        stream >> floatTemp; tempVector3_2._data[0]=floatTemp;
        stream >> floatTemp; tempVector3_2._data[1]=floatTemp;
        stream >> floatTemp; tempVector3_2._data[2]=floatTemp; //up

        tempVector3_3._data[0]=-1*tempVector3_1._data[0];
        tempVector3_3._data[1]=-1*tempVector3_1._data[1];
        tempVector3_3._data[2]=-1*tempVector3_1._data[2]; //forward

        tempVector3_4._data[0]=crossProduct(tempVector3_2, tempVector3_3)._data[0];
        tempVector3_4._data[1]=crossProduct(tempVector3_2, tempVector3_3)._data[1];
        tempVector3_4._data[2]=crossProduct(tempVector3_2, tempVector3_3)._data[2]; //left
        currentCamera->setSpace(tempVector3_3, tempVector3_2, tempVector3_4);

        stream >> floatTemp; floatTempVector.push_back(floatTemp); //left
        stream >> floatTemp; floatTempVector.push_back(floatTemp); //right
        stream >> floatTemp; floatTempVector.push_back(floatTemp); //bottom
        stream >> floatTemp; floatTempVector.push_back(floatTemp); //top
        stream >> floatTemp; floatTempVector.push_back(floatTemp); //distance
        stream >> floatTemp; floatTempVector.push_back(floatTemp); //horres
        stream >> floatTemp; floatTempVector.push_back(floatTemp); //verres
        currentCamera->setImagePlane(floatTempVector[0], floatTempVector[1], floatTempVector[2], floatTempVector[3], floatTempVector[4], floatTempVector[5], floatTempVector[6]);
        floatTempVector.clear();

        stream >> stringTemp; //outputfile
        currentCamera->setOutputFile(stringTemp);
        CurrentScene->setCameras(currentCamera);
    }
    stream.close();

    
    /*for(int i=0; i<CurrentScene->materialSize(); i++) {
        cout << "ambient r " << CurrentScene->getMaterial(i).getAmbient().R() << endl;
        cout << "ambient g " << CurrentScene->getMaterial(i).getAmbient().G() << endl;
        cout << "ambient b " << CurrentScene->getMaterial(i).getAmbient().B() << endl;
        cout << "diffuse r " << CurrentScene->getMaterial(i).getDiffuse().R() << endl;
        cout << "diffuse g " << CurrentScene->getMaterial(i).getDiffuse().G() << endl;
        cout << "diffuse b " << CurrentScene->getMaterial(i).getDiffuse().B() << endl;
        cout << "specular r " << CurrentScene->getMaterial(i).getSpecular().R() << endl;
        cout << "specular g " << CurrentScene->getMaterial(i).getSpecular().G() << endl;
        cout << "specular b " << CurrentScene->getMaterial(i).getSpecular().B() << endl;
        cout << "specular exp " << CurrentScene->getMaterial(i).getSpecularSpecExp() << endl;
        cout << "reflectance r " << CurrentScene->getMaterial(i).getReflectance().R() << endl;
        cout << "reflectance g " << CurrentScene->getMaterial(i).getReflectance().G() << endl;
        cout << "reflectance b " << CurrentScene->getMaterial(i).getReflectance().B() << endl;
    }

    for(int i=0; i<CurrentScene->verticesSize(); i++) {
        cout << "x " << CurrentScene->getVertex(i).Position()._data[0] << endl;
        cout << "y " << CurrentScene->getVertex(i).Position()._data[1] << endl;
        cout << "z " << CurrentScene->getVertex(i).Position()._data[2] << endl;

    }

    for(int i=0; i<CurrentScene->meshesSize(); i++) {
        cout << "mesh id " << CurrentScene->getMesh(i)._id << endl;
        cout << "triangle count " << CurrentScene->getMesh(i)._triangleCount << endl;
        cout << "material id " << CurrentScene->getMesh(i)._materialId << endl;
        for(int j=0; j<CurrentScene->getMesh(i)._triangles.size(); j++) {
            cout << CurrentScene->getMesh(i)._triangles[j]._positions[0]._data[0] << " " <<
                                CurrentScene->getMesh(i)._triangles[j]._positions[0]._data[1] << " " <<
                                                CurrentScene->getMesh(i)._triangles[j]._positions[0]._data[2] << endl;

            cout << CurrentScene->getMesh(i)._triangles[j]._positions[1]._data[0] << " " <<
                                CurrentScene->getMesh(i)._triangles[j]._positions[1]._data[1] << " " <<
                                                CurrentScene->getMesh(i)._triangles[j]._positions[1]._data[2] << endl;

            cout << CurrentScene->getMesh(i)._triangles[j]._positions[2]._data[0] << " " <<
                                CurrentScene->getMesh(i)._triangles[j]._positions[2]._data[1] << " " <<
                                                CurrentScene->getMesh(i)._triangles[j]._positions[2]._data[2] << endl;
        }  
    }

    for(int i=0; i<CurrentScene->spheresSize(); i++) {
        cout << "sphere id " << CurrentScene->getSphere(i)._id << endl;
        cout << "material id " << CurrentScene->getSphere(i)._materialId << endl;
        cout << "radius " << CurrentScene->getSphere(i)._radius << endl;
        cout << "center " << CurrentScene->getSphere(i)._center << endl;
    }

    for(int i=0; i<CurrentScene->camerasSize(); i++) {
        cout << "cid " << CurrentScene->getCamera(i).getId() << endl;
        cout << "space forward X" << CurrentScene->getCamera(i).getSpaceForward()._data[0] << endl;
        cout << "space forward Y" << CurrentScene->getCamera(i).getSpaceForward()._data[1] << endl;
        cout << "space forward Z" << CurrentScene->getCamera(i).getSpaceForward()._data[2] << endl;
        cout << "space up X" << CurrentScene->getCamera(i).getSpaceUp()._data[0] << endl;
        cout << "space up Y" << CurrentScene->getCamera(i).getSpaceUp()._data[1] << endl;
        cout << "space up Z" << CurrentScene->getCamera(i).getSpaceUp()._data[2] << endl;
        cout << "space left X" << CurrentScene->getCamera(i).getSpaceLeft()._data[0] << endl;
        cout << "space left Y" << CurrentScene->getCamera(i).getSpaceLeft()._data[1] << endl;
        cout << "space left Z" << CurrentScene->getCamera(i).getSpaceLeft()._data[2] << endl;
        cout << "image plane left " << CurrentScene->getCamera(i).getImagePlaneLeft() << endl;
        cout << "image plane right " << CurrentScene->getCamera(i).getImagePlaneRight() << endl;
        cout << "image plane bottom " << CurrentScene->getCamera(i).getImagePlaneBottom() << endl;
        cout << "image plane top " << CurrentScene->getCamera(i).getImagePlaneTop() << endl;
        cout << "image plane distance " << CurrentScene->getCamera(i).getImagePlaneDistance() << endl;
        cout << "image plane width " << CurrentScene->getCamera(i).getImagePlaneWidth() << endl;
        cout << "image plane height " << CurrentScene->getCamera(i).getImagePlaneHeight() << endl;
        cout << "output " << CurrentScene->getCamera(i).getOutputFile() << endl;
    }*/
}
        
