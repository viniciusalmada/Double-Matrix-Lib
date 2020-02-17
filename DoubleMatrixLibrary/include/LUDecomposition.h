#ifndef LUDECOMPOSITION_H
#define LUDECOMPOSITION_H
#include "DoubleMatrix.h"

class LUDecomposition
{
public:
	DoubleMatrix l;
	DoubleMatrix u;
public:
	LUDecomposition(const DoubleMatrix& matrix);

private:
	static double sumL(DoubleMatrix& l, DoubleMatrix& u, int& r, int& c);
	static double sumU(DoubleMatrix& l, DoubleMatrix& u, int& r, int& c);
};

#endif
