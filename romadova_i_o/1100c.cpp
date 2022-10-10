#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numbers>
#include <iomanip>


const double pi = M_PI;

int main()
{
	int n, r;
	double  angl;
	std::cin >> n >> r;
	angl = std::sin(pi / n);
	std::cout << std::setprecision(8)<<(r * angl) / (1 - angl);
}
