#include "Camera.h"
#include "Scene.h"
#include <unistd.h>
#include "Vertex.h"
#include <math.h> 
#include <cmath> 
#include <climits>
using namespace std;

vector < vector <float> > Multiply4(vector < vector <float> > matrix1, vector < vector <float> > matrix2){
    vector < vector <float> > resultMatrix(
    4,
    std::vector<float>(4));
    
    for(int row=0;row<4;row++){
        for(int column=0;column<4;column++){
            resultMatrix[row][column] = 0;
 
            for(int n=0;n<4;n++){
                resultMatrix[row][column]+=
                    matrix1[row][n]*matrix2[n][column];
            }
        }
    }
    return resultMatrix;
}

vector < vector <float> > Multiply1(vector < vector <float> > matrix1, vector < vector <float> > matrix2){
    vector < vector <float> > resultMatrix(
    4,
    std::vector<float>(1));
    
    for(int row=0;row<4;row++){
        for(int column=0;column<1;column++){
            resultMatrix[row][column] = 0;
 
            for(int n=0;n<4;n++){
                resultMatrix[row][column]+=
                    matrix1[row][n]*matrix2[n][column];
            }
        }
    }
    return resultMatrix;
}

Camera::Camera(const Vector3 &position, const Vector3 &up, const Vector3 &gaze, float left, float right, float bottom,
               float top, float near, float far, size_t horRes, size_t verRes)
{
    _position = position;
    _space.Up = up;
    _gaze     = gaze;

    _imagePlane.Bottom = bottom;
    _imagePlane.Right  = right;
    _imagePlane.Left   = left;
    _imagePlane.Top    = top;

    ////////////////////////////////////
    _imagePlane.Near = near;
    _imagePlane.Far = far;
    ////////////////////////////////////

    _imagePlane.Height   = verRes;
    _imagePlane.Width    = horRes;

    init();
}


std::istream &operator>>(std::istream &stream, Camera &camera)
{
    stream >> camera._position;
    stream >> camera._gaze;
    stream >> camera._space.Up;

    stream >> camera._imagePlane.Left;
    stream >> camera._imagePlane.Right;
    stream >> camera._imagePlane.Bottom;
    stream >> camera._imagePlane.Top;

    ////////////////////////////////////
    stream >> camera._imagePlane.Near;
    stream >> camera._imagePlane.Far;
    ////////////////////////////////////

    stream >> camera._imagePlane.Width;
    stream >> camera._imagePlane.Height;

    stream >> camera._outputFile >> std::ws;

    camera.init();

    return stream;
}

void Camera::init()
{
    _space.Forward = -_gaze.Normalized();
	_space.Up.Normalize();
    _space.Left = Vector3::Cross(_space.Up, _space.Forward);
    _space.Left.Normalize();

    _space.Up = Vector3::Cross(_space.Forward, _space.Left);
    _space.Up.Normalize();

    //////////////////////////////////////////////////////////////
	_renderInfo.TopLeft = _position + (_space.Forward * -_imagePlane.Near)
									+ (_space.Left * _imagePlane.Left) 
									+ (_space.Up * _imagePlane.Top);
    ///////////////////////////////////////////////////////////////

	float pixelWidth = (_imagePlane.Right - _imagePlane.Left) / _imagePlane.Width;
	float pixelHeight = (_imagePlane.Top - _imagePlane.Bottom) / _imagePlane.Height;

	_renderInfo.OneRight = pixelWidth * _space.Left;
	_renderInfo.OneDown = -pixelHeight * _space.Up;
	Vector3 fullRow = _renderInfo.OneRight * -static_cast<int>(_imagePlane.Width);
	_renderInfo.NextRow = _renderInfo.OneDown + fullRow;
}

void Camera::SetScene(const Scene *scene)
{
    _scene = scene;
}

std::vector< std::vector<float> > Camera::CameraTransformation() const {
    std::vector<float> row;
    std::vector< std::vector<float> > mCam;
    row.push_back(_space.Left.X());
    row.push_back(_space.Left.Y());
    row.push_back(_space.Left.Z());
    float temp = -1 * (_space.Left.X()*_position.X() + _space.Left.Y()*_position.Y() + _space.Left.Z()*_position.Z());
    row.push_back(temp);
    mCam.push_back(row);
    row.clear();

    row.push_back(_space.Up.X());
    row.push_back(_space.Up.Y());
    row.push_back(_space.Up.Z());
    temp = -1 * (_space.Up.X()*_position.X() + _space.Up.Y()*_position.Y() + _space.Up.Z()*_position.Z());
    row.push_back(temp);
    mCam.push_back(row);
    row.clear();

    row.push_back(_space.Forward.X());
    row.push_back(_space.Forward.Y());
    row.push_back(_space.Forward.Z());
    temp = -1 * (_space.Forward.X()*_position.X() + _space.Forward.Y()*_position.Y() + _space.Forward.Z()*_position.Z());
    row.push_back(temp);
    mCam.push_back(row);
    row.clear();

    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    row.push_back(1);
    mCam.push_back(row);
    return mCam;
}

std::vector< std::vector<float> > Camera::PerspectiveTransformation() const{
    std::vector<float> row;
    std::vector< std::vector<float> > mPers;
    float temp = (2*_imagePlane.Near)/(_imagePlane.Right - _imagePlane.Left);
    row.push_back(temp);
    row.push_back(0);
    temp = (_imagePlane.Right + _imagePlane.Left) / (_imagePlane.Right - _imagePlane.Left);
    row.push_back(temp);
    row.push_back(0);
    mPers.push_back(row);
    row.clear();

    row.push_back(0);
    temp = (2*_imagePlane.Near)/(_imagePlane.Top - _imagePlane.Bottom);
    row.push_back(temp);
    temp = (_imagePlane.Top + _imagePlane.Bottom) / (_imagePlane.Top - _imagePlane.Bottom);
    row.push_back(temp);
    row.push_back(0);
    mPers.push_back(row);
    row.clear();

    row.push_back(0);
    row.push_back(0);
    temp = -1 * ((_imagePlane.Far + _imagePlane.Near) / (_imagePlane.Far - _imagePlane.Near));
    row.push_back(temp);
    temp = -1 * ((2 * _imagePlane.Far * _imagePlane.Near) / (_imagePlane.Far - _imagePlane.Near));    row.push_back(temp);
    row.push_back(temp);
    mPers.push_back(row);
    row.clear();

    row.push_back(0);
    row.push_back(0);
    row.push_back(-1);
    row.push_back(0);
    mPers.push_back(row);
    return mPers;
}

std::vector< std::vector<float> > Camera::ViewportTransformation() const {
    std::vector<float> row;
    std::vector< std::vector<float> > mView;
    float temp = _imagePlane.Width / 2;
    row.push_back(temp);
    row.push_back(0);
    row.push_back(0);
    row.push_back(temp);
    mView.push_back(row);
    row.clear();

    row.push_back(0);
    temp = _imagePlane.Height / 2;
    row.push_back(temp);
    row.push_back(0);
    row.push_back(temp);
    mView.push_back(row);
    row.clear();

    row.push_back(0);
    row.push_back(0);
    row.push_back(0.5);
    row.push_back(0.5);
    mView.push_back(row);
    row.clear();

    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    row.push_back(1);
    mView.push_back(row);
    return mView;
}

void Camera::Line(Vector3 v0, Vector3 v1, Image &output, Color color1, Color color2, float* zBuffer) const{
    float m = (v1.Y() - v0.Y()) / (v1.X() - v0.X());
    float diffY = v1.Y() - v0.Y();
    float diffX = v1.X() - v0.X();

    if(diffX >= 0 && diffY >= 0 && m<=1) {
        float y = v0.Y();
        float d = (v0.Y() - v1.Y()) + 0.5*(v1.X() - v0.X());
        for(float x=v0.X(); x<=v1.X(); x++) {
            
            float zValue = (fabs(x-v0.X())*v1.Z() + fabs(x-v1.X())*v0.Z()) / fabs(diffX);
            if(zValue < zBuffer[int(y) * _imagePlane.Width + int(x)]) {
                zBuffer[int(y) * _imagePlane.Width + int(x)] = zValue;
                int r = (fabs(x-v0.X())*color2.R() + fabs(x-v1.X())*color1.R()) / fabs(diffX);
                int g = (fabs(x-v0.X())*color2.G() + fabs(x-v1.X())*color1.G()) / fabs(diffX);
                int b = (fabs(x-v0.X())*color2.B() + fabs(x-v1.X())*color1.B()) / fabs(diffX);
                output.Pixel(y,x) = Color(r,g,b);
            }  
            
            if(d<0) {
                y++;
                d += (v0.Y()-v1.Y())+(v1.X()-v0.X());
            }
            else {
                d += v0.Y()-v1.Y();
            }

        }
    }
    else if(diffX >= 0 && diffY >= 0 && m>=1) {
        float x = v0.X();
        float d = 0.5*(v0.Y() - v1.Y()) + (v1.X() - v0.X());
        for(float y=v0.Y(); y<=v1.Y(); y++) {

            float zValue = (fabs(y-v0.Y())*v1.Z() + fabs(y-v1.Y())*v0.Z()) / fabs(diffY);
            if(zValue < zBuffer[int(y) * _imagePlane.Width + int(x)]) {
                zBuffer[int(y) * _imagePlane.Width + int(x)] = zValue;
                int r = (fabs(y-v0.Y())*color2.R() + fabs(y-v1.Y())*color1.R()) / fabs(diffY);
                int g = (fabs(y-v0.Y())*color2.G() + fabs(y-v1.Y())*color1.G()) / fabs(diffY);
                int b = (fabs(y-v0.Y())*color2.B() + fabs(y-v1.Y())*color1.B()) / fabs(diffY);
                output.Pixel(y,x) = Color(r,g,b);
            }

            if(d>0) {
                x++;
                d += (v0.Y()-v1.Y())+(v1.X()-v0.X());
            }
            else {
                d += v1.X()-v0.X();
            }

        }
    }
    else if(diffX <= 0 && diffY >= 0 && m<=-1) {
        float x = v0.X();
        float d = -0.5*(v0.Y() - v1.Y()) + (v1.X() - v0.X());
        for(float y=v0.Y(); y<=v1.Y(); y++) {

            float zValue = (fabs(y-v0.Y())*v1.Z() + fabs(y-v1.Y())*v0.Z()) / fabs(diffY);
            if(zValue < zBuffer[int(y) * _imagePlane.Width + int(x)]) {
                zBuffer[int(y) * _imagePlane.Width + int(x)] = zValue;
                int r = (fabs(y-v0.Y())*color2.R() + fabs(y-v1.Y())*color1.R()) / fabs(diffY);
                int g = (fabs(y-v0.Y())*color2.G() + fabs(y-v1.Y())*color1.G()) / fabs(diffY);
                int b = (fabs(y-v0.Y())*color2.B() + fabs(y-v1.Y())*color1.B()) / fabs(diffY);
                output.Pixel(y,x) = Color(r,g,b);
            }

            if(d<0) {
                x--;
                d += -1*(v0.Y()-v1.Y())+(v1.X()-v0.X());
            }
            else {
                d += v1.X()-v0.X();
            }

        }
    }
    else if(diffX <= 0 && diffY >= 0 && m>=-1) {
        float y = v0.Y();
        float d = -1*(v0.Y() - v1.Y()) + 0.5*(v1.X() - v0.X());
        for(float x=v0.X(); x>=v1.X(); x--) {

            float zValue = (fabs(x-v0.X())*v1.Z() + fabs(x-v1.X())*v0.Z()) / fabs(diffX);
            if(zValue < zBuffer[int(y) * _imagePlane.Width + int(x)]) {
                zBuffer[int(y) * _imagePlane.Width + int(x)] = zValue;
                int r = (fabs(x-v0.X())*color2.R() + fabs(x-v1.X())*color1.R()) / fabs(diffX);
                int g = (fabs(x-v0.X())*color2.G() + fabs(x-v1.X())*color1.G()) / fabs(diffX);
                int b = (fabs(x-v0.X())*color2.B() + fabs(x-v1.X())*color1.B()) / fabs(diffX);
                output.Pixel(y,x) = Color(r,g,b);
            } 

            if(d>0) {
                y++;
                d += -1*(v0.Y()-v1.Y())+(v1.X()-v0.X());
            }
            else {
                d += -1*(v0.Y()-v1.Y());
            }

        }
    }
    else if(diffX <= 0 && diffY <= 0 && m<=1) {
        float y = v0.Y();
        float d = -1*(v0.Y() - v1.Y()) + -0.5*(v1.X() - v0.X());
        for(float x=v0.X(); x>=v1.X(); x--) {

            float zValue = (fabs(x-v0.X())*v1.Z() + fabs(x-v1.X())*v0.Z()) / fabs(diffX);
            if(zValue < zBuffer[int(y) * _imagePlane.Width + int(x)]) {
                zBuffer[int(y) * _imagePlane.Width + int(x)] = zValue;
                int r = (fabs(x-v0.X())*color2.R() + fabs(x-v1.X())*color1.R()) / fabs(diffX);
                int g = (fabs(x-v0.X())*color2.G() + fabs(x-v1.X())*color1.G()) / fabs(diffX);
                int b = (fabs(x-v0.X())*color2.B() + fabs(x-v1.X())*color1.B()) / fabs(diffX);
                output.Pixel(y,x) = Color(r,g,b);
            } 

            if(d<0) {
                y--;
                d += -1*(v0.Y()-v1.Y())-1*(v1.X()-v0.X());
            }
            else {
                d += -1*(v0.Y()-v1.Y());
            }

        }
    }
    else if(diffX <= 0 && diffY <= 0 && m>=1) { 
        float x = v0.X();
        float d = -0.5*(v0.Y() - v1.Y()) + -1*(v1.X() - v0.X());
        for(float y=v0.Y(); y>=v1.Y(); y--) {
            
            float zValue = (fabs(y-v0.Y())*v1.Z() + fabs(y-v1.Y())*v0.Z()) / fabs(diffY);
            if(zValue < zBuffer[int(y) * _imagePlane.Width + int(x)]) {
                zBuffer[int(y) * _imagePlane.Width + int(x)] = zValue;
                int r = (fabs(y-v0.Y())*color2.R() + fabs(y-v1.Y())*color1.R()) / fabs(diffY);
                int g = (fabs(y-v0.Y())*color2.G() + fabs(y-v1.Y())*color1.G()) / fabs(diffY);
                int b = (fabs(y-v0.Y())*color2.B() + fabs(y-v1.Y())*color1.B()) / fabs(diffY);
                output.Pixel(y,x) = Color(r,g,b);
            }

            if(d>0) {
                x--;
                d += -1*(v0.Y()-v1.Y())-1*(v1.X()-v0.X());
            }
            else {
                d += -1*(v1.X()-v0.X());
            }

        }
    }
    else if(diffX >= 0 && diffY <= 0 && m<=-1) {
        float x = v0.X();
        float d = 0.5*(v0.Y() - v1.Y()) + -1*(v1.X() - v0.X());
        for(float y=v0.Y(); y>=v1.Y(); y--) {

            float zValue = (fabs(y-v0.Y())*v1.Z() + fabs(y-v1.Y())*v0.Z()) / fabs(diffY);
            if(zValue < zBuffer[int(y) * _imagePlane.Width + int(x)]) {
                zBuffer[int(y) * _imagePlane.Width + int(x)] = zValue;
                int r = (fabs(y-v0.Y())*color2.R() + fabs(y-v1.Y())*color1.R()) / fabs(diffY);
                int g = (fabs(y-v0.Y())*color2.G() + fabs(y-v1.Y())*color1.G()) / fabs(diffY);
                int b = (fabs(y-v0.Y())*color2.B() + fabs(y-v1.Y())*color1.B()) / fabs(diffY);
                output.Pixel(y,x) = Color(r,g,b);
            }

            if(d<0) {
                x++;
                d += 1*(v0.Y()-v1.Y())-1*(v1.X()-v0.X());
            }
            else {
                d += -1*(v1.X()-v0.X());
            }

        }
    }
    else if(diffX >= 0 && diffY <= 0 && m>=-1) {
        float y = v0.Y();
        float d = (v0.Y() - v1.Y()) + -0.5*(v1.X() - v0.X());
        for(float x=v0.X(); x<=v1.X(); x++) {

            float zValue = (fabs(x-v0.X())*v1.Z() + fabs(x-v1.X())*v0.Z()) / fabs(diffX);
            if(zValue < zBuffer[int(y) * _imagePlane.Width + int(x)]) {
                zBuffer[int(y) * _imagePlane.Width + int(x)] = zValue;
                int r = (fabs(x-v0.X())*color2.R() + fabs(x-v1.X())*color1.R()) / fabs(diffX);
                int g = (fabs(x-v0.X())*color2.G() + fabs(x-v1.X())*color1.G()) / fabs(diffX);
                int b = (fabs(x-v0.X())*color2.B() + fabs(x-v1.X())*color1.B()) / fabs(diffX);
                output.Pixel(y,x) = Color(r,g,b);
            } 

            if(d>0) {
                y--;
                d += 1*(v0.Y()-v1.Y())-1*(v1.X()-v0.X());
            }
            else {
                d += (v0.Y()-v1.Y());
            }

        }
    }
}

