#ifndef DOUBLE_MATRIX_H
#define DOUBLE_MATRIX_H
#include <functional>
#include <memory>

class DoubleMatrix final
{
	double** mMatrixData;
	int mRows;
	int mColumns;
	typedef std::function<void(int&, int&, double&)> matrixElem;

	void checkDimensions(const DoubleMatrix& matrix) const;
public:
	
	DoubleMatrix(int& rows, int& cols, double** data);
	DoubleMatrix(int rows, int cols);
	DoubleMatrix(int& rows, int& cols);
	~DoubleMatrix();

	inline double& get(int& m, int& n) const ;
	inline void set(int m, int n, double value) const;
	// std::shared_ptr<DoubleMatrix> times(const DoubleMatrix& matrix) const;
	DoubleMatrix times(const DoubleMatrix& matrix) const;
	DoubleMatrix times(double& scalar) const;
	DoubleMatrix plus(DoubleMatrix& matrix) const;
	DoubleMatrix transpose() const;
	void print() const;
	void forEachRowNColumn(const std::function<void(int&, int&, double&)>& block) const;
};

#endif
