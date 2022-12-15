#include<iostream>
#include<fstream>
#include <geom/geometry.hpp>
#include <cmath>

const double t = 1e-1;
const double mini = 1e-1;
const double g = 1;
const double DED = 1.2;

int main()
{
	std::ofstream fout("output.txt");
	VectorDec2D point{-10, 0};
	VectorDec2D point_speed{0, 0.31};
	VectorDec2D point_acc = (-1)*g * point / std::pow(leng(point), 3);
	VectorDec2D point_prev;

	for (int i = 0; i < 51000; i += 1) {
		point_prev = point - point_speed * t;
		point_acc =(-1)* g * point / std::pow(leng(point), 3);
		point_speed = point_speed + point_acc * t;
		point = point + point_speed * t;
		if (std::abs(point.x) < mini && std::abs(point.y) < mini) {
			point = point - point_speed * t;
			point = point * (-1);
			point_acc = point_prev * g / std::pow(leng(point_prev), 3);

		}
		fout << point.x << " " << point.y << " " << point_speed.x << " " << point_speed.y << "\n";
	}
	fout.close();
}
