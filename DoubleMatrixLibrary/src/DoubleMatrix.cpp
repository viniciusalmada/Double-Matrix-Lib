#include <iostream>
#include "DoubleMatrix.h"
#include "RandDouble.h"

DoubleMatrix::DoubleMatrix()
= default;

DoubleMatrix::DoubleMatrix(int rows, int cols) : mRows(rows), mColumns(cols)
{
	mData = vector<double>(rows * cols);
}

DoubleMatrix::DoubleMatrix(int dimension) :
	DoubleMatrix(dimension, dimension)
{
}

DoubleMatrix::DoubleC
DoubleMatrix::get(int r, int c) const
{
	const int index = r * mColumns + c;
	return mData[index];
}

void DoubleMatrix::set(int r, int c, double value)
{
	const int index = r * mColumns + c;
	mData[index] = value;
}

DoubleMatrix
DoubleMatrix::times(const DoubleMatrix& matrix) const
{
	DoubleMatrix res(mRows, matrix.mColumns);
	res.forEachRowNColumn([&](int& r, int& c, DoubleC)
	{
		for (int k = 0; k < mColumns; ++k)
		{
			DoubleC rowVal = get(r, k);
			DoubleC colVal = matrix.get(k, c);
			DoubleC prod = rowVal * colVal;
			DoubleC prevValue = res.get(r, c);
			res.set(r, c, prod + prevValue);
		}
	});
	return res;
}

DoubleMatrix DoubleMatrix::times(double scalar) const
{
	DoubleMatrix res(*this);
	res.forEachElement([&](int& i, DoubleC value)
	{
		res.mData[i] = value * scalar;
	});
	return res;
}

DoubleMatrix DoubleMatrix::times(int scalar) const
{
	DoubleMatrix res(*this);
	res.forEachElement([&](int& i, DoubleC value)
	{
		res.mData[i] = value * scalar;
	});
	return res;
}

DoubleMatrix DoubleMatrix::plus(DoubleMatrix& matrix) const
{
	DoubleMatrix res(*this);
	res.forEachElement([&](int& i, DoubleC)
	{
		res.mData[i] += matrix.mData[i];
	});
	return res;
}

DoubleMatrix DoubleMatrix::minus(DoubleMatrix& matrix) const
{
	DoubleMatrix res(*this);
	res.forEachElement([&](int& i, DoubleC)
	{
		res.mData[i] -= matrix.mData[i];
	});
	return res;
}

DoubleMatrix DoubleMatrix::unaryMinus() const
{
	DoubleMatrix res(*this);
	res.forEachElement([&](int& i, DoubleC)
	{
		res.mData[i] = -res.mData[i];
	});
	return res;
}

DoubleMatrix DoubleMatrix::transpose() const
{
	DoubleMatrix transposed(mColumns, mRows);
	forEachRowNColumn([&](int& r, int& c, DoubleC value)
	{
		transposed.set(c, r, value);
	});
	return transposed;
}

void DoubleMatrix::oneOnZeroDiagonal()
{
	forEachRowNColumn([this](int& r,int& c,DoubleC value)
	{
		if (r == c && value == 0.0)
			this->set(r, c, 1.0);
	});
}

void
DoubleMatrix::print() const
{
	for (int i = 0; i < mRows; ++i)
	{
		for (int j = 0; j < mColumns; ++j)
		{
			std::cout << get(i, j) << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void DoubleMatrix::forEachRowNColumn(const MatrixElem& block) const
{
	int r = 0, c = 0;
	while (r < mRows)
	{
		while (c < mColumns)
		{
			block(r, c, get(r, c));
			c++;
		}
		c = 0;
		r++;
	}
}

void DoubleMatrix::forEachElement(const Elem& block) const
{
	int i = 0;
	while (i < mRows * mColumns)
	{
		block(i, mData[i]);
		i++;
	}
}

DoubleMatrix DoubleMatrix::rand(int rows, int cols)
{
	DoubleMatrix dm(rows, cols);
	RandDouble rd(-1, 1);
	dm.forEachElement([&](int& i, DoubleC)
	{
		dm.mData[i] = rd() * 10.0;
	});
	return dm;
}
