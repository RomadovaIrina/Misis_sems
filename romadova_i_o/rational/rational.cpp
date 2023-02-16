#include<iostream>
#include<sstream>
#include "rational.h"



Rational operator-(const Rational& frac) {
	return { (-1) * frac.getnum(), frac.getDenum()};
}


Rational& Rational::operator*=(const Rational& frac) {
	num_ *= frac.num_;
	denum_ *= frac.denum_;
	return *this;

}
Rational operator*(const Rational& frac_left, const Rational& frac_right) {
	Rational res = frac_left;
	res *= frac_right;
	return res;
}
Rational& Rational::operator/=(const Rational& frac) {
	num_ *= frac.denum_;
	denum_ *= frac.num_;
	modify();
	format();
	return *this;
}
Rational operator/(const Rational& frac_left, const Rational& frac_right) {
	Rational res = frac_left;
	res /= frac_right;
	return res;
}
Rational& Rational::operator+=( const Rational& frac) {
	int64_t bothdn = frac.denum_ * denum_;
	num_ = num_ * (bothdn / denum_) + frac.num_*(bothdn/frac.denum_);
	denum_ = bothdn;
	modify();
	return *this;
}
Rational operator+(const Rational& left_frac,  Rational& right_frac) {
	Rational res = left_frac;
	res += right_frac;
	return res;

}
Rational& Rational::operator-=(const Rational& frac) {
	*this += -frac;
	return *this;
}
Rational operator-(const Rational& left_frac, Rational& right_frac) {
	Rational res = left_frac;
	res -= right_frac;
	return res;

}

Rational& Rational::operator++() {
	*this += Rational(1, 1);
	return *this;
}
Rational Rational::operator++(int) {
	Rational t = *this;
	this->operator++();
	return t;
}
Rational& Rational::operator--() {
	*this -= Rational(1, 1);
	return *this;
}
Rational Rational::operator--(int) {
	Rational t = *this;
	--(*this);
	return t;
}


bool Rational::operator==(const Rational& frac)
{
	return (denum_ == frac.getDenum() && num_ == frac.getnum());
}
bool Rational::operator!=(const Rational& frac)
{
	return (!(*this == frac));
}
bool Rational::operator>(const Rational& frac)
{
	return (num_ * frac.getDenum() > denum_ * frac.getDenum());
}
bool Rational::operator<(const Rational& frac)
{
	return (num_ * frac.getDenum()< denum_ * frac.getDenum());
}
bool Rational::operator>=(const Rational& frac)
{
	return !(*this < frac);
}
bool Rational::operator<=(const Rational& frac)
{
	return !(*this > frac);
}

//судя по всему вариант такой себе но пока так.

//std::ostream& operator<<(std::ostream& out, Rational& trash) {
//	return out << trash.getnum() << "/" << trash.getDenum();
//}

std::istream& operator>>(std::istream& in, Rational& value) {
	return(value.readFrom(in));
}
std::ostream& operator<<(std::ostream& out, const Rational& value) {
	return(value.writeTo(out));
}


bool test(const std::string& to_check) {
	std::stringstream rat_test(to_check);
	Rational lhs;
	rat_test >> lhs;
	if (rat_test.good() || (rat_test.eof() && !rat_test.fail())) {
		std::cout << "Read correct " << lhs << "\n";
	}
	else {
		std::cout << "Read fail " << lhs << "\n";
	}
	return rat_test.good();
}
//условимся что тут гарантированно все красиво по формату подается
void test_operations(const std::string& to_check) {
	std::stringstream rat_test(to_check);
	Rational lhs, rhs;
	rat_test >> lhs >> rhs;
	std::cout << lhs << "+" << rhs << "=" << lhs + rhs<<"\n";
	std::cout << lhs << "-" << rhs << "=" << lhs - rhs<<"\n";
	std::cout << lhs << "*" << rhs << "=" << lhs * rhs << "\n";
	std::cout << lhs << "/" << rhs << "=" << lhs / rhs << "\n";
	std::cout << lhs << "inc" << "=" << ++lhs << " " << lhs++ << "\n";
	std::cout << lhs << "dec" << "=" << --lhs << " " << lhs-- << "\n";
	
	
}

int main()
{
	try {
		test("2/3");
		test("2/-4");
		test("20");
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	test_operations("1/2 3/4");
	Rational a = { 3, 5 };
	std::cout <<a<<" "<<a++;
	return 0;
}


