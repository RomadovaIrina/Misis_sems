#include <iostream>
#include <cmath>

unsigned long long factor(unsigned long long num) {
	unsigned long long f = 1;
	for (int i = 1; i <= num; i += 1) {
		f *= i;
	}
	return f;
 }


const double eps = 0.0001;
int main()
{
	for (double x = 0.1; x <= 1 + eps; x += 0.05) {
		double temp_x = x;
		int i = 0;
		double s = 0;
		while (temp_x >= eps) {
			double power = (std::pow(x, 2 * i));
			unsigned long long factorial = factor(2 * i);
			temp_x = power / factorial;
			s += temp_x;
			i += 1;
		}
		std::cout <<"x: "<<x << " "<<"Sum for x: " << s << "\n";
	}
		
}