float lineEq(float x, float y, Vector3 second, Vector3 third) {
    float x0 = second.X();
    float y0 = second.Y();

    float x1 = third.X();
    float y1 = third.Y();
    return x*(y0-y1)+y*(x1-x0)+(x0*y1)-(y0*x1);
}

int tripleMin(float x, float y, float z) {
    return min(x, min(y,z));
}

int tripleMax(float x, float y, float z) {
    return max(x, max(y,z));
}

Image Camera::Render() const { 
    
    Image output(_imagePlane.Width, _imagePlane.Height,_scene->BackgroundColor());
    float* zBuffer = new float[(int) _imagePlane.Width* (int) _imagePlane.Height];
    for (auto i = 0U; i < _imagePlane.Width  * _imagePlane.Height; ++i) {
        zBuffer[i] = INFINITY;
    }
    /*std::vector< std::vector<float> > v;
    v = this->ViewportTransformation();
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }*/

    std::vector< std::vector<float> > mCam = CameraTransformation();
    std::vector< std::vector<float> > mPers = PerspectiveTransformation();
    std::vector< std::vector<float> > mView = ViewportTransformation();
    std::vector< std::vector<float> > camMultPers = Multiply4(mPers, mCam);

    for(int i=0; i<_scene->Meshes().size(); i++) {
        for(int j=0; j<_scene->Meshes()[i].GetTris().size(); j++) {
            std::vector <Vector3> tri;

            float x1 = _scene->Meshes()[i].GetTris()[j]._vertices[0].Position().X();
            float x2 = _scene->Meshes()[i].GetTris()[j]._vertices[1].Position().X();
            float x3 = _scene->Meshes()[i].GetTris()[j]._vertices[2].Position().X();

            float y1 = _scene->Meshes()[i].GetTris()[j]._vertices[0].Position().Y();
            float y2 = _scene->Meshes()[i].GetTris()[j]._vertices[1].Position().Y();
            float y3 = _scene->Meshes()[i].GetTris()[j]._vertices[2].Position().Y();


            float z1 = _scene->Meshes()[i].GetTris()[j]._vertices[0].Position().Z();
            float z2 = _scene->Meshes()[i].GetTris()[j]._vertices[1].Position().Z();
            float z3 = _scene->Meshes()[i].GetTris()[j]._vertices[2].Position().Z();

            Vector3 center((x1+x2+x3)/3, (y1+y2+y3)/3, (z1+z2+z3)/3);
            Vector3 v (center.X() - _position.X(), center.Y() - _position.Y(), center.Z() - _position.Z());
            float nv = Vector3::Dot(_scene->Meshes()[i].GetTris()[j]._unitNormal, v);
            if(nv < 0) {
                for(int k=0; k<_scene->Meshes()[i].GetTris()[j]._vertices.size(); k++) {
                    Vertex vert = _scene->Meshes()[i].GetTris()[j]._vertices[k];
                    std::vector<std::vector<float> > v1;
                    std::vector<std::vector<float> > result;
                    std::vector<float> v2;
                    v2.push_back(vert.Position().X());
                    v1.push_back(v2);
                    v2.clear();

                    v2.push_back(vert.Position().Y());
                    v1.push_back(v2);
                    v2.clear();

                    v2.push_back(vert.Position().Z());
                    v1.push_back(v2);
                    v2.clear();

                    v2.push_back(1);
                    v1.push_back(v2);
                   
                    result = Multiply1(camMultPers, v1);

                    result[0][0] = result[0][0] / result[3][0];
                    result[1][0] = result[1][0] / result[3][0];
                    result[2][0] = result[2][0] / result[3][0];
                    result[3][0] = 1;
                    result = Multiply1(mView, result);
                    Vector3 newVert(result[0][0], _imagePlane.Height - result[1][0], result[2][0]);
                    tri.push_back(newVert);
                }
                if(_scene->Meshes()[i]._modelType == 1) {
                    Vector3 c1 = tri[0];
                    Vector3 c2 = tri[1];
                    Vector3 c3 = tri[2];
                    
                    Color color1 = _scene->Meshes()[i].GetTris()[j]._colors[0];
                    Color color2 = _scene->Meshes()[i].GetTris()[j]._colors[1];
                    Color color3 = _scene->Meshes()[i].GetTris()[j]._colors[2];

                    int xMin = tripleMin(c1.X(), c2.X(), c3.X());
                    int yMin = tripleMin(c1.Y(), c2.Y(), c3.Y());

                    int xMax = tripleMax(c1.X(), c2.X(), c3.X());
                    int yMax = tripleMax(c1.Y(), c2.Y(), c3.Y());

                    float gama=0,alpha=0,beta=0;
                    for (int y = yMin; y <= yMax; ++y) {
                        for (int x = xMin; x <= xMax; ++x) {
                            alpha = lineEq(x, y, c2, c3) / lineEq(c1.X(), c1.Y(), c2, c3);
                            beta = lineEq(x, y, c3, c1) / lineEq(c2.X(), c2.Y(), c3, c1);
                            gama = lineEq(x, y, c1, c2) / lineEq(c3.X(), c3.Y(), c1, c2);
                      
                            if (alpha>=0 && beta>=0 && gama>=0) {
                                float zValue = alpha*c1.Z() + beta*c2.Z() + gama*c3.Z();
                                if(zValue < zBuffer[y * _imagePlane.Width + x]) {
                                    zBuffer[y * _imagePlane.Width + x] = zValue;
                                    float r = (color1 * alpha).R() + (color2 * beta).R() + (color3 * gama).R();
                                    float g = (color1 * alpha).G() + (color2 * beta).G() + (color3 * gama).G();
                                    float b = (color1 * alpha).B() + (color2 * beta).B() + (color3 * gama).B();
                                    Color color(r, g, b);
                                    output.Pixel(y,x)= color;
                                }   
                            }
                         
                        }
                    } 

                }
                else {
                    Line(tri[0], tri[1], output, _scene->Meshes()[i].GetTris()[j]._colors[0], _scene->Meshes()[i].GetTris()[j]._colors[1], zBuffer);
                    Line(tri[0], tri[2], output, _scene->Meshes()[i].GetTris()[j]._colors[0], _scene->Meshes()[i].GetTris()[j]._colors[2], zBuffer);
                    Line(tri[1], tri[2], output, _scene->Meshes()[i].GetTris()[j]._colors[1], _scene->Meshes()[i].GetTris()[j]._colors[2], zBuffer);
                }
            }
        }
    }
    delete[] zBuffer;
    return output;
}
