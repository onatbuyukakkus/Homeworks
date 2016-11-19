#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate{
    private:
        // add private members, methods and constructors here as you need
	int x;
	int y;
    public:
        // do not make any modifications below
        Coordinate();
        Coordinate(int, int);
        Coordinate(const Coordinate&);
        ~Coordinate();
        int getx() const;
        int gety() const;
        void setx(int);
        void sety(int);
        Coordinate operator+(const Coordinate&) const;
};

#endif
