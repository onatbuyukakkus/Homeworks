#include "matrix.h"
#include <iostream>

using namespace std;

/* This function creates integer input arrays */
int ** createIntegerInput(int& row,int& col,int inputNo)
{
	int i,j;

	if(inputNo == 1)
	{
		row = 3;
		col = 3;

		int ** input = new int*[row];
		for(i=0; i<row; i++)
    			input[i] = new int[col];

		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				input[i][j] = (i*row + j)+1;

		return input;
	}
	else if(inputNo == 2)
	{
		row = 3;
		col = 3;

		int ** input = new int*[row];
		for(i=0; i<row; i++)
    			input[i] = new int[col];

		for(i=0;i<col;i++)
			for(j=0;j<row;j++)
				input[j][i] = (i*col + j)+1;

		return input;
	}
	else if(inputNo == 3)
	{
		row = 2;
		col = 3;

		int ** input = new int*[row];
		for(i=0; i<row; i++)
    			input[i] = new int[col];

		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				input[i][j] = (i*row + j)+1;

		return input;
	}
	else if(inputNo == 4)
	{
		row = 2;
		col = 3;

		int ** input = new int*[row];
		for(i=0; i<row; i++)
    			input[i] = new int[col];

		for(i=0;i<col;i++)
			for(j=0;j<row;j++)
				input[j][i] = (i*col + j)+1;

		return input;
	}
	else if(inputNo == 5)
	{
		row = 3;
		col = 2;

		int ** input = new int*[row];
		for(i=0; i<row; i++)
    			input[i] = new int[col];

		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				input[i][j] = (i*row + j)+1;

		return input;
	}
	else if(inputNo == 6)
	{
		row = 3;
		col = 2;

		int ** input = new int*[row];
		for(i=0; i<row; i++)
    			input[i] = new int[col];

		for(i=0;i<col;i++)
			for(j=0;j<row;j++)
				input[j][i] = (i*col + j)+1;

		return input;
	}
	
}

/* This function checks the class objects that are allocated in stack region */
void checkConstructors1()
{
	int **input1,row1,col1;
	input1 = createIntegerInput(row1,col1,1);

	int **input2,row2,col2;
	input2 = createIntegerInput(row2,col2,2);

	Matrix<int> matrix1;
	cout << "Printing the data information of the matrix 1" << endl;
	cout << "Size of the matrix = " << matrix1.getRows() << " x " << matrix1.getCols() << endl;
	matrix1.print();

	Matrix<int> matrix2(input1,row1,col1);
	cout << "Printing the data information of the matrix 2" << endl;
	cout << "Size of the matrix = " << matrix2.getRows() << " x " << matrix2.getCols() << endl;
	matrix2.print();

	Matrix<int> matrix3(input2,row2,col2);
	cout << "Printing the data information of the matrix 3" << endl;
	cout << "Size of the matrix = " << matrix3.getRows() << " x " << matrix3.getCols() << endl;
	matrix3.print();

	Matrix<int> matrix4(matrix2);
	cout << "Printing the data information of the matrix 4" << endl;
	cout << "Size of the matrix = " << matrix4.getRows() << " x " << matrix4.getCols() << endl;
	matrix4.print();

	matrix1 = matrix3;
	cout << "Printing the data information of the matrix 1 after assignment" << endl;
	cout << "Size of the matrix = " << matrix1.getRows() << " x " << matrix1.getCols() << endl;
	matrix1.print();

	matrix1 = matrix3 = matrix2;
	cout << "Printing the data information of the matrix 1 after multiple assignment" << endl;
	cout << "Size of the matrix = " << matrix1.getRows() << " x " << matrix1.getCols() << endl;
	matrix1.print();
	cout << "Printing the data information of the matrix 2 after multiple assignment" << endl;
	cout << "Size of the matrix = " << matrix2.getRows() << " x " << matrix2.getCols() << endl;
	matrix2.print();
	cout << "Printing the data information of the matrix 3 after multiple assignment" << endl;
	cout << "Size of the matrix = " << matrix3.getRows() << " x " << matrix3.getCols() << endl;
	matrix3.print();

	Matrix<int> matrix5(3,2);
	cout << "Printing the data information of the matrix 5" << endl;
	cout << "Size of the matrix = " << matrix5.getRows() << " x " << matrix5.getCols() << endl;
	matrix5.print();

	matrix5 = matrix3;
	cout << "Printing the data information of the matrix 5 after assignment" << endl;
	cout << "Size of the matrix = " << matrix5.getRows() << " x " << matrix5.getCols() << endl;
	matrix5.print();
	
	Matrix<int> matrix6;

	/* Note you should not get segmentation or invalid pointer error after function return */
}

/* This function checks the class objects that are allocated in heap region */
void checkConstructors2()
{
	int **input1,row1,col1;
	input1 = createIntegerInput(row1,col1,1);

	int **input2,row2,col2;
	input2 = createIntegerInput(row2,col2,2);

	Matrix<int> *matrix1 = new Matrix<int>;
	cout << "Printing the data information of the matrix 1" << endl;
	cout << "Size of the matrix = " << matrix1->getRows() << " x " << matrix1->getCols() << endl;
	matrix1->print();

	Matrix<int> *matrix2 = new Matrix<int>(input1,row1,col1);
	cout << "Printing the data information of the matrix 2" << endl;
	cout << "Size of the matrix = " << matrix2->getRows() << " x " << matrix2->getCols() << endl;
	matrix2->print();

	Matrix<int> *matrix3 = new Matrix<int>(input2,row2,col2);
	cout << "Printing the data information of the matrix 3" << endl;
	cout << "Size of the matrix = " << matrix3->getRows() << " x " << matrix3->getCols() << endl;
	matrix3->print();

	Matrix<int> *matrix4 = matrix2;// This does not call our copy constructor. Implicit shallow copy performs  
	cout << "Printing the data information of the matrix 4" << endl;
	cout << "Size of the matrix = " << matrix4->getRows() << " x " << matrix4->getCols() << endl;
	matrix4->print();

	matrix1 = matrix3;// This does not call our overloaded assignment operator. Implicit shallow copy performs 
	cout << "Printing the data information of the matrix 1 after assignment" << endl;
	cout << "Size of the matrix = " << matrix1->getRows() << " x " << matrix1->getCols() << endl;
	matrix1->print();

	Matrix<int> *matrix5 = new Matrix<int>(3,2);
	cout << "Printing the data information of the matrix 5" << endl;
	cout << "Size of the matrix = " << matrix5->getRows() << " x " << matrix5->getCols() << endl;
	matrix5->print();

	matrix5 = matrix1;
	cout << "Printing the data information of the matrix 5 after assignment" << endl;
	cout << "Size of the matrix = " << matrix5->getRows() << " x " << matrix5->getCols() << endl;
	matrix5->print();

	Matrix<int> *matrix6 = new Matrix<int>;

	delete matrix1;
	//matrix1->print();//Causes segmentation, since we delete matrix1
	//matrix3->print();//Causes segmentation, since pointer is deleted because of shallow copy
	delete matrix2;
	//matrix4->print();//Causes segmentation, since pointer is deleted because of shallow copy

	//delete matrix3;//Causes segmentation, since pointer is deleted because of shallow copy
	//delete matrix4;//Causes segmentation, since pointer is deleted because of shallow copy
	//delete matrix5;//Causes segmentation, since pointer is deleted because of shallow copy

	delete matrix6;
	
}

/* This function checks the matrix operations */
void checkOperators1()
{
	int **input1,row1,col1;
	input1 = createIntegerInput(row1,col1,1);

	int **input2,row2,col2;
	input2 = createIntegerInput(row2,col2,2);

	int **input3,row3,col3;
	input3 = createIntegerInput(row3,col3,3);

	int **input4,row4,col4;
	input4 = createIntegerInput(row4,col4,4);

	int **input5,row5,col5;
	input5 = createIntegerInput(row5,col5,5);

	int **input6,row6,col6;
	input6 = createIntegerInput(row6,col6,6);

	Matrix<int> matrix1(input1,row1,col1);
	cout << "Printing the data information of the matrix 1" << endl;
	cout << "Size of the matrix = " << matrix1.getRows() << " x " << matrix1.getCols() << endl;
	matrix1.print();

	Matrix<int> matrix2(input2,row2,col2);
	cout << "Printing the data information of the matrix 2" << endl;
	cout << "Size of the matrix = " << matrix2.getRows() << " x " << matrix2.getCols() << endl;
	matrix2.print();

	Matrix<int> matrix3;

	matrix3 = matrix1 + matrix2;
	cout << "Printing the data information of the matrix 3 after (matrix1 + matrix2)" << endl;
	cout << "Size of the matrix = " << matrix3.getRows() << " x " << matrix3.getCols() << endl;
	matrix3.print();

	Matrix<int> matrix4;
	matrix4 = matrix1 - matrix2;
	cout << "Printing the data information of the matrix 4 after (matrix1 - matrix2)" << endl;
	cout << "Size of the matrix = " << matrix4.getRows() << " x " << matrix4.getCols() << endl;
	matrix4.print();

	Matrix<int> matrix5;
	matrix5 = matrix1 * matrix2;
	cout << "Printing the data information of the matrix 5 after (matrix1 * matrix2)" << endl;
	cout << "Size of the matrix = " << matrix5.getRows() << " x " << matrix5.getCols() << endl;
	matrix5.print();

	Matrix<int> matrix6(input3,row3,col3);
	cout << "Printing the data information of the matrix 6" << endl;
	cout << "Size of the matrix = " << matrix6.getRows() << " x " << matrix6.getCols() << endl;
	matrix6.print();

	Matrix<int> matrix7(input4,row4,col4);
	cout << "Printing the data information of the matrix 7" << endl;
	cout << "Size of the matrix = " << matrix7.getRows() << " x " << matrix7.getCols() << endl;
	matrix7.print();

	Matrix<int> matrix8(input5,row5,col5);
	cout << "Printing the data information of the matrix 8" << endl;
	cout << "Size of the matrix = " << matrix8.getRows() << " x " << matrix8.getCols() << endl;
	matrix8.print();

	Matrix<int> matrix9(input6,row6,col6);
	cout << "Printing the data information of the matrix 9" << endl;
	cout << "Size of the matrix = " << matrix9.getRows() << " x " << matrix9.getCols() << endl;
	matrix9.print();

	cout << "Printing the data information of the result matrix after (matrix6 + matrix7)" << endl;
	cout << "Size of the matrix = " << matrix6.getRows() << " x " << matrix6.getCols() << endl;
	(matrix6 + matrix7).print();

	Matrix<int> matrix10 = (matrix6 - matrix7);
	cout << "Printing the data information of the matrix10 after (matrix6 - matrix7)" << endl;
	cout << "Size of the matrix = " << matrix10.getRows() << " x " << matrix10.getCols() << endl;
	matrix10.print();
	
	Matrix<int> matrix11;
	matrix11 = matrix8 * matrix6;
	cout << "Printing the data information of the matrix11 after (matrix8 * matrix6)" << endl;
	cout << "Size of the matrix = " << matrix11.getRows() << " x " << matrix11.getCols() << endl;
	matrix11.print();

	Matrix<int> matrix12;
	/*matrix12 = matrix7 * matrix9;
	cout << "Printing the data information of the matrix12 after (matrix7 * matrix9)" << endl;
	cout << "Size of the matrix = " << matrix12.getRows() << " x " << matrix12.getCols() << endl;
	matrix12.print();*/

	const Matrix<int> matrix13(input6,row6,col6);
	cout << "Printing the data information of the matrix 13" << endl;
	cout << "Size of the matrix = " << matrix13.getRows() << " x " << matrix13.getCols() << endl;
	matrix13.print();

	int number;
	number = matrix13(2,2);
	cout << "The value of the index (2,2) of the matrix 13 = " << number << endl;
	
	/*int& refNumber = matrix12(2,2);
	refNumber = 21;
	number = matrix12(2,2);
	cout << "The value of the index (2,2) of the matrix 12 after reference operation = " << number << endl;*/

}

