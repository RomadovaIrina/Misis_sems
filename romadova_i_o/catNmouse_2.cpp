#include <iostream>
#include <geom/geometry.hpp>

const double DED = 1e-5;
const double t = 1e-7;
const double mini = 1e-5;

bool is_caught(VectorDec2D r_c, VectorDec2D r_m) {
	return (leng(r_m - r_c) <= DED);
}

int main()
{
	VectorDec2D r_c{ 10, -1 };
	VectorDec2D r_m{ -5, -20 };


	VectorDec2D v_m{ 0, 5 };
	double prev_diff = 1e10;
	bool DiffBtw = std::sin(convert_DecToPol(r_m).angle) < 0;

	double first_speed = leng(v_m) / 10, second_speed = leng(v_m) * 10;
	//std::cout << first_speed << " " << second_speed << "\n";
	double mid = (second_speed + first_speed) / 2;
	while (second_speed - first_speed > mini) {
		double v_c_0 = mid;

		VectorDec2D v_c = (r_m - r_c) * (1 / (leng(r_m - r_c))) * v_c_0;

		while (r_m.y < 0 && leng(r_m - r_c) >= DED) {
			VectorDec2D d_r = r_m - r_c;
			if (DiffBtw) {
				prev_diff = leng(d_r);
			}
			v_c = d_r * (1 / leng(d_r)) * v_c_0;
			r_c = r_c + v_c * t;
			r_m = r_m + v_m * t;

			if (DiffBtw && leng(d_r) > prev_diff) {
				break;
			}
			
		}

		if (is_caught(r_m, r_c)) {
			second_speed = mid;
		}
		else {
			first_speed = mid;
		}
		mid = (second_speed + first_speed) / 2;
		//std::cout << mid << " " << is_caught(r_m, r_c) << "\n";
	}
	std::cout << mid;

}
