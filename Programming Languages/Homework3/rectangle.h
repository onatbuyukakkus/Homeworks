#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "coordinate.h"

class Rectangle{
    private:
        // add private members, methods and constructors here as you need
	Coordinate topLeft;
	Coordinate topRight;
	Coordinate bottomRight;
	Coordinate bottomLeft;
    public:
        // do not make any modifications below
        Rectangle(const Coordinate&, const Coordinate&);
        Rectangle(const Rectangle&);
        ~Rectangle();
        Coordinate getTopLeft() const;
        Coordinate getBottomRight() const;
        void setTopLeft(const Coordinate&);
        void setBottomRight(const Coordinate&);
        bool contains(const Coordinate&) const;
        bool intersects(const Rectangle&) const;
};

#endif
