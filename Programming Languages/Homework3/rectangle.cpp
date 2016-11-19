#include "rectangle.h"
#include "coordinate.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(const Coordinate& a, const Coordinate& b)
{
	topLeft.setx(a.getx());
   	topLeft.sety(a.gety());
	bottomRight.setx(b.getx());
	bottomRight.sety(b.gety());
}

Rectangle::Rectangle(const Rectangle& a)
{
	topLeft.setx(a.topLeft.getx());
	topLeft.sety(a.topLeft.gety());
	bottomRight.setx(a.bottomRight.getx());
	bottomRight.sety(a.bottomRight.gety());
}

Rectangle::~Rectangle()
{

}

Coordinate Rectangle::getTopLeft() const
{
	return topLeft;
}

Coordinate Rectangle::getBottomRight() const
{
	return bottomRight;
}

void Rectangle::setTopLeft(const Coordinate& a)
{
	topLeft.setx(a.getx());
	topLeft.sety(a.gety());
}

void Rectangle::setBottomRight(const Coordinate& a)
{
	bottomRight.setx(a.getx());
	bottomRight.sety(a.gety());
}

bool Rectangle::contains(const Coordinate& a) const
{
	int tempX = a.getx();
	int tempY = a.gety();

	if (tempX >= topLeft.getx() && tempX <= bottomRight.getx() && tempY >= topLeft.gety() && tempY <= bottomRight.gety())
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

bool Rectangle::intersects(const Rectangle& a) const
{
	int tempX1 = a.getTopLeft().getx();
	int tempY1 = a.getTopLeft().gety();
	int tempX2 = a.getBottomRight().getx();
	int tempY2 = a.getBottomRight().gety();

	int realX1 = this->getTopLeft().getx();
	int realY1 = this->getTopLeft().gety();
	int realX2 = this->getBottomRight().getx();
	int realY2 = this->getBottomRight().gety();

	if(tempX1 < realX1 && tempX2 < realX1) {return 0;}
	else if(tempX1 > realX2 && tempX2 > realX2) {return 0;}
	else if(tempY1 < realY1 && tempY2 < realY1) {return 0;}
	else if(tempY1 > realY2 && tempY2 > realY2) {return 0;}
	else {return 1;}

}

/*int main()
{

	Rectangle a(Coordinate(16,16),Coordinate(24,24));
	Rectangle b ( Coordinate ( 16 , 16 ) , Coordinate ( 16 , 25 ) ) ;
	cout << a.intersects(b) << endl;}
	/*Coordinate a(1,1);
	Coordinate b(3,3);
	Coordinate c(0,0);
	Coordinate d(16,16);
	Rectangle onat(a,b);
	Rectangle beril(c,d);
	cout << onat.intersects(beril) << endl;
	cout << "topleft:" << onat.getTopLeft().getx() << onat.getTopLeft().gety() << "bottomright:" << onat.getBottomRight().getx() << onat.getBottomRight().gety() << endl;
	cout << "topleft:" << ekrem.getTopLeft().getx() << ekrem.getTopLeft().gety() << "bottomright:" << ekrem.getBottomRight().getx() << ekrem.getBottomRight().gety() << endl;
	onat.setTopLeft(Coordinate (2,2));
	onat.setBottomRight(Coordinate (4,4));
	cout << "topleft:" << onat.getTopLeft().getx() << onat.getTopLeft().gety() << "bottomright:" << onat.getBottomRight().getx() << onat.getBottomRight().gety() << endl;
	cout << "topleft:" << ekrem.getTopLeft().getx() << ekrem.getTopLeft().gety() << "bottomright:" << ekrem.getBottomRight().getx() << ekrem.getBottomRight().gety() << endl;
	cout << "trues:" << endl;
	cout << onat.contains(Coordinate (2,2)) << endl;
	cout << onat.contains(Coordinate (4,4)) << endl;
	cout << onat.contains(Coordinate (3,3)) << endl;
	cout << onat.contains(Coordinate (2,3)) << endl;
	cout << onat.contains(Coordinate (4,3)) << endl;
	cout << onat.contains(Coordinate (3,2)) << endl;
	cout << onat.contains(Coordinate (3,4)) << endl;
	cout << "falses:" << endl;
	cout << onat.contains(Coordinate (25,2)) << endl;
	cout << onat.contains(Coordinate (6,4)) << endl;
	cout << onat.contains(Coordinate (5,2)) << endl;
	cout << onat.contains(Coordinate (3,5)) << endl;

	Rectangle x(Coordinate(5,10), Coordinate(8,15));
	Rectangle y(Coordinate(6,12), Coordinate(20,21));
	Rectangle z(Coordinate(22,24), Coordinate(25,30));
	cout << x.intersects(y) << endl;
	return 0;
}*/
