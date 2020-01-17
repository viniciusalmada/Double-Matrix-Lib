#include "LUDecomposition.h"

LUDecomposition::LUDecomposition(const DoubleMatrix& matrix)
{
	l = DoubleMatrix(matrix.nRows(), matrix.nColumns());
	u = DoubleMatrix(matrix.nRows(), matrix.nColumns());

	l.oneOnZeroDiagonal();

	matrix.forEachRowNColumn([&](int& r,int& c,DoubleMatrix::DoubleC value)
	{
		if (r <= c)
		{
			const double valU = value - sumU(l, u, r, c);
			u.set(r, c, valU);
		}
		else
		{
			const double valL = value / u.get(c, c) - sumL(l, u, r, c);
			l.set(r, c, valL);
		}
	});
}

double LUDecomposition::sumL(DoubleMatrix& l, DoubleMatrix& u, int& r, int& c)
{
	if (c < 1) return 0.0;
	double res = 0.0;

	for (int n = 0; n < c; n++)
	{
		res += (l.get(r, n) * u.get(n, c)) / u.get(c, c);
	}

	return res;
}

double LUDecomposition::sumU(DoubleMatrix& l, DoubleMatrix& u, int& r, int& c)
{
	if (r < 1) return 0.0;
	double res = 0.0;

	for (int n = 0; n < c; n++)
	{
		res += (l.get(r, n) * u.get(n, c));
	}

	return res;
}
