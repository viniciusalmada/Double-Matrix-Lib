#ifndef DOUBLE_MATRIX_H
#define DOUBLE_MATRIX_H
#include <functional>

class DoubleMatrix final
{
	double** mMatrixData;
	int mRows;
	int mColumns;
public:
	DoubleMatrix(int rows, int cols);
	DoubleMatrix(int& dimension);
	DoubleMatrix(int& rows, int& cols, double** data);
	DoubleMatrix(const DoubleMatrix& dm);
	~DoubleMatrix();

	inline double& get(int& m, int& n) const;
	inline void set(int m, int n, double value) const;
	void checkDimensions(DoubleMatrix& matrix) const;
	DoubleMatrix times(DoubleMatrix& matrix) const;
	DoubleMatrix times(double& scalar) const;
	DoubleMatrix times(double scalar) const;
	DoubleMatrix plus(DoubleMatrix& matrix) const;
	DoubleMatrix transpose() const;
	void print() const;
	void forEachRowNColumn(const std::function<void(int&, int&, double&)>& block) const;
};

#endif
