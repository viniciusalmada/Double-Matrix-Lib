#ifndef MATRIX_LIB_H
#define MATRIX_LIB_H
#include "DoubleMatrix.h"

class MatrixLib
{
public:
	static DoubleMatrix solveSystem(DoubleMatrix& a, DoubleMatrix& b);

private:
	static double sumUX(DoubleMatrix& u, DoubleMatrix& x, int i);
	static double sumLD(DoubleMatrix& l, DoubleMatrix& d, int i);
	
};

#endif
