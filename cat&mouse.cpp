#include <iostream>
#include <cmath>
const double rad = 3.14 / 180;

//структура декартового вектора
struct VectorDec2D
{
	double x = 0, y = 0;
};

//просто что то для на побаловаться
void print(const VectorDec2D& a) {
	std::cout << a.x << " " << a.y;
	std::cout << "\n";
}

//перегрузочка опрераторов для декартовых
VectorDec2D operator+(const VectorDec2D& a,const VectorDec2D& b) {
	return{ a.x + b.x, a.y + b.y };
}
VectorDec2D operator-(const VectorDec2D& a, const VectorDec2D& b) {
	return{ a.x-b.x, a.y-b.y };
}
double operator*(const VectorDec2D& a, const VectorDec2D& b) {
	return{ a.x * b.x + a.y * b.y };
}
VectorDec2D operator*(const VectorDec2D& a, double num) {
	return { a.x * num, a.y * num };
}
VectorDec2D operator*( double num, const VectorDec2D& a) {
	return { num * a.x, num * a.y };
}
VectorDec2D operator/(const VectorDec2D& a, double num) {
	return { a.x/num, a.y/num };
}
double leng(VectorDec2D t) {
	double n = std::sqrt(t.x * t.x+ t.y * t.y);
	return n;
}



//структура полярного вектора
struct VectorPol2D
{
	double r = 0.0, angle = 0.0;
};
VectorPol2D convert_a(VectorPol2D a) {
	a.angle *= rad;
	return { a.r, a.angle };
	
}

//перегрузка для полярных
VectorPol2D operator+(const VectorPol2D& a, const VectorPol2D& b) {
	double proection_x = a.r * std::cos(a.angle) + b.r * std::cos(b.angle);
	double proection_y = a.r * std::sin(a.angle) + b.r * std::sin(b.angle);

	return{ std::sqrt(proection_x * proection_x + proection_y * proection_y),
		std::atan(proection_x / proection_y) };
}
VectorPol2D operator-(const VectorPol2D& a, const VectorPol2D& b) {
	double
		proection_x = b.r * std::cos(b.angle) - a.r * std::cos(a.angle),
		proection_y = b.r * std::sin(b.angle) - a.r * std::sin(a.angle);

	return{ std::sqrt(proection_x * proection_x + proection_y * proection_y), 
		std::atan(proection_x / proection_y) };
}
VectorPol2D operator*(const VectorPol2D& a, double num) {
	return{ a.r * num, a.angle };
}
VectorPol2D operator*(double num, const VectorPol2D& a) {
	return{ a.r * num, a.angle };
}
double operator*(const VectorPol2D& a, const VectorPol2D& b) {
	double
		proec_a_x = a.r * std::cos(a.angle),
		proec_a_y = a.r * std::sin(a.angle),
		proec_b_x = b.r * std::cos(b.angle),
		proec_b_y = b.r * std::sin(b.angle);
	return proec_a_x * proec_b_x + proec_a_y * proec_b_y;
}

//перегрузка ввода вывода для стурктур
std::ostream& operator<<(std::ostream& out, VectorDec2D& a) {
	return out << a.x << " " << a.y;
}
std::istream& operator>>(std::istream& in, VectorDec2D& a) {
	return in >> a.x >> a.y;
}
std::ostream& operator<<(std::ostream& out, VectorPol2D& a) {
	return out << a.r << " " << a.angle;
}
std::istream& operator>>(std::istream& in, VectorPol2D& a) {
	return in >> a.r>> a.angle;
}
//перевод из одной системы коорд в другую
VectorDec2D convert_PolToDec(VectorPol2D a) {
	return { a.r * std::cos(a.angle), a.r * std::sin(a.angle) };
}
VectorPol2D convert_DecToPol(VectorDec2D a) {
	return { std::sqrt(a.x * a.x + a.y * a.y), std::atan(a.y / a.x) };
}
const double DED = 0.7;
const double t = 1e-6;
int main()
{
	//положение кота мыши, скорости
	VectorDec2D r_c{10, -10};
	VectorDec2D r_m{0, -20};
	//скорость кошака
	double v_c_0 = 100;
	//как меняется скорость коша и мыш
	VectorDec2D v_c = (r_m - r_c) * (1 / (leng(r_m - r_c))) * v_c_0;
	VectorDec2D v_m{-5, -25};
	double prev_diff = 0;
	bool DiffBtw = std::sin(convert_DecToPol(r_m).angle)<0;
	//цикл если мыш меньше 0 и если мыш не в кошке
	while (r_m.y<0 && leng(r_m-r_c)>=DED){
		VectorDec2D d_r = r_m - r_c;
		v_c = d_r * (1 / leng(d_r)) * v_c_0;
		r_c = r_c + v_c * t;
		r_m = r_m + v_m * t;
		//если расстояние между кошкой и мышкой растет, то у нас турбо мыш, которая убежала от кота.
		if (DiffBtw && leng(d_r) > prev_diff) {
			break;
		}
		prev_diff=leng(d_r);
	}
	if (leng(r_m - r_c) < DED) {
		std::cout << "Mouse was caught";
		std::cout << "\n";
		std::cout <<"cat:"<< r_c << " " <<"mouse:"<< r_m;
	}
	else if (r_m.y>=0) {
		std::cout << "Mouse escaped";
		std::cout << "\n";
		std::cout << "cat:" << r_c << " " << "mouse:" << r_m;
	}
	else if (DiffBtw && leng(r_m - r_c) > prev_diff) {
		std::cout << "Mouse is clown.";
	}

}