/* This function checks the exceptions */
void checkOperators2()
{
	int **input1,row1,col1;
	input1 = createIntegerInput(row1,col1,1);

	int **input2,row2,col2;
	input2 = createIntegerInput(row2,col2,2);

	int **input3,row3,col3;
	input3 = createIntegerInput(row3,col3,3);

	int **input4,row4,col4;
	input4 = createIntegerInput(row4,col4,4);

	int **input5,row5,col5;
	input5 = createIntegerInput(row5,col5,5);

	int **input6,row6,col6;
	input6 = createIntegerInput(row6,col6,6);

	try
	{
		Matrix<int> matrix1(input1,row1,col1);
		Matrix<int> matrix2(input3,row3,col3);

		matrix1 + matrix2;	
	}
	catch(DimensionMismatchException &exception)
	{
		cout << "Dimension mismatch for matrix1 + matrix2" << endl;
		cout << "Exception Message = " << exception.what() << endl;
	}

	try
	{
		Matrix<int> matrix3(input1,row1,col1);
		Matrix<int> matrix4(input5,row5,col5);

		matrix3 - matrix4;	
	}
	catch(DimensionMismatchException &exception)
	{
		cout << "Dimension mismatch for matrix3 - matrix4" << endl;
		cout << "Exception Message = " << exception.what() << endl;
	}

	
	try
	{
		Matrix<int> matrix5(input5,row5,col5);
		Matrix<int> matrix6(input6,row6,col6);

		matrix5 * matrix6;	
	}
	catch(DimensionMismatchException &exception)
	{
		cout << "Dimension mismatch for matrix5 * matrix6" << endl;
		cout << "Exception Message = " << exception.what() << endl;
	}

	try
	{
		const Matrix<int> matrix6(input5,row5,col5);
		int number = matrix6(3,3);
	}
	catch(InvalidIndexException &exception)
	{
		cout << "Invalid index for matrix6(3,3)" << endl;
		cout << "Exception Message = " << exception.what() << endl;
	}

	try
	{
		const Matrix<int> matrix7(input5,row5,col5);
		int number = matrix7(0,3);
	}
	catch(InvalidIndexException &exception)
	{
		cout << "Invalid index for matrix7(0,3)" << endl;
		cout << "Exception Message = " << exception.what() << endl;
	}

	try
	{
		const Matrix<int> matrix8(input5,row5,col5);
		int number = matrix8(3,-1);
	}
	catch(InvalidIndexException &exception)
	{
		cout << "Invalid index for matrix8(3,-1)" << endl;
		cout << "Exception Message = " << exception.what() << endl;
	}

	try
	{
		Matrix<int> matrix9(input5,row5,col5);
		int& number = matrix9(3,3);
	}
	catch(InvalidIndexException &exception)
	{
		cout << "Invalid index for matrix9(3,3) (reference version)" << endl;
		cout << "Exception Message = " << exception.what() << endl;
	}

	try
	{
		Matrix<int> matrix10(input5,row5,col5);
		int& number = matrix10(0,3);
	}
	catch(InvalidIndexException &exception)
	{
		cout << "Invalid index for matrix10(0,3) (reference version)" << endl;
		cout << "Exception Message = " << exception.what() << endl;
	}

	try
	{
		Matrix<int> matrix11(input5,row5,col5);
		int& number = matrix11(3,-1);
	}
	catch(InvalidIndexException &exception)
	{
		cout << "Invalid index for matrix11(3,-1) (reference version)" << endl;
		cout << "Exception Message = " << exception.what() << endl;
	}


}

int main(int argc, char *argv[])
{
	int i,j;

	//checkConstructors1();
	//checkConstructors2();

	checkOperators1();
	//checkOperators2();



}
