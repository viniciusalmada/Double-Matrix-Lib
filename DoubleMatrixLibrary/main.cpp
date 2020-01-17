#include <iostream>
#include "DoubleMatrix.h"
#include "LUDecomposition.h"
#include "MatrixLib.h"

int main()
{
	DoubleMatrix a = DoubleMatrix(2, 2);
	DoubleMatrix b = DoubleMatrix(2, 1);

	a.set(0, 0, 1);
	a.set(0, 1, 2);
	a.set(1, 0, 3);
	a.set(1, 1, 4);

	b.set(0, 0, 5);
	b.set(1, 0, 6);

	//std::cout << "Matrix A\n";
	a.print();
	//std::cout << "\nMatrix B\n";
	b.print();
	std::cout << "\nA*B\n";
	DoubleMatrix c = a * b;
	c.print();
	DoubleMatrix a2 = a * 2;
	a2.print();
	DoubleMatrix at = a.transpose();
	at.print();
	DoubleMatrix am = -at;
	am.print();

	DoubleMatrix d = DoubleMatrix(2, 2);
	d.set(0, 0, -1);
	d.set(0, 1, -2);
	d.set(1, 0, -3);
	d.set(1, 1, -4);

	(d - a).print();

	LUDecomposition alu = LUDecomposition(a);
	alu.l.print();
	alu.u.print();

	DoubleMatrix coeff(3);
	coeff.set(0, 0, 3);
	coeff.set(0, 1, 2);
	coeff.set(0, 2, -1);
	coeff.set(1, 0, 1);
	coeff.set(1, 1, 3);
	coeff.set(1, 2, 1);
	coeff.set(2, 0, 2);
	coeff.set(2, 1, 2);
	coeff.set(2, 2, -2);

	DoubleMatrix load(3, 1);
	load.set(0, 0, 0);
	load.set(0, 1, 1);
	load.set(0, 2, 2);

	DoubleMatrix res = MatrixLib::solveSystem(coeff, load);
	res.print();
	std::cin.get();
}
