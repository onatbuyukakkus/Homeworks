#include "qtree.h"

int main()
{
	QTree qtree ( 32 ) ;
	Rectangle a ( Coordinate ( 5 , 5 ) , Coordinate ( 15 , 10 ) ) ;
	Rectangle b ( Coordinate ( 16 , 16 ) , Coordinate ( 16 , 25 ) ) ;
	Rectangle c ( Coordinate ( 22 , 24 ) , Coordinate ( 25 , 30 ) ) ;
	qtree . insert ( a ) ;
	//cout << qtree << endl ;
	qtree . insert ( b ) ;
	//cout << qtree << endl ;
	qtree . insert ( c ) ;
	cout << qtree << endl ;

	cout << "shakjdhsadjhsagdksagd" << endl;

	QTree onat (16);
	qtree = onat;
	cout << onat << endl;

	cout << "jhdsakjhgdakjshgdajhdgfdkj" << endl;

	cout << qtree << endl;

	const Rectangle *d = qtree [Coordinate (23,28)] ;
	if ( d == NULL )
	{
		cout << "No shape at the given position." << endl ;
	}
	else
	{
		cout << d->getTopLeft().getx() << " " << d->getTopLeft().gety() << endl ;
		cout << d->getBottomRight().getx() << " " << d->getBottomRight().gety() << endl ;
	}
	return 0;
}