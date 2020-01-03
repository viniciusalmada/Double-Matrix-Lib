#include <iostream>
#include "DoubleMatrix.h"

int main()
{
	{
		DoubleMatrix a = DoubleMatrix(2, 2);
		DoubleMatrix b = DoubleMatrix(2, 1);

		a.set(0, 0, 131414);
		a.set(0, 1, 2);
		a.set(1, 0, 2);
		a.set(1, 1, 1);

		b.set(0, 0, 1);
		b.set(1, 0, 10);

		std::cout << "Matrix A\n";
		a.print();
		std::cout << "\nMatrix B\n";
		b.print();
		std::cout << "\nA*B\n";
		(a.times(b)).print();

	
	}
	std::cin.get();
	return 0;
}
