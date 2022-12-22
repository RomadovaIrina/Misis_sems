#include <iostream>
#include <numeric>

const double eps = std::numeric_limits<double>::epsilon();
bool isinspace(double x, double y) {
	bool isinround = (x * x + y * y <= 1),
		isinquaters = ((-1 - eps <= x && x <= 0 + eps && 0 - eps <= y && y <= 1 + eps) || (0 - eps <= x && x <= 1 + eps && -1 - eps <= y && y <= 0 + eps)),
		isinlines = (y - x >= 1 || y - x <= -1);
	bool expression = isinround && isinquaters && isinlines;
	return (expression);
}

int main()
{
	double x, y;
	int point_valid = 0, point_false = 0;
	while (std::cin>>x>>y) {
		if (isinspace(x,y)) {
			point_valid += 1;
		}
		else {
			point_false += 1;
		}
	}
	std::cout << point_valid / (point_valid + point_false);
}
