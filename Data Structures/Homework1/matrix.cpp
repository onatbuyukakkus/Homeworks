#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	/*int i1[3] = { 1, 2, 3 };
	int i2[3] = { 4, 5, 6 };
	int i3[3] = { 7, 8, 9 };
	const int** m1;
	m1 = new const int*[3];
	m1[0] = i1;
	m1[1] = i2;
	m1[2] = i3;
	
	int i4[2] = { 9, 8 };
	int i5[2] = { 6, 5 };
	int i6[2] = { 3, 2 };
	const int** m2;
	m2 = new const int*[3];
	m2[0] = i4;
	m2[1] = i5;
	m2[2] = i6;
	Matrix<int> x(m1, 3, 3);
	Matrix<int> y(m2, 3, 2);
	
	
	
	y.print();
	cout << "******************************************************" << endl;
	//x = y;
	x.print();
	cout << "******************************************************" << endl;
	Matrix<int> temp(3,3);
	/*temp=y+x;*/
	/*Matrix<int> temp(3,3);*/
		Matrix<int> temp(3,2);
	temp.print();
	return 0;
}
