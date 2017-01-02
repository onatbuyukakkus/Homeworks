#include "Scene.h"
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

Vector3 rotation(float angle, Vector3 rotarter, Vector3 input) {

    float rotarterM[4][4];
    float inputM[4][1]{input.X(), input.Y(), input.Z(), 1.0};
    float resultM[4][1];

    for(int i=0; i<4; i++) {
    	rotarterM[i][3] = 0.0;
    	resultM[i][1] = 0.0;
    }

    for(int i=0; i<3; i++) {
    	rotarterM[3][i] = 0.0;
    }
    rotarterM[3][3] = 1.0;

    float length = sqrt(rotarter.X()*rotarter.X() + rotarter.Y() * rotarter.Y() + rotarter.Z() * rotarter.Z());
    float radianAngle = angle * M_PI / 180.0;
    float lSqrtSinAng = length * sin(radianAngle);

    float u2 = rotarter.X() * rotarter.X();
    float v2 = rotarter.Y() * rotarter.Y();
    float w2 = rotarter.Z() * rotarter.Z();

    float uv = rotarter.X() * rotarter.Y();
    float uw = rotarter.X() * rotarter.Z();
    float vw = rotarter.Y() * rotarter.Z();
 
    rotarterM[0][0] = (u2 + (v2 + w2) * cos(radianAngle)) / pow(length,2);
    rotarterM[0][1] = (uv * (1 - cos(radianAngle)) - rotarter.Z() * lSqrtSinAng) / pow(length,2);
    rotarterM[0][2] = (uw * (1 - cos(radianAngle)) + rotarter.Y() * lSqrtSinAng) / pow(length,2);
 
    rotarterM[1][0] = (uv * (1 - cos(radianAngle)) + rotarter.Z() * lSqrtSinAng) / pow(length,2);
    rotarterM[1][1] = (v2 + (u2 + w2) * cos(radianAngle)) / pow(length,2);
    rotarterM[1][2] = (vw * (1 - cos(radianAngle)) - rotarter.X() * lSqrtSinAng) / pow(length,2);
 
    rotarterM[2][0] = (uw * (1 - cos(radianAngle)) - rotarter.Y() * lSqrtSinAng) / pow(length,2);
    rotarterM[2][1] = (vw * (1 - cos(radianAngle)) + rotarter.X() * lSqrtSinAng) / pow(length,2);
    rotarterM[2][2] = (w2 + (u2 + v2) * cos(radianAngle)) / pow(length,2);
    

    for(int i = 0; i < 4; i++ ){
        for(int j = 0; j < 1; j++){
            resultM[i][j] = 0;
            for(int k = 0; k < 4; k++){
                resultM[i][j] += rotarterM[i][k] * inputM[k][j];
            }
        }
    }

    Vector3 output(resultM[0][0], resultM[1][0], resultM[2][0]);
    return output;    
} 

std::istream &operator>>(std::istream &stream, Scene &scene)
{
	//stream >> scene._rayReflect;
	stream >> scene._background;
	//stream >> scene._ambient;

	unsigned long tmpCount;
	unsigned long i;
	std::string dummy;
	/////////////////////
	Vector3 dummyVector;
	unsigned long j;
	unsigned long tmpCount2;
	unsigned long tmpCount3;
	/////////////////////

	/*stream >> tmpCount;
	scene._lights.resize(tmpCount);
	for (i = 0; i < tmpCount; ++i) {
		stream >> scene._lights[i];
	}*/

	std::vector<Color> vertexColors; 
	stream >> dummy;
	stream >> tmpCount;
	stream >> dummy;
	scene._vertices.resize(tmpCount);

	vertexColors.resize(tmpCount);
	for (i = 0; i < tmpCount; ++i) {
		stream >> vertexColors[i];
	}

	stream >> dummy;
	for (i = 0; i < tmpCount; ++i) {
		stream >> scene._vertices[i] >> std::ws;
		scene._vertices[i].setColor(vertexColors[i]);
	}

	stream >> dummy; //translations
	stream >> tmpCount;
	scene._translations.resize(tmpCount);
	for(i=0; i < tmpCount; ++i) {
		stream >> scene._translations[i];
	}

	stream >> dummy; //scalings
	stream >> tmpCount;
	scene._scalings.resize(tmpCount);
	for(i=0; i < tmpCount; ++i) {
		stream >> scene._scalings[i];
	}

	stream >> dummy; //rotations
	stream >> tmpCount;
	scene._rotations.resize(tmpCount);
	scene._rotationAngles.resize(tmpCount);
	for(i=0; i < tmpCount; ++i) {
		stream >> scene._rotationAngles[i];
		stream >> scene._rotations[i];
	}


	stream >> dummy; //models
	stream >> tmpCount;
	for(i=0; i < tmpCount; ++i) {
		int triangleId = 0;
		char transformationType;
		int transformationId;
		std::vector< tuple <char, int> > transformations;

		Model tmpMesh;
		std::vector<Triangle> triangles;
		stream >> tmpCount2; tmpMesh.SetId(tmpCount2);
		stream >> tmpCount2; tmpMesh.SetType(tmpCount2);
		stream >> tmpCount2;
		for(j=0; j < tmpCount2; ++j) {
			stream >> transformationType;
			stream >> transformationId;
			tuple <char, int> tmpTuple (transformationType, transformationId);
			transformations.push_back(tmpTuple);
		}

		stream >> tmpCount2;
		tmpMesh.SetTriCount(tmpCount2);
		for(j=0; j < tmpCount2; ++j) {
			int vertTemp1, vertTemp2, vertTemp3;
			stream >> vertTemp1 >> vertTemp2 >> vertTemp3;
			Vertex vert1, vert2, vert3;
			Vector3 transformVert1, transformVert2, transformVert3;
			vert1 = scene._vertices[vertTemp1-1];
			vert2 = scene._vertices[vertTemp2-1];
			vert3 = scene._vertices[vertTemp3-1];
			transformVert1 = vert1.Position();
			transformVert2 = vert2.Position();
			transformVert3 = vert3.Position();	

			for(int k=0; k<transformations.size(); k++) {
				if(get<0>(transformations[k]) == 'r') {
					// Vector3 writeTemp1=transformVert1;
					// Vector3 writeTemp2=transformVert2;
					// Vector3 writeTemp3=transformVert3;
					float rotationAngle = scene._rotationAngles[get<1>(transformations[k])-1];
					Vector3 rotatingVector = scene._rotations[get<1>(transformations[k])-1];
					transformVert1 = rotation(rotationAngle, rotatingVector, transformVert1);
					transformVert2 = rotation(rotationAngle, rotatingVector, transformVert2);
					transformVert3 = rotation(rotationAngle, rotatingVector, transformVert3);
					// cout << "After Rotation" << endl;
					// cout << writeTemp1 << "->" << transformVert1 << endl;
					// cout << writeTemp2 << "->" << transformVert2 << endl;
					// cout << writeTemp3 << "->" << transformVert3 << endl;
				}
				if(get<0>(transformations[k]) == 't') {
					// Vector3 writeTemp1=transformVert1;
					// Vector3 writeTemp2=transformVert2;
					// Vector3 writeTemp3=transformVert3;
					transformVert1 += scene._translations[get<1>(transformations[k])-1];
					transformVert2 += scene._translations[get<1>(transformations[k])-1];
					transformVert3 += scene._translations[get<1>(transformations[k])-1];
					// cout << "After Translation" << endl;
					// cout << writeTemp1 << "->" << transformVert1 << endl;
					// cout << writeTemp2 << "->" << transformVert2 << endl;
					// cout << writeTemp3 << "->" << transformVert3 << endl;
				}
				if(get<0>(transformations[k]) == 's') {
					// Vector3 writeTemp1=transformVert1;
					// Vector3 writeTemp2=transformVert2;
					// Vector3 writeTemp3=transformVert3;
					// Vector3 centerPoint = (transformVert1 + transformVert2 + transformVert3)/3;
					// transformVert1 -= centerPoint;
					// transformVert2 -= centerPoint;
					// transformVert3 -= centerPoint;

					Vector3 scale = scene._scalings[get<1>(transformations[k])-1];
					transformVert1 *= scale;
					transformVert2 *= scale;
					transformVert3 *= scale;
					
					// transformVert1 += centerPoint;
					// transformVert2 += centerPoint;
					// transformVert3 += centerPoint;
					// cout << "After Scaling" << endl;
					// cout << writeTemp1 << "->" << transformVert1 << endl;
					// cout << writeTemp2 << "->" << transformVert2 << endl;
					// cout << writeTemp3 << "->" << transformVert3 << endl;
				}
			}
			Vertex temp1(transformVert1);
			Vertex temp2(transformVert2);
			Vertex temp3(transformVert3);
			std::vector <Vertex> triVerts;
			triVerts.push_back(temp1);
			triVerts.push_back(temp2);
			triVerts.push_back(temp3);
			std:vector <Color> colors;
			colors.push_back(vert1.Colors());
			colors.push_back(vert2.Colors());
			colors.push_back(vert3.Colors());
			Triangle tempTri(triVerts, ++triangleId, colors);
			tempTri.calculateNormals();
			triangles.push_back(tempTri);
			scene._triangles.push_back(tempTri);
		}
	    tmpMesh.SetTris(triangles);
	    tmpMesh.SetScene(&scene);
		scene._meshes.push_back(tmpMesh);
	}



	/*cout << scene._background.R() << " " << scene._background.G() << " " << scene._background.B() << endl;
	for (int i=0; i<scene._vertices.size(); i++) {
		cout << scene._vertices[i].Colors().R() << " " <<  scene._vertices[i].Colors().G() << " " <<  scene._vertices[i].Colors().B() << endl;
	}
	for (int i=0; i<scene._vertices.size(); i++) {
		cout << scene._vertices[i].Position() << endl;
	}
	for (int i=0; i<scene._translations.size(); i++) {
		cout << scene._translations[i] << endl;
	}
	for (int i=0; i<scene._scalings.size(); i++) {
		cout << scene._scalings[i] << endl;
	}
	for (int i=0; i<scene._rotations.size(); i++) {
		cout << scene._rotationAngles[i] << scene._rotations[i] << endl;
	}
	for(int i=0; i<transformations.size(); i++) {
		cout << get<0>(transformations[i]) << " " << get<1>(transformations[i]) << endl;
	}
	for(int i=0; i<scene._meshes.size(); i++) {
		for(int j=0; j<scene._meshes[i].GetTris().size(); j++) {
			for(int k=0; k< scene._meshes[i].GetTris()[j]._vertices.size(); k++) {
				cout << scene._meshes[i].GetTris()[j]._vertices[k].Position() << " ";
			}
			cout << endl;
		}
	}*/

	return stream;
}

void Scene::AddCameras(std::istream &stream)
{
	std::string dummy;
	unsigned long camCount;
	stream >> camCount >> std::ws;

	_cameras.resize(camCount);
	for (unsigned long i = 0; i < camCount; ++i) {
		getline(stream, dummy);
		stream >> _cameras[i];
		_cameras[i].SetScene(this);
	}
}

Scene::Scene(const Scene& rhs)
{
	*this = rhs;
}

Scene& Scene::operator=(const Scene& rhs)
{
	_vertices = rhs._vertices;

	_cameras = rhs._cameras;
	_meshes = rhs._meshes;

	_rayReflect = rhs._rayReflect;
	_background = rhs._background;
	_ambient = rhs._ambient;

	for (auto& i : _cameras)
	{
		i.SetScene(this);
	}

	for (auto& i : _meshes)
	{
		i.SetScene(this);
	}

	return *this;
}