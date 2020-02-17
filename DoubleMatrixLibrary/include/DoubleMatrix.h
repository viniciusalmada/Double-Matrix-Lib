#ifndef DOUBLE_MATRIX_H
#define DOUBLE_MATRIX_H
#include <functional>
#include <vector>

using std::vector;
using std::function;

class DoubleMatrix final
{
private:
	vector<double> mData;
	int mRows{};
	int mColumns{};
	
public:
	typedef const double& DoubleC;
	typedef function<void(int&, int&, DoubleC)> MatrixElem;
	typedef function<void(int&, DoubleC)> Elem;
	
	DoubleMatrix();
	DoubleMatrix(int rows, int cols);
	DoubleMatrix(int dimension);

	int nRows() const { return mRows; }
	int nColumns() const { return mColumns; }

	DoubleC get(int r, int c) const;
	void set(int r, int c, double value);
	DoubleMatrix operator*(const DoubleMatrix& matrix) const;
	DoubleMatrix operator*(double scalar) const;
	DoubleMatrix operator*(int scalar) const;
	DoubleMatrix operator+(DoubleMatrix& matrix) const;
	DoubleMatrix operator-(DoubleMatrix& matrix) const;
	DoubleMatrix operator-() const;
	DoubleMatrix transpose() const;
	void oneOnZeroDiagonal();

	void print() const;
	void forEachRowNColumn(const MatrixElem& block) const;
	inline void forEachElement(const Elem& block) const;

	static DoubleMatrix rand(int rows, int cols);
};

#endif
