#include "coordinate.h"
#include <iostream>
using namespace std;

Coordinate::Coordinate()
{
	x=0;
	y=0;
}

Coordinate::Coordinate(int a, int b)
{
	x=a;
	y=b;
}

Coordinate::Coordinate(const Coordinate& a)
{
	x=a.x;
	y=a.y;
}

Coordinate::~Coordinate()
{

}

int Coordinate::getx() const
{
	return x;
}

int Coordinate::gety() const
{
	return y;
}

void Coordinate::setx(int a)
{
	x=a;
}

void Coordinate::sety(int a)
{
	y=a;
}

Coordinate Coordinate::operator+(const Coordinate& a) const
{
	Coordinate temp;	
	temp.x=(x+a.x);
	temp.y=(y+a.y);
	return temp;
}

/*int main()
{
	Coordinate onat;
	Coordinate ekrem(1,2);
	cout << onat.getx() << onat.gety() << endl;
	cout << ekrem.getx() << ekrem.gety() << endl;
	onat.setx(2);
	onat.sety(3);
	cout << onat.getx() << onat.gety() << endl;
	cout << ekrem.getx() << ekrem.gety() << endl;
	onat=onat+ekrem;
	cout << onat.getx() << onat.gety() << endl;
	cout << ekrem.getx() << ekrem.gety() << endl;
	return 0;
}*/
