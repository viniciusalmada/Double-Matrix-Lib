#ifndef DOUBLE_MATRIX_H
#define DOUBLE_MATRIX_H
#include <functional>

class DoubleMatrix final
{
private:
	typedef std::function<void(int&, int&, double&)> MatrixElem;

	double** mMatrixData;
	int mRows;
	int mColumns;

	void checkDimensions(const DoubleMatrix& matrix) const;

public:
	DoubleMatrix(int& rows, int& cols, double** data); // Copy constructor
	DoubleMatrix(int rows, int cols);
	DoubleMatrix(int& rows, int& cols);
	~DoubleMatrix();

	inline double& get(int& m, int& n) const;
	inline void set(int m, int n, double value);
	DoubleMatrix times(const DoubleMatrix& matrix) const;
	DoubleMatrix times(double& scalar) const;
	DoubleMatrix plus(DoubleMatrix& matrix) const;
	DoubleMatrix transpose() const;
	void print() const;
	void forEachRowNColumn(const MatrixElem& block) const;
};

#endif
