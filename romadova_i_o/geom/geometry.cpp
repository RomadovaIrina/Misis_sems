﻿#include <geom/geometry.hpp>
#include <iostream>

const double rad = 3.14 / 180;

void print(const VectorDec2D& a) {
	std::cout << a.x << " " << a.y;
	std::cout << "\n";
}

VectorDec2D operator+(const VectorDec2D& a, const VectorDec2D& b) {
	return{ a.x + b.x, a.y + b.y };
}
VectorDec2D operator-(const VectorDec2D& a, const VectorDec2D& b) {
	return{ a.x - b.x, a.y - b.y };
}
double operator*(const VectorDec2D& a, const VectorDec2D& b) {
	return{ a.x * b.x + a.y * b.y };
}
VectorDec2D operator*(const VectorDec2D& a, double num) {
	return { a.x * num, a.y * num };
}
VectorDec2D operator*(double num, const VectorDec2D& a) {
	return { num * a.x, num * a.y };
}
VectorDec2D operator/(const VectorDec2D& a, double num) {
	return { a.x / num, a.y / num };
}
double leng(VectorDec2D t) {
	double n = std::sqrt(t.x * t.x + t.y * t.y);
	return n;
}

VectorPol2D convert_a(VectorPol2D a) {
	a.angle *= rad;
	return { a.r, a.angle };

}

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
	return in >> a.r >> a.angle;
}

VectorDec2D convert_PolToDec(VectorPol2D a) {
	return { a.r * std::cos(a.angle), a.r * std::sin(a.angle) };
}
VectorPol2D convert_DecToPol(VectorDec2D a) {
	return { std::sqrt(a.x * a.x + a.y * a.y), std::atan(a.y / a.x) };
}