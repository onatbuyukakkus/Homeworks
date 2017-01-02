#include "Scene.h"
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

Vector3 triNormal(Vertex vert1, Vertex vert2, Vertex vert3) {
	Vector3 normal = Vector3::Cross(
	            vert2.Position() - vert1.Position(),
	            vert3.Position() - vert1.Position()
		    );
	Vector3 unitNormal = normal.Normalized();
	return unitNormal;
}


std::istream &operator>>(std::istream &stream, Scene &scene)
{
	stream >> scene._background;
	stream >> scene._ambient;

	int tmpCount;
	unsigned long i;
	char dummy;
	/////////////////////
	Vector3 dummyVector;
	unsigned long j;
	int tmpCount2;
	/////////////////////

	stream >> tmpCount;
	scene._lights.resize(tmpCount);
	for (i = 0; i < tmpCount; ++i) {
		stream >> dummy; //#
		stream >> dummy; //l
		stream >> dummy; //i
		stream >> dummy; //g
		stream >> dummy; //h
		stream >> dummy; //t
		stream >> tmpCount2;

		stream >> scene._lights[i];
	}

	stream >> tmpCount;
	for (i = 0; i < tmpCount; ++i) {
		stream >> dummy; //#
		stream >> dummy; //m
		stream >> dummy; //a
		stream >> dummy; //t
		stream >> dummy; //e
		stream >> dummy; //r
		stream >> dummy; //i
		stream >> dummy; //a
		stream >> dummy; //l
		stream >> tmpCount2;

		Material mat;
		stream >> mat._ambient;
    	stream >> mat._diffuse;
    	stream >> mat._specular;
    	stream >> mat._phong;
    	scene._materials.push_back(mat);
	}

	/////////////////
	stream >> dummy; //#
	stream >> dummy; //t
	stream >> dummy; //r
	stream >> dummy; //a
	stream >> dummy; //n
	stream >> dummy; //s
	stream >> dummy; //l
	stream >> dummy; //a
	stream >> dummy; //t
	stream >> dummy; //i
	stream >> dummy; //o
	stream >> dummy; //n
	stream >> dummy; //s
	
	stream >> tmpCount;
	scene._translations.resize(tmpCount);
	for(i=0; i < tmpCount; ++i) {
		stream >> scene._translations[i];
	}

	stream >> dummy; //#
	stream >> dummy; //s
	stream >> dummy; //c
	stream >> dummy; //a
	stream >> dummy; //l
	stream >> dummy; //i
	stream >> dummy; //n
	stream >> dummy; //g 
	stream >> dummy; //s

	stream >> tmpCount;
	scene._scalings.resize(tmpCount);
	for(i=0; i < tmpCount; ++i) {
		stream >> scene._scalings[i];
	}

	stream >> dummy; //#
	stream >> dummy; //r
	stream >> dummy; //o
	stream >> dummy; //t
	stream >> dummy; //a
	stream >> dummy; //t
	stream >> dummy; //i
	stream >> dummy; //o
	stream >> dummy; //n
	stream >> dummy; //s

	stream >> tmpCount;
	scene._rotations.resize(tmpCount);
	scene._rotationAngles.resize(tmpCount);
	for(i=0; i < tmpCount; ++i) {
		stream >> scene._rotationAngles[i];
		stream >> scene._rotations[i];
	}

	stream >> tmpCount;
	stream >> dummy; //#
	stream >> dummy; //v
	stream >> dummy; //e
	stream >> dummy; //r
	stream >> dummy; //t
	stream >> dummy; //i
	stream >> dummy; //c
	stream >> dummy; //e
	stream >> dummy; //s
	
	scene._vertices.resize(tmpCount);
	for(i=0; i < tmpCount; ++i) {
		stream >> scene._vertices[i];

		Vector3 normal(0,0,0);
		scene._vertices[i]._triCount = 0;
		scene._vertices[i]._normal = normal;
	}


	stream >> tmpCount;
	for(i=0; i < tmpCount; ++i) {
		stream >> dummy; //#
		stream >> dummy; //m
		stream >> dummy; //e
		stream >> dummy; //s
		stream >> dummy; //h
		stream >> tmpCount2;
		char transformationType;
		int transformationId;
		std::vector< std::tuple <char, int> > transformations;

		Mesh tmpMesh;
		std::vector<Triangle> triangles;
		stream >> tmpMesh._type;
		stream >> tmpMesh._materialId;

		stream >> tmpMesh._transformationsCount;
		for(j=0; j < tmpMesh._transformationsCount; ++j) {
			stream >> transformationType;
			stream >> transformationId;
			std::tuple <char, int> tmpTuple (transformationType, transformationId);
			transformations.push_back(tmpTuple);
			tmpMesh._transformations = transformations;
		}

		stream >> tmpMesh._triCount;
		for(j=0; j < tmpMesh._triCount; ++j) {
			int vertId1, vertId2, vertId3;
			stream >> vertId1 >> vertId2 >> vertId3;

			Vertex vert1, vert2, vert3;
			vert1 = scene._vertices[vertId1-1];
			vert2 = scene._vertices[vertId2-1];
			vert3 = scene._vertices[vertId3-1];
			
    		VertexId    vertices[3];
			vertices[0] = vertId1;
			vertices[1] = vertId2;
			vertices[2] = vertId3;

			Triangle tempTri(vertices, tmpMesh._materialId);
			
			Vector3 unitNormal = triNormal(vert1, vert2, vert3);

			scene._vertices[vertId1-1]._normal = ((scene._vertices[vertId1-1]._normal*scene._vertices[vertId1-1]._triCount) + unitNormal) / (scene._vertices[vertId1-1]._triCount+1);
			scene._vertices[vertId1-1]._normal.Normalize();

			scene._vertices[vertId2-1]._normal = ((scene._vertices[vertId2-1]._normal*scene._vertices[vertId2-1]._triCount) + unitNormal) / (scene._vertices[vertId2-1]._triCount+1);
			scene._vertices[vertId2-1]._normal.Normalize();

			scene._vertices[vertId3-1]._normal = ((scene._vertices[vertId3-1]._normal*scene._vertices[vertId3-1]._triCount) + unitNormal) / (scene._vertices[vertId3-1]._triCount+1);
			scene._vertices[vertId3-1]._normal.Normalize();

			scene._vertices[vertId1-1]._triCount++;
			scene._vertices[vertId2-1]._triCount++;
			scene._vertices[vertId3-1]._triCount++;

			triangles.push_back(tempTri);
			scene._triangles.push_back(tempTri);
		}
	    tmpMesh._tris = triangles;
	    tmpMesh.SetScene(&scene);
		scene._meshes.push_back(tmpMesh);
	}

	//////////////////////////////////////
	/*cout << scene._background.R() << " " << scene._background.G() << " " << scene._background.B() << endl;
	cout << scene._ambient.R() << " " << scene._ambient.G() << " " << scene._ambient.B() << endl;

	for(int i=0; i<scene._lights.size(); i++) {
		cout << scene._lights[i].Position() << endl;
		cout << scene._lights[i].IntensityColor().R() << " " << scene._lights[i].IntensityColor().G() << " " << scene._lights[i].IntensityColor().B() << endl;
	}
	for(int i=0; i<scene._materials.size(); i++) {
		cout << scene._materials[i]._ambient.R() << " " << scene._materials[i]._ambient.G() << " " << scene._materials[i]._ambient.B() << endl;
		cout << scene._materials[i]._diffuse.R() << " " << scene._materials[i]._diffuse.G() << " " << scene._materials[i]._diffuse.B() << endl;
		cout << scene._materials[i]._specular.R() << " " << scene._materials[i]._specular.G() << " " << scene._materials[i]._specular.B() << " " << scene._materials[i]._phong << endl;
	}
	for(int i=0; i<scene._translations.size(); i++) {
		cout << scene._translations[i] << endl;
	}
	for(int i=0; i<scene._scalings.size(); i++) {
		cout << scene._scalings[i] << endl;
	}
	for(int i=0; i<scene._rotations.size(); i++) {
		cout << scene._rotationAngles[i] << " " << scene._rotations[i] << endl;
	}
	for(int i=0; i<scene._vertices.size(); i++) {
		cout << scene._vertices[i].Position() << endl;
	}
	for(int i=0; i<scene._meshes.size(); i++) {
		cout << scene._meshes[i]._type << endl;
		cout << scene._meshes[i]._materialId << endl;
		for(int j=0; j<scene._meshes[i]._transformationsCount; j++) {
			cout << get<0>(scene._meshes[i]._transformations[j]) << " " << get<1>(scene._meshes[i]._transformations[j]) << endl;
		}
		for(int k=0; k<scene._meshes[i]._triCount; k++) {
			cout << scene._meshes[i]._tris[k]._vertices[0] << " " << scene._meshes[i]._tris[k]._vertices[1] << " " << scene._meshes[i]._tris[k]._vertices[2] << endl;
		}
	}
	for(int i=0; i<scene._vertices.size(); i++) {
		cout << scene._vertices[i]._normal << endl;
	}*/
	//////////////////////////////////////

	return stream;
}

void Scene::AddCameras(std::istream &stream)
{
	stream >> _camera;
	_camera.SetScene(this);
}

Scene::Scene(const Scene& rhs)
{
	*this = rhs;
}

Scene& Scene::operator=(const Scene& rhs)
{
	_vertices = rhs._vertices;

	_camera = rhs._camera;
	_meshes = rhs._meshes;

	_materials = rhs._materials;

	_lights = rhs._lights;

	_background = rhs._background;
	_ambient = rhs._ambient;

	for (auto& i : _meshes)
	{
		i.SetScene(this);
	}

	return *this;
}