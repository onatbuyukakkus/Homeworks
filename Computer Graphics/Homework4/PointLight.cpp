#include "PointLight.h"

std::istream &operator>>(std::istream &stream, PointLight &light) {

    stream >> light._position;
    stream >> light._intensity;

    return stream;
}

