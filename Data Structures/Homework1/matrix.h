class DimensionMismatchException//Returns error message,message is "dimension mismatch exception!"
{
	public:
	DimensionMismatchException();
	const char * what();//returns error message
	private:
	const char *msg;
};

class InvalidIndexException//Returns error message,message is "invalid index exception!"
{
	public:
	InvalidIndexException();
	const char * what();//returns error message
	private:
	const char *msg;
};

template <class T>
class Matrix
{
private:
    T** data; // matrix elements stored here
    int rows; // number of rows
    int cols; // number of columns
public:
    Matrix(int numRows = 0, int numCols = 0); // makes storage allocation but leaves it uninitialized, for 0,0 dont allocate memory
    Matrix(T const* const* inputData, int numRows, int numCols);
    Matrix(const Matrix& rhs);
   ~Matrix();

    Matrix& operator=(const Matrix& rhs);

    // all of the below functions may throw dimension mismatch exception if the given matrix's dimensions does not match with the initial dimensions
    Matrix operator+(const Matrix& rhs) const; // element-wise addition of two matrices
    Matrix operator-(const Matrix& rhs) const; // element-wise subtraction of two matrices
    Matrix operator*(const Matrix& rhs) const; // multiplication of two matrices, dot product

    // these two functions may throw invalid index exception, it does this if the values are negative or if they are out of bounds or if they are 0
    T operator()(int r, int c) const; // returns the element value at row r and column c
    T& operator()(int r, int c); // returns reference of the element value at row r and column c

     int getRows() const; // returns the number of rows
     int getCols() const; // returns the number of columns

    void print() const; // prints the matrix with each column element separated by a tab and each row element in a new line print a newline after the last row
};

/* DO NOT MODIFY ANYTHING ABOVE THIS LINE.
   IT WILL BE REPLACED BY THE ORIGINAL INTERFACE,
   AND IF YOU MAKE CHANGES THEY WILL BE LOST.
   INSERT YOUR IMPLEMENTATION BELOW THIS LINE. */


//Your solutions will come to here

#include <iostream>
using namespace std;

//***********Default constructor******************
template <class T>
Matrix<T>::Matrix(int numRows, int numCols)
{
	if (! (numRows==0 && numCols==0))
	{
		int a=0;
		data = new T*[numRows];
		while(a<numRows)
		{
			data[a] = new T[numCols];
			a++;
		}
		
	}
	this->cols = numCols;
	this->rows = numRows;
}

//***********Constructor******************
template <class T>
Matrix<T>::Matrix(T const* const* inputData, int numRows, int numCols)
{
	data = new T*[numRows];	
	int b=0;
	int c=0;
	while(b<numRows)
	{
		data[b]= new T[numCols];
		b++;
	}
	while(c<numRows)
	{
		for(int d=0; d<numCols; d++)
		{
			data[c][d]=inputData[c][d];
		}
		c++;
	}
	this->rows = numRows;
	this->cols = numCols;
}

//***********Copy constructor******************
template<class T>
Matrix<T>::Matrix(const Matrix &rhs)
{
	this->cols = rhs.getCols();
	this->rows = rhs.getRows();
	int f=0;
	int b=0;
	data = new T*[rows];
	while(b<rows)
	{
		data[b]= new T[cols];
		b++;
	}
	while(f<rhs.getRows())
	{
		for(int j=0; j<cols; j++)
		{
			 this->data[f][j] = rhs.data[f][j];
		}
		f++;
	}
}

//***********Destructor******************
template <class T>
Matrix<T>::~Matrix()
{
	if (! (cols==0 && rows==0))
	{
		int e=0;
		while(e<rows)
		{
			delete[] data[e];
			e++;
		}
		delete[] data;
	}
}

