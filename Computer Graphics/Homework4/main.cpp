#include <iostream>
#include <fstream>
#include "Scene.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <GL/glew.h>
#include <GL/gl.h>   // The GL Header File
#include <GL/freeglut.h> // The GL Utility Toolkit (Glut) Header

char gRendererInfo[512] = { 0 };
char gWindowTitle[512] = { 0 };

int gWidth, gHeight;

Scene *testP;
int meshCount = -1;
float pX, pY, pZ = 0;

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

void init() {
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    
}

void drawCubeElementsVBO() {	
	static int vertexPosDataSizeInBytes;

	if(testP->Meshes()[meshCount]._type == 1) { //solid
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else { //wireframe
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	GLuint indices[testP->Meshes()[meshCount]._triCount*3];

	int c=0;
	for(int i=0; i<(testP->Meshes()[meshCount]._triCount*3)-2;) {
		indices[i] = testP->Meshes()[meshCount]._tris[c]._vertices[0]-1; i++;
		indices[i] = testP->Meshes()[meshCount]._tris[c]._vertices[1]-1; i++;
		indices[i] = testP->Meshes()[meshCount]._tris[c]._vertices[2]-1; i++;
		c++;
	}

	GLfloat vertexPos[testP->Vertices().size()*3];
	c=0;
	for(int i=0; i<(testP->Vertices().size()*3)-2;) {
		vertexPos[i] = testP->Vertices()[c].Position().X(); i++; 
		vertexPos[i] = testP->Vertices()[c].Position().Y(); i++;
		vertexPos[i] = testP->Vertices()[c].Position().Z(); i++;
		c++;
	}

	GLfloat vertexCol[testP->Vertices().size()*3];
	c=0;
	for(int i=0; i<(testP->Vertices().size()*3)-2;) {
		vertexCol[i] = testP->Vertices()[c]._normal.X(); i++;
		vertexCol[i] = testP->Vertices()[c]._normal.Y(); i++;
		vertexCol[i] = testP->Vertices()[c]._normal.Z(); i++;
		c++;
	}

	GLuint vertexAttribBuffer, indexBuffer;

	glGenBuffers(1, &vertexAttribBuffer);
	glGenBuffers(1, &indexBuffer);

	assert(vertexAttribBuffer > 0 && indexBuffer > 0);

	glBindBuffer(GL_ARRAY_BUFFER, vertexAttribBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	vertexPosDataSizeInBytes = sizeof(vertexPos);
	int vertexColDataSizeInBytes = sizeof(vertexCol);
	int indexDataSizeInBytes = sizeof(indices);
	
	glBufferData(GL_ARRAY_BUFFER, vertexPosDataSizeInBytes + vertexColDataSizeInBytes, 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertexPosDataSizeInBytes, vertexPos);
	glBufferSubData(GL_ARRAY_BUFFER, vertexPosDataSizeInBytes, vertexColDataSizeInBytes, vertexCol);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexDataSizeInBytes, indices, GL_STATIC_DRAW);

	glVertexPointer(3, GL_FLOAT, 0, 0);
	glNormalPointer(GL_FLOAT, 0, (void*)vertexPosDataSizeInBytes);
	glDrawElements(GL_TRIANGLES, testP->Meshes()[meshCount]._triCount*3, GL_UNSIGNED_INT, 0);
}

typedef void(*drawFunc)(void);

void display() {            	
	glClearColor(testP->BackgroundColor().R(), testP->BackgroundColor().G(), testP->BackgroundColor().B(), 1);
	glClearDepth(1.0f);
	glClearStencil(0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	static float angle = 0;

	GLfloat deltaZ = -30;
	//GLfloat deltaZ = 0;

	drawFunc drawCube = drawCubeElementsVBO;

	

	for(int i=0; i<testP->Meshes().size(); i++) {
		glLoadIdentity();
		gluLookAt((GLdouble) testP->Cameras()._position.X() + pX,
			(GLdouble) testP->Cameras()._position.Y() + pY,
			(GLdouble) testP->Cameras()._position.Z() + pZ,
			(GLdouble) testP->Cameras()._position.X() + pX + testP->Cameras()._gaze.X(),
			(GLdouble) testP->Cameras()._position.Y() + pY + testP->Cameras()._gaze.Y(),
			(GLdouble) testP->Cameras()._position.Z() + pZ + testP->Cameras()._gaze.Z(),
			(GLdouble) testP->Cameras()._space.Up.X(),
			(GLdouble) testP->Cameras()._space.Up.Y(),
			(GLdouble) testP->Cameras()._space.Up.Z()
		);

		for(int i=0; i<testP->Lights().size(); i++) {
		    	glEnable(GL_LIGHT0+i);
				GLfloat lightPos[] = {(GLfloat) testP->Lights()[i].Position().X(),
									(GLfloat) testP->Lights()[i].Position().Y(),
									(GLfloat) testP->Lights()[i].Position().Z(),
									(GLfloat) 1.0};
				GLfloat ambientColor [] = {(GLfloat) testP->AmbientLight().R(),
											(GLfloat) testP->AmbientLight().G(),
											(GLfloat) testP->AmbientLight().B(),
											(GLfloat) 1.0};
				GLfloat lightColor [] = {(GLfloat) testP->Lights()[i].IntensityColor().R(),
											(GLfloat) testP->Lights()[i].IntensityColor().G(),
											(GLfloat) testP->Lights()[i].IntensityColor().B(),
											(GLfloat) 1.0};

				glLightfv(GL_LIGHT0+i, GL_POSITION, lightPos);
				glLightfv(GL_LIGHT0+i, GL_AMBIENT, ambientColor);
				glLightfv(GL_LIGHT0+i, GL_DIFFUSE, lightColor);
				glLightfv(GL_LIGHT0+i, GL_SPECULAR, lightColor);
		}

		for(int j=testP->Meshes()[i]._transformations.size()-1; j>=0; j--) {
			if(get<0>(testP->Meshes()[i]._transformations[j]) == 't') {
				Vector3 transform = testP->_translations[get<1>(testP->Meshes()[i]._transformations[j])-1];
				glTranslatef(transform.X(), transform.Y(), transform.Z());
			}
			if(get<0>(testP->Meshes()[i]._transformations[j]) == 'r') {
				Vector3 transform = testP->_rotations[get<1>(testP->Meshes()[i]._transformations[j])-1];
				float angle = testP->_rotationAngles[get<1>(testP->Meshes()[i]._transformations[j])-1];
				glRotatef(angle, transform.X(), transform.Y(), transform.Z());
			}
			if(get<0>(testP->Meshes()[i]._transformations[j]) == 's') {
				Vector3 transform = testP->_scalings[get<1>(testP->Meshes()[i]._transformations[j])-1];
				glScalef(transform.X(), transform.Y(), transform.Z());
			}
		}
		
		meshCount++;
		Color amb(testP->GetMaterial(testP->Meshes()[i]._materialId)._ambient.R(), testP->GetMaterial(testP->Meshes()[i]._materialId)._ambient.G(), testP->GetMaterial(testP->Meshes()[i]._materialId)._ambient.B());
		Color diff(testP->GetMaterial(testP->Meshes()[i]._materialId)._diffuse.R(), testP->GetMaterial(testP->Meshes()[i]._materialId)._diffuse.G(), testP->GetMaterial(testP->Meshes()[i]._materialId)._diffuse.B());
		Color spec(testP->GetMaterial(testP->Meshes()[i]._materialId)._specular.R(), testP->GetMaterial(testP->Meshes()[i]._materialId)._specular.G(), testP->GetMaterial(testP->Meshes()[i]._materialId)._specular.B());
		GLfloat ambColor[4] = {amb.R(), amb.G(), amb.B(), 1.0};
		GLfloat diffColor[4] = {diff.R(), diff.G(), diff.B(), 1.0};
		GLfloat specColor[4] = {spec.R(), spec.G(), spec.B(), 1.0};
		GLfloat specExp[1] = {testP->GetMaterial(testP->Meshes()[i]._materialId)._phong};
		glMaterialfv(GL_FRONT,GL_AMBIENT,ambColor);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,diffColor);
		glMaterialfv(GL_FRONT,GL_SPECULAR,specColor);
		glMaterialfv(GL_FRONT,GL_SHININESS,specExp);
		drawCube();
	}
	meshCount=-1;

	
	//glTranslatef(0, 0, -3);
	//glRotatef(angle, 1, 0, 0);
	//glScalef(5, 5, 5);

	angle += 0.1;

	glutSwapBuffers();
}

void reshape(int w, int h) {   // Create The Reshape Function (the viewport)
    w = w < 1 ? 1 : w;
    h = h < 1 ? 1 : h;

    gWidth = w;
    gHeight = h;

    glViewport(0, 0, testP->Cameras()._imagePlane.Width, testP->Cameras()._imagePlane.Height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-10, 10, -10, 10, -10, 10);

	glFrustum(testP->Cameras()._imagePlane.Left, testP->Cameras()._imagePlane.Right, testP->Cameras()._imagePlane.Bottom, testP->Cameras()._imagePlane.Top, testP->Cameras()._imagePlane.Near, testP->Cameras()._imagePlane.Far);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void idle() {
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	Vector3 rotarterVectorY(0,1,0);
    switch(key) {
        case 27:     // Escape
            exit(0); 
            break;
        case 'w':
        	pX += testP->Cameras()._gaze.X()*0.05;
        	pY += testP->Cameras()._gaze.Y()*0.05;
        	pZ += testP->Cameras()._gaze.Z()*0.05;
        	idle();
        	break;
        case 's':
        	pX -= testP->Cameras()._gaze.X()*0.05;
        	pY -= testP->Cameras()._gaze.Y()*0.05;
        	pZ -= testP->Cameras()._gaze.Z()*0.05;
        	idle();
        	break;
        case 'a':
			testP->_camera._gaze = rotation(0.5, rotarterVectorY, testP->Cameras()._gaze);
			testP->_camera._space.Up = rotation(0.5, rotarterVectorY, testP->Cameras()._space.Up);
			testP->_camera._space.Left = rotation(0.5, rotarterVectorY, testP->Cameras()._space.Left);
			idle();
        	break;
        case 'd':
			testP->_camera._gaze = rotation(-0.5, rotarterVectorY, testP->Cameras()._gaze);
			testP->_camera._space.Up = rotation(-0.5, rotarterVectorY, testP->Cameras()._space.Up);
			testP->_camera._space.Left = rotation(-0.5, rotarterVectorY, testP->Cameras()._space.Left);
			idle();
        	break;
        case 'u':
			testP->_camera._gaze = rotation(0.5, testP->Cameras()._space.Left, testP->Cameras()._gaze);
			testP->_camera._space.Up = rotation(0.5, testP->Cameras()._space.Left, testP->Cameras()._space.Up);
			idle();
        	break;
        case 'j':
			testP->_camera._gaze = rotation(-0.5, testP->Cameras()._space.Left, testP->Cameras()._gaze);
			testP->_camera._space.Up = rotation(-0.5, testP->Cameras()._space.Left, testP->Cameras()._space.Up);
			idle();
        	break;
        default:  
            break;
    }
}


int main(int argc, char** argv) {
    Scene test;
    testP = &test;

    if (argc < 2) {
        std::cout << "Please provide scene and camera files" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    std::ifstream cams(argv[2]);

    file >> test;
    test.AddCameras(cams);

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(testP->Cameras()._imagePlane.Width, testP->Cameras()._imagePlane.Height);
    glutCreateWindow("");
	glewInit();

    strcpy(gRendererInfo, (const char*) glGetString(GL_RENDERER));
    strcat(gRendererInfo, " - ");
    strcat(gRendererInfo, (const char*) glGetString(GL_VERSION));
    glutSetWindowTitle(gRendererInfo);

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    //glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
