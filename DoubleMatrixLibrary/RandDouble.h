#ifndef RAND_DOUBLE_H
#define RAND_DOUBLE_H
#include <functional>
#include <random>

class RandDouble
{
private:
	std::function<double()> r;
public:
	RandDouble(double low, double high)
		: r(std::bind(std::uniform_real_distribution<>(low, high), std::default_random_engine()))
	{
	}

	double operator()() { return r(); }
};
#endif