//***********= operator******************
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix &rhs)
{ 
	this->cols = rhs.getCols();
	this->rows = rhs.getRows();
	int f=0;
	int b=0;
	data = new T*[rows];
	while(b<rows)
	{
		data[b]= new T[cols];
		b++;
	}
	while(f<rhs.getRows())
	{
		for(int j=0; j<rhs.getCols(); j++)
		{
			 this->data[f][j] = rhs.data[f][j];
		}
		f++;
	}
	return *this;
}

//***********+ operator******************
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix &rhs) const
{
	if( this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols())
	{
		throw DimensionMismatchException();
	}
	else
	{
		T **sumData = new T*[rhs.getRows()];
		int r=0;
		while(r<this->getRows())
		{
			sumData[r] = new T[rhs.getCols()];
			for(int i=0; i<this->getCols(); i++)
			{
				sumData[r][i] = data[r][i] + rhs.data[r][i];
			}
			r++;
		}
		Matrix<T> *solutionMatrix = new Matrix<T> (sumData, this->getRows(), this->getCols());
		return *solutionMatrix;
	}
}

//***********- operator******************
template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix &rhs) const
{
	if( this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols())
	{
		throw DimensionMismatchException();
	}
	else
	{
		T **sumData = new T*[rhs.getRows()];
		int r=0;
		while(r<this->getRows())
		{
			sumData[r] = new T[rhs.getCols()];
			for(int i=0; i<this->getCols(); i++)
			{
				sumData[r][i] = data[r][i] - rhs.data[r][i];
			}
			r++;
		}
		Matrix<T> *solutionMatrix = new Matrix<T> (sumData, this->getRows(), this->getCols());
		return *solutionMatrix;
	}
}

//*********** * operator******************
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) const
{
	if (this->getCols() != rhs.getRows())
	{
		throw DimensionMismatchException();
	}
	else
	{
		T **resData = new T*[this->getRows()];
		int m=0;
		while(m<this->getRows())
		{
			resData[m] = new T[rhs.getCols()];
			m++;
		} 
		for(int i=0; i<rhs.getRows(); i++)
		{
			for(int j=0; j<rhs.getCols(); j++)
			{
				resData[i][j]=0;
				for(int k=0; k<this->getCols(); k++)
				{
					
					resData[i][j] += this->data[i][k] * rhs.data[k][j];
				} 
			}
		}
		Matrix<T> *solutionMatrix = new Matrix<T> (resData, this->getRows(), rhs.getCols());
		return *solutionMatrix;
	}	
}

//**********() operator******************
template<class T>
T Matrix<T>::operator()(int r, int c) const
{
	if(c<0 || r<0 || c>this->getCols() || r>this->getRows())
	{
		throw InvalidIndexException();
	}
	else
	{
		return this->data[r-1][c-1];
	}
}

//**********()& operator******************
template<class T>
T& Matrix<T>::operator()(int r, int c)
{
	if(c<0 || r<0 || c>this->getCols() || r>this->getRows())
	{
		throw InvalidIndexException();
	}
	else
	{
		return this->data[r-1][c-1];
	}
}

//**********getRows operator******************
template<class T>
int Matrix<T>::getRows() const
{
	return this->rows;
}

//**********getCols operator******************
template<class T>
int Matrix<T>::getCols() const
{
	return this->cols;
}

//**********print operator******************
template<class T>
void Matrix<T>::print() const
{
	
	for(int i=0; i<this->rows; i++)
	{
		
		std::cout << this->data[i][0];
		for(int j=1; j<this->cols; j++)
		{
			
			std::cout << "\t" <<this->data[i][j];
		}
		std::cout << "\n";
	}
	
}

//**********errors******************
DimensionMismatchException::DimensionMismatchException()
{
	msg = "dimension mismatch exception!";
}

const char *DimensionMismatchException::what()
{
	return msg;
}

InvalidIndexException::InvalidIndexException()
{
	msg = "invalid index exception!";
}

const char *InvalidIndexException::what()
{
	return msg;
}


