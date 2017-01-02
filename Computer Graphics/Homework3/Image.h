#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

#include "Color.h"

class Image {
    Color*    _pixels;
    int    _width;
    int    _height;

public:
    Image(int width, int height);
    Image(int width, int height, const Color& color);

    Image(const Image& rhs);
    Image(Image&& rhs);

    Image& operator=(Image rhs);

    ~Image();

    Color& Pixel(int x, int y);
    const Color& Pixel(int x, int y) const;

    friend std::ostream& operator<< (std::ostream& stream, const Image& image);
};

#endif //RAYTRACER_IMAGE_H
