#include <iostream>
#include "Vector_Lib.hpp"

const double DED = 0.7;
const double t = 1e-6;
int main()
{
	//положение кота мыши, скорости
	VectorDec2D r_c{ 10, -10 };
	VectorDec2D r_m{ 0, -20 };
	//скорость кошака
	double v_c_0 = 100;
	//как меняется скорость коша и мыш
	VectorDec2D v_c = (r_m - r_c) * (1 / (leng(r_m - r_c))) * v_c_0;
	VectorDec2D v_m{ -5, -25 };
	double prev_diff = 0;
	bool DiffBtw = std::sin(convert_DecToPol(r_m).angle) < 0;
	//цикл если мыш меньше 0 и если мыш не в кошке
	while (r_m.y < 0 && leng(r_m - r_c) >= DED) {
		VectorDec2D d_r = r_m - r_c;
		v_c = d_r * (1 / leng(d_r)) * v_c_0;
		r_c = r_c + v_c * t;
		r_m = r_m + v_m * t;
		//если расстояние между кошкой и мышкой растет, то у нас турбо мыш, которая убежала от кота.
		if (DiffBtw && leng(d_r) > prev_diff) {
			break;
		}
		prev_diff = leng(d_r);
	}
	if (leng(r_m - r_c) < DED) {
		std::cout << "Mouse was caught";
		std::cout << "\n";
		std::cout << "cat:" << r_c << " " << "mouse:" << r_m;
	}
	else if (r_m.y >= 0) {
		std::cout << "Mouse escaped";
		std::cout << "\n";
		std::cout << "cat:" << r_c << " " << "mouse:" << r_m;
	}
	else if (DiffBtw && leng(r_m - r_c) > prev_diff) {
		std::cout << "Mouse is clown." << "\n";
		std::cout << r_c << " " << r_m;
	}

}
