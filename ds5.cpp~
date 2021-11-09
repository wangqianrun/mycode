#include <iostream>
using namespace std;

struct Matrix
{
	int row,col,value;
	Matrix& operator=(Matrix& x)
	{
		row=x.row;
		col=x.col;
		value=x.value;
		return *this;
	}
};
class sparesMatrix
{
	public:
		sparesMatrix(int r,int c);
		~sparesMatrix(){delete[] element };
		void transpose(sparseMatrix &b);
		void add(sparseMatrix &b,sparseMatrix &c);
		void multiply(sparseMatrix &b,sparseMatrix &c);
		void input(int x,int y,int z); 

	private:
			int rows;
			int cols;
			Matrix* element;
			int maxSize;
};
