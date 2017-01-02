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
	stream >> scene._rayReflect;
	stream >> scene._background;
	stream >> scene._ambient;

	unsigned long tmpCount;
	unsigned long i;
	std::string dummy;
	/////////////////////
	Vector3 dummyVector;
	unsigned long j;
	unsigned long tmpCount2;
	/////////////////////

	stream >> tmpCount;
	scene._lights.resize(tmpCount);
	for (i = 0; i < tmpCount; ++i) {
		stream >> scene._lights[i];
	}

	stream >> tmpCount;
	getline(stream, dummy);
	scene._materials.resize(tmpCount);
	for (i = 0; i < tmpCount; ++i) {
		getline(stream, dummy);
		stream >> scene._materials[i] >> std::ws;
	}

	/////////////////
	stream >> dummy;
	stream >> tmpCount;
	for(i=0; i < tmpCount; ++i) {
		stream >> dummy;
		
		int width, height;
		const char * c = dummy.c_str();
	    read_jpeg_header(c, &width, &height);

	    UCOLOR** image = new UCOLOR* [height];
	    for (int y = 0; y < height; ++y) {
	        image[y] = new UCOLOR [width];
	    }
	    read_jpeg(c, image, &width, &height);
	    scene._textureHeight.push_back(height);
	    scene._textureWidth.push_back(width);
	    scene._textures.push_back(image);
	}

	stream >> dummy;
	stream >> tmpCount;
	scene._translations.resize(tmpCount);
	for(i=0; i < tmpCount; ++i) {
		stream >> scene._translations[i];
	}

	stream >> dummy;
	stream >> tmpCount;
	scene._scalings.resize(tmpCount);
	for(i=0; i < tmpCount; ++i) {
		stream >> scene._scalings[i];
	}

	stream >> dummy;
	stream >> tmpCount;
	scene._rotations.resize(tmpCount);
	scene._rotationAngles.resize(tmpCount);
	for(i=0; i < tmpCount; ++i) {
		stream >> scene._rotationAngles[i];
		stream >> scene._rotations[i];
	}

	float maxDist = 0;

	std::string type;
	int materialId;
	int textureId;
	char transformationType;
	int transformationId;
	int sphereId=0;
	int triangleId=0;

	stream >> tmpCount;
	for(i=0; i < tmpCount; ++i) {
		stream >> type;
		if(type=="#SphereInstance") {
			sphereId++;
			stream >> materialId;
			stream >> textureId;

			Vector3 center(0,0,0);
			Vertex tmpVert(center);
			scene._vertices.push_back(tmpVert);
			Sphere tmp(scene._vertices.size(), 1, materialId, textureId, sphereId);

			stream >> tmpCount2;
			for(j=0; j < tmpCount2; ++j) {
				stream >> transformationType;
				stream >> transformationId;
				if(transformationType == 's') {
					float scale = scene._scalings[transformationId-1].X();
					float radius = tmp.GetRadius() * scale;
					Vector3 up = tmp.GetUp() * scale;
					Vector3 right = tmp.GetRight() * scale;
					tmp.SetUp(up);
					tmp.SetRight(right);
					tmp.SetRadius(radius);
				}
				if(transformationType == 't') {
					Vector3 translatedCenter = scene._vertices[tmp.GetCenterId()-1].Position() + scene._translations[transformationId-1];
					Vertex translatedVertex(translatedCenter);
					scene._vertices[tmp.GetCenterId()-1] = translatedVertex;
					Vector3 up = tmp.GetUp() + scene._translations[transformationId-1];
					Vector3 right = tmp.GetRight() + scene._translations[transformationId-1];
					tmp.SetUp(up);
					tmp.SetRight(right);
				}
				if(transformationType == 'r') {
					float rotationAngle = scene._rotationAngles[transformationId-1];
					Vector3 rotatingVector = scene._rotations[transformationId-1];
					Vector3 up = rotation(rotationAngle, rotatingVector, tmp.GetUp());
					Vector3 right = rotation(rotationAngle, rotatingVector, tmp.GetRight());
					tmp.SetUp(up);
					tmp.SetRight(right);
				}
			}

			maxDist = std::max(
				{
						maxDist,
						std::abs(scene._vertices[scene._vertices.size()-1].Position().X()),
						std::abs(scene._vertices[scene._vertices.size()-1].Position().Y()),
						std::abs(scene._vertices[scene._vertices.size()-1].Position().Z())
				});

			tmp.SetScene(&scene);
			scene._spheres.push_back(tmp);
		}
		if(type=="#CubeInstance") {
			triangleId++;
			stream >> materialId;
			stream >> textureId;

			Vector3 point1(0.5,0.5,-0.5); 
			Vector3 point2(-0.5,0.5,-0.5); 
			Vector3 point3(-0.5,0.5,0.5); 
			Vector3 point4(0.5,0.5,0.5); 
			Vector3 point5(0.5,-0.5,-0.5); 
			Vector3 point6(-0.5,-0.5,-0.5); 
			Vector3 point7(-0.5,-0.5,0.5); 
			Vector3 point8(0.5,-0.5,0.5); 

			stream >> tmpCount2;
			for(j=0; j < tmpCount2; ++j) {
				stream >> transformationType;
				stream >> transformationId;
				if(transformationType == 's') {
					Vector3 centerPoint = (point3 + point5)/2;
					point1 -= centerPoint;
					point2 -= centerPoint;
					point3 -= centerPoint;
					point4 -= centerPoint;
					point5 -= centerPoint;
					point6 -= centerPoint;
					point7 -= centerPoint;
					point8 -= centerPoint;
					Vector3 scale = scene._scalings[transformationId-1];
					point1 *= scale;
					point2 *= scale;
					point3 *= scale;
					point4 *= scale;
					point5 *= scale;
					point6 *= scale;
					point7 *= scale;
					point8 *= scale;
					point1 += centerPoint;
					point2 += centerPoint;
					point3 += centerPoint;
					point4 += centerPoint;
					point5 += centerPoint;
					point6 += centerPoint;
					point7 += centerPoint;
					point8 += centerPoint;
				}
				if(transformationType == 't') {
					point1 += scene._translations[transformationId-1];
					point2 += scene._translations[transformationId-1];
					point3 += scene._translations[transformationId-1];
					point4 += scene._translations[transformationId-1];
					point5 += scene._translations[transformationId-1];
					point6 += scene._translations[transformationId-1];
					point7 += scene._translations[transformationId-1];
					point8 += scene._translations[transformationId-1];
				}
				if(transformationType == 'r') {
					float rotationAngle = scene._rotationAngles[transformationId-1];
					Vector3 rotatingVector = scene._rotations[transformationId-1];
					point1 = rotation(rotationAngle, rotatingVector, point1);
					point2 = rotation(rotationAngle, rotatingVector, point2);
					point3 = rotation(rotationAngle, rotatingVector, point3);
					point4 = rotation(rotationAngle, rotatingVector, point4);
					point5 = rotation(rotationAngle, rotatingVector, point5);
					point6 = rotation(rotationAngle, rotatingVector, point6);
					point7 = rotation(rotationAngle, rotatingVector, point7);
					point8 = rotation(rotationAngle, rotatingVector, point8);
				}
			}
			
			Vertex tmpVert1(point1); scene._vertices.push_back(tmpVert1);
			Vertex tmpVert2(point2); scene._vertices.push_back(tmpVert2);
			Vertex tmpVert3(point3); scene._vertices.push_back(tmpVert3);
			Vertex tmpVert4(point4); scene._vertices.push_back(tmpVert4);
			Vertex tmpVert5(point5); scene._vertices.push_back(tmpVert5);
			Vertex tmpVert6(point6); scene._vertices.push_back(tmpVert6);
			Vertex tmpVert7(point7); scene._vertices.push_back(tmpVert7);
			Vertex tmpVert8(point8); scene._vertices.push_back(tmpVert8);

			VertexId ids1[3]; 
			VertexId ids2[3];
			VertexId ids3[3];
			VertexId ids4[3];
			VertexId ids5[3];
			VertexId ids6[3];
			VertexId ids7[3];
			VertexId ids8[3];
			VertexId ids9[3];
			VertexId ids10[3];
			VertexId ids11[3];
			VertexId ids12[3];

			int vertSize = scene._vertices.size()+1;
			ids1[0] = vertSize-9 + 1;
			ids1[1] = vertSize-9 + 4;
			ids1[2] = vertSize-9 + 5;

			ids2[0] = vertSize-9 + 4;
			ids2[1] = vertSize-9 + 8;
			ids2[2] = vertSize-9 + 5;

			ids3[0] = vertSize-9 + 2; 
			ids3[1] = vertSize-9 + 6;
			ids3[2] = vertSize-9 + 7;

			ids4[0] = vertSize-9 + 3;
			ids4[1] = vertSize-9 + 2;
			ids4[2] = vertSize-9 + 7;

			ids5[0] = vertSize-9 + 1; 
			ids5[1] = vertSize-9 + 2;
			ids5[2] = vertSize-9 + 4;

			ids6[0] = vertSize-9 + 2;
			ids6[1] = vertSize-9 + 3;
			ids6[2] = vertSize-9 + 4;

			ids7[0] = vertSize-9 + 8; 
			ids7[1] = vertSize-9 + 7;
			ids7[2] = vertSize-9 + 5;

			ids8[0] = vertSize-9 + 7;
			ids8[1] = vertSize-9 + 6;
			ids8[2] = vertSize-9 + 5;

			ids9[0] = vertSize-9 + 4;
			ids9[1] = vertSize-9 + 3;
			ids9[2] = vertSize-9 + 8;

			ids10[0] = vertSize-9 + 3;
			ids10[1] = vertSize-9 + 7;
			ids10[2] = vertSize-9 + 8;

			ids11[0] = vertSize-9 + 2; 
			ids11[1] = vertSize-9 + 1;
			ids11[2] = vertSize-9 + 6;

			ids12[0] = vertSize-9 + 1;
			ids12[1] = vertSize-9 + 5;
			ids12[2] = vertSize-9 + 6;

			std::vector<float> uvVector1{0,0};
			std::vector<float> uvVector2{0,0.5};
			std::vector<float> uvVector3{0,1};

			std::vector<float> uvVector4{1.0/3.0,0};
			std::vector<float> uvVector5{1.0/3.0,0.5};
			std::vector<float> uvVector6{1.0/3.0,1};

			std::vector<float> uvVector7{2.0/3.0,0};
			std::vector<float> uvVector8{2.0/3.0,0.5};
			std::vector<float> uvVector9{2.0/3.0,1};

			std::vector<float> uvVector10{1,0};
			std::vector<float> uvVector11{1,0.5};
			std::vector<float> uvVector12{1,1};

			std::vector< std::vector<float> > uvTris1{uvVector8, uvVector5, uvVector9}; 
			std::vector< std::vector<float> > uvTris2{uvVector5, uvVector6, uvVector9}; 
			std::vector< std::vector<float> > uvTris3{uvVector1, uvVector2, uvVector5}; 
			std::vector< std::vector<float> > uvTris4{uvVector4, uvVector1, uvVector5};
			std::vector< std::vector<float> > uvTris5{uvVector11, uvVector8, uvVector12};
			std::vector< std::vector<float> > uvTris6{uvVector8, uvVector9, uvVector12};
			std::vector< std::vector<float> > uvTris7{uvVector10, uvVector7, uvVector11}; 
			std::vector< std::vector<float> > uvTris8{uvVector7, uvVector8, uvVector11}; 
			std::vector< std::vector<float> > uvTris9{uvVector5, uvVector2, uvVector6}; 
			std::vector< std::vector<float> > uvTris10{uvVector2, uvVector3, uvVector6}; 
			std::vector< std::vector<float> > uvTris11{uvVector7, uvVector4, uvVector8};
			std::vector< std::vector<float> > uvTris12{uvVector4, uvVector5, uvVector8}; 


		    Triangle tri1(ids1, materialId, textureId, triangleId, uvTris1); 
		    Triangle tri2(ids2, materialId, textureId, ++triangleId, uvTris2); 
		    Triangle tri3(ids3, materialId, textureId, ++triangleId, uvTris3); 
		    Triangle tri4(ids4, materialId, textureId, ++triangleId, uvTris4); 
		    Triangle tri5(ids5, materialId, textureId, ++triangleId, uvTris5); 
		    Triangle tri6(ids6, materialId, textureId, ++triangleId, uvTris6); 
		    Triangle tri7(ids7, materialId, textureId, ++triangleId, uvTris7); 
		    Triangle tri8(ids8, materialId, textureId, ++triangleId, uvTris8); 
		    Triangle tri9(ids9, materialId, textureId, ++triangleId, uvTris9); 
		    Triangle tri10(ids10, materialId, textureId, ++triangleId, uvTris10); 
		    Triangle tri11(ids11, materialId, textureId, ++triangleId, uvTris11); 
		    Triangle tri12(ids12, materialId, textureId, ++triangleId, uvTris12); 

		    for(int mxdst=vertSize-8; mxdst<vertSize; mxdst++) {
		    	maxDist = std::max(
				{
						maxDist,
						std::abs(scene._vertices[mxdst].Position().X()),
						std::abs(scene._vertices[mxdst].Position().Y()),
						std::abs(scene._vertices[mxdst].Position().Z())
				});
		    }

		    std::vector<Triangle> triangles;
		    triangles.push_back(tri1); scene._triangles.push_back(tri1);
		    triangles.push_back(tri2); scene._triangles.push_back(tri2);
		    triangles.push_back(tri3); scene._triangles.push_back(tri3);
		    triangles.push_back(tri4); scene._triangles.push_back(tri4);
		    triangles.push_back(tri5); scene._triangles.push_back(tri5);
		    triangles.push_back(tri6); scene._triangles.push_back(tri6);
		    triangles.push_back(tri7); scene._triangles.push_back(tri7);
		    triangles.push_back(tri8); scene._triangles.push_back(tri8);
		    triangles.push_back(tri9); scene._triangles.push_back(tri9);
		    triangles.push_back(tri10); scene._triangles.push_back(tri10);
		    triangles.push_back(tri11); scene._triangles.push_back(tri11);
		    triangles.push_back(tri12); scene._triangles.push_back(tri12);

		    Mesh tmpMesh(12, materialId, triangles);
		    tmpMesh.SetScene(&scene);
			scene._meshes.push_back(tmpMesh);

		} 
	}


	/*****************************************/
	/////////////////


	/*stream >> tmpCount >> std::ws;
	getline(stream, dummy);
	scene._vertices.resize(tmpCount);
	float maxDist = 0;
	for (i = 0; i < tmpCount; ++i) {
		stream >> scene._vertices[i] >> std::ws;
		maxDist = std::max(
				{
						maxDist,
						std::abs(scene._vertices[i].Position().X()),
						std::abs(scene._vertices[i].Position().Y()),
						std::abs(scene._vertices[i].Position().Z())
				});
	  }

	stream >> tmpCount;
	std::string type;

	for (i = 0; i < tmpCount; ++i) {
		stream >> type;
		getline(stream, dummy);

		if (type == "#Mesh") {
			Mesh tmp;
			stream >> tmp >> std::ws;
			tmp.SetScene(&scene);
			scene._meshes.push_back(tmp);
		}
		else {
			Sphere tmp;
			stream >> tmp >> std::ws;
			tmp.SetScene(&scene);
			scene._spheres.push_back(tmp);
		}
	}*/
	size_t depth = 0;
	maxDist = std::abs(maxDist);
	if (maxDist > 4) {
		depth = static_cast<size_t>(std::ceil(std::log2(maxDist)));
		maxDist = std::pow(2, depth);
	}
	else
	{
		depth = 2;
	}

	scene._root = Octree(Vector3(-maxDist, -maxDist, -maxDist), maxDist * 2);
	scene._root.Partition(depth);
	scene._root.SetScene(&scene);

	for (const auto& mesh : scene._meshes)
	{
		const auto& tris = mesh.GetTris();
		for (const auto& tri : tris)
		{
			scene._root.Insert(tri);
		}
	}

	scene._root.CountObjects();
	scene._root.Optimize();
	scene._root.SetScene(&scene);

	//////////////////////////////////////
	/*
	for(int i=0; i<scene._textures.size(); i++) {
	    std::cout << "Top-left pixel's (R, G, B) values: ";
	    std::cout << "(" << (int) scene._textures[i][0][0][0] << ", ";
	    std::cout << (int) scene._textures[i][0][0][1] << ", ";
	    std::cout << (int) scene._textures[i][0][0][2] << ")" << std::endl;

	    //std::cout << "Bottom-right pixel's (R, G, B) values: ";
	    //std::cout << "(" << (int) scene_textures[i][height-1][width-1][0] << ", ";
	    //std::cout << (int) scene_textures[i][height-1][width-1][1] << ", ";
	    //std::cout << (int) scene_textures[i][height-1][width-1][2] << ")" << std::endl;
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
	for(int i=0; i<scene._spheres.size(); i++) {
		scene._spheres[i].printSphere();
	}
	*/
	//////////////////////////////////////

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

