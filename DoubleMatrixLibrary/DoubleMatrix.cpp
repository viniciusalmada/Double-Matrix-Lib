#include "DoubleMatrix.h"
#include <iostream>

DoubleMatrix::DoubleMatrix(const int rows, const int cols)
{
	mRows = rows;
	mColumns = cols;
	mMatrixData = new double*[mRows];
	for (int i = 0; i < mRows; i++)
		mMatrixData[i] = new double[mColumns];

	for (int i = 0; i < mRows; i++)
		for (int j = 0; j < mColumns; j++)
			mMatrixData[i][j] = 0.0;
}

DoubleMatrix::DoubleMatrix(int& rows, int& cols)
{
	mRows = rows;
	mColumns = cols;
	mMatrixData = new double*[mRows];
	for(int i = 0; i < mRows; i++)
		mMatrixData[i] = new double[mColumns];

	for(int i = 0; i < mRows; i++)
		for(int j = 0; j < mColumns; j++)
			mMatrixData[i][j] = 0.0;
}

DoubleMatrix::DoubleMatrix(int& rows, int& cols, double** data)
{
	mRows = rows;
	mColumns = cols;
	mMatrixData = data;
}

DoubleMatrix::~DoubleMatrix()
{
}

inline double& DoubleMatrix::get(int& m, int& n) const
{
	return mMatrixData[m][n];
}

inline void DoubleMatrix::set(const int m, const int n, const double value) const
{
	mMatrixData[m][n] = value;
}

void DoubleMatrix::checkDimensions(const DoubleMatrix& matrix) const
{
	try
	{
		if (this->mColumns != matrix.mRows)
			throw std::runtime_error("Dimensions must agree");
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		std::abort();
	}
}

/*std::shared_ptr<DoubleMatrix> DoubleMatrix::times(const DoubleMatrix& matrix) const
{
	checkDimensions(matrix);
	DoubleMatrix* res = new DoubleMatrix(this->mRows, matrix.mColumns);
	res->forEachRowNColumn([&](int& r, int& c, const double&)
	{
		for (int k = 0; k < res->mColumns; ++k)
		{
			const double product = this->get(r, k) * matrix.get(k, c);
			const double& oldValue = res->get(r, c);
			res->set(r, c, product + oldValue);
		}
	});
	return std::shared_ptr<DoubleMatrix>(res);
}*/

DoubleMatrix DoubleMatrix::times(const DoubleMatrix& matrix) const
{
	checkDimensions(matrix);
	DoubleMatrix res(this->mRows, matrix.mColumns);
	res.forEachRowNColumn([&](int& r, int& c, const double&)
	{
		for (int k = 0; k < res.mColumns; ++k)
		{
			const double product = this->get(r, k) * matrix.get(k, c);
			const double& oldValue = res.get(r, c);
			res.set(r, c, product + oldValue);
		}
	});
	return (res);
}

DoubleMatrix DoubleMatrix::times(double& scalar) const
{
	DoubleMatrix res = *this;
	forEachRowNColumn([&](int& r, int& c, const double& value)
	{
		res.set(r, c, value * scalar);
	});
	return res;
}

DoubleMatrix DoubleMatrix::plus(DoubleMatrix& matrix) const
{
	DoubleMatrix res = *this;
	res.forEachRowNColumn([&](int& r, int& c, const double& value1)
	{
		double& value2 = matrix.get(r, c);
		res.set(r, c, value1 + value2);
	});
	return res;
}

DoubleMatrix DoubleMatrix::transpose() const
{
	DoubleMatrix transpose = DoubleMatrix(this->mColumns, this->mRows);
	forEachRowNColumn([&transpose](const int r, const int c, const double value)
	{
		transpose.set(c, r, value);
	});
	return transpose;
}

	void DoubleMatrix::print() const
	{
		for (int i = 0; i < mRows; ++i)
		{
			for (int j = 0; j < mColumns; ++j)
			{
				std::cout << this->get(i, j) << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

void DoubleMatrix::forEachRowNColumn(const matrixElem& block) const
{
	int r = 0;
	int c = 0;
	while (r < mRows)
	{
		while (c < mColumns)
		{
			block(r, c, mMatrixData[r][c]);
			c++;
		}
		r++;
		c = 0;
	}
}
