#include <iostream>
#include <cmath>
#include <iostream>

int factor(int num) {
	int f = 1;
	for (int i = 1; i <= num; i += 1) {
		f *= i;
	}
	return f;
}

int main()
{
	double x = 0.1;
	double delta_x = 0.05;
	double eps = 0.0001;
	while (x <= 1 + delta_x) {

		double s = 0;
		double temp_x = x;
		double temp_prev = 2 * x;
		double diff = eps;
		int i = 0;
		while (temp_prev >= eps) {
			diff = temp_x - temp_prev;
			int power = i * 2;
			int to_div = factor(2 * i);
			temp_x = (std::pow(temp_x, power)) / to_div;
			s += temp_x;
			temp_prev = temp_x;
			i += 1;
		}
		std::cout << x << " " << s << "\n";
		x += delta_x;
	}
}
