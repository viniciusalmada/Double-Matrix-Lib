#include "MatrixLib.h"
#include "LUDecomposition.h"

DoubleMatrix MatrixLib::solveSystem(DoubleMatrix& a, DoubleMatrix& b)
{
	LUDecomposition lu(a);
	DoubleMatrix d(a.nRows(), 1);
	d.forEachRowNColumn([&](int& r,int&,DoubleMatrix::DoubleC)
	{
		double valD = b.get(r, 0) - sumLD(lu.l, d, r);
		d.set(r, 0, valD);
	});

	DoubleMatrix x(a.nRows(), 1);
	x.forEachRowNColumn([&](int& r, int&, DoubleMatrix::DoubleC)
	{
		int i = x.nRows() - r - 1;
		double valX = d.get(i, 0) / lu.u.get(i, i) - sumUX(lu.u, x, i);
		x.set(i, 0, valX);
	});
	return x;
}

double MatrixLib::sumUX(DoubleMatrix& u, DoubleMatrix& x, int i)
{
	int j = x.nRows();
	if (i >= j - 1) return 0.0;
	double res = 0.0;
	for (int n = i + 1; n < j; n++)
		res += (u.get(i, n) * x.get(n, 0)) / u.get(i, i);
	return res;
}

double MatrixLib::sumLD(DoubleMatrix& l, DoubleMatrix& d, int i)
{
	if (i < 1) return 0.0;
	double res = 0.0;
	for (int n = 0; n < i; n++)
		res += (l.get(i, n) * d.get(n, 0));
	return res;
}
