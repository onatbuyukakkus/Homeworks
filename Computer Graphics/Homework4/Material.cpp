#include "Material.h"
#include "Scene.h"
#include <algorithm>
#include <cmath>
using namespace std;

std::istream &operator>>(std::istream &stream, Material &mat)
{
    stream >> mat._ambient;
    stream >> mat._diffuse;
    stream >> mat._specular;
    stream >> mat._phong;

    return stream;
}