/*Scene Scene::GetMockScene()
{
	Scene scene;
	scene._vertices.push_back(Vertex(Vector3(0, 0, 0)));
	scene._vertices.push_back(Vertex(Vector3(3, 0, 0)));
	scene._vertices.push_back(Vertex(Vector3(-3, 0, 0)));
	scene._vertices.push_back(Vertex(Vector3(0, 3, 0)));
	scene._vertices.push_back(Vertex(Vector3(0, -3, 0)));

	scene._materials.push_back(Material::Diffuse(Color(255, 0, 0)));
	scene._materials.push_back(Material::Diffuse(Color(255, 255, 0)));
	scene._materials.push_back(Material::Diffuse(Color(255, 255, 255)));
	scene._materials.push_back(Material::Diffuse(Color(0, 255, 255)));
	scene._materials.push_back(Material::Diffuse(Color(0, 0, 255)));

	scene._spheres.push_back(Sphere(1, 1, 1));
	scene._spheres.push_back(Sphere(2, 1, 2));
	scene._spheres.push_back(Sphere(3, 1, 3));
	scene._spheres.push_back(Sphere(4, 1, 4));
	scene._spheres.push_back(Sphere(5, 1, 5));

	scene._spheres[0].SetScene(&scene);
	scene._spheres[1].SetScene(&scene);
	scene._spheres[2].SetScene(&scene);
	scene._spheres[3].SetScene(&scene);
	scene._spheres[4].SetScene(&scene);

	scene._cameras.push_back(Camera(Vector3(0, 0, -5), Vector3(0, 1, 0), Vector3(0, 0, 1), -5, 5, -5, 5, 1, 256, 256));
	scene._cameras[0].SetScene(&scene);
	
	scene._background = Color(128, 0, 96);

	return scene;
}*/

Scene::Scene(const Scene& rhs)
{
	*this = rhs;
}

Scene& Scene::operator=(const Scene& rhs)
{
	_vertices = rhs._vertices;

	_cameras = rhs._cameras;
	_spheres = rhs._spheres;
	_meshes = rhs._meshes;

	_materials = rhs._materials;

	_lights = rhs._lights;

	_rayReflect = rhs._rayReflect;
	_background = rhs._background;
	_ambient = rhs._ambient;

	_root.SetScene(this);

	for (auto& i : _cameras)
	{
		i.SetScene(this);
	}

	for (auto& i : _spheres)
	{
		i.SetScene(this);
	}

	for (auto& i : _meshes)
	{
		i.SetScene(this);
	}

	return *this;
}
