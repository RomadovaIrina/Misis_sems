#pragma once
#include <iosfwd>
#include <cmath>

struct VectorDec2D
{
	double x = 0, y = 0;
};
void print(const VectorDec2D& a);
VectorDec2D operator+(const VectorDec2D& a, const VectorDec2D& b);
VectorDec2D operator-(const VectorDec2D& a, const VectorDec2D& b);
double operator*(const VectorDec2D& a, const VectorDec2D& b);
VectorDec2D operator*(const VectorDec2D& a, double num);
VectorDec2D operator*(double num, const VectorDec2D& a);
VectorDec2D operator/(const VectorDec2D& a, double num);
double leng(VectorDec2D t);
struct VectorPol2D
{
	double r = 0.0, angle = 0.0;
};
VectorPol2D convert_a(VectorPol2D a);
VectorPol2D operator+(const VectorPol2D& a, const VectorPol2D& b);
VectorPol2D operator-(const VectorPol2D& a, const VectorPol2D& b);
VectorPol2D operator*(const VectorPol2D& a, double num);
VectorPol2D operator*(double num, const VectorPol2D& a);
double operator*(const VectorPol2D& a, const VectorPol2D& b);
std::ostream& operator<<(std::ostream& out, VectorDec2D& a);
std::istream& operator>>(std::istream& in, VectorDec2D& a);
std::ostream& operator<<(std::ostream& out, VectorPol2D& a);
std::istream& operator>>(std::istream& in, VectorPol2D& a);
VectorDec2D convert_PolToDec(VectorPol2D a);
VectorPol2D convert_DecToPol(VectorDec2D a);
