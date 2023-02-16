#include<iostream>
#include<sstream>

const std::runtime_error zero_division_error("Division by Zero");
const std::runtime_error bad_formatting_error("Bad Format");

class Rational {
public:
	Rational() = default;
	explicit Rational(int64_t);
	Rational(int64_t n, int64_t dn) {
		num_ = n;
		denum_ = dn;
		if (denum_ == 0) {
			throw zero_division_error;
		}
		modify();
		format();
	}

	Rational& operator=( Rational& frac) = default;
	Rational& operator+=( const Rational& frac);
	Rational& operator-=( const Rational& frac);
	Rational& operator*=(const Rational& frac);
	Rational& operator/=(const Rational& frac);
	Rational& operator++();
	Rational operator++(int);
	Rational& operator--();
	Rational operator--(int);


	bool operator==(const Rational& frac);
	bool operator!=(const Rational& frac);
	bool operator>(const Rational& frac);
	bool operator>=(const Rational& frac);
	bool operator<=(const Rational& frac);
	bool operator<(const Rational& frac);

	int64_t getnum() const {
		return num_;
	}
	int64_t getDenum() const {
		return denum_;
	}
	

	std::istream& readFrom(std::istream& in) {
		char slash{0};
		int64_t numerator{0};
		int64_t denumerator{0};

		if (!in.good()) {
			return in;
		}
		in >> numerator >> slash >> denumerator;
		
		if (slash != slash_ || denumerator < 0) {
			//throw bad_formatting_error;
			in.setstate(in.failbit);
		}

		if (denumerator == 0) {
			//throw zero_division_error;
			in.setstate(in.failbit);
		}

		num_ = numerator;
		denum_ = denumerator;
		modify();
		format();
		return in;
	}

	std::ostream& writeTo(std::ostream& out) const {
		out << num_ << slash_ << denum_;
		return out;
	}

	~Rational() = default;
private:
	int64_t num_{0};
	int64_t denum_{1};
	void modify() {
		int64_t gcd = GCD(num_, denum_);
		num_ /= gcd;
		denum_ /= gcd;
		
	}
	void format() {
		if (num_ * denum_ < 0) {
			denum_ = std::abs(denum_);
			num_ =-std::abs(num_);
		}
	}
	static int64_t GCD(int64_t lhs, int64_t rhs) {
		lhs = std::abs(lhs);
		rhs = std::abs(rhs);
		if (lhs == 0) {
			return rhs;
		}
		else if (rhs == 0) {
			return lhs;
		}
		else {
			return GCD(std::max(lhs, rhs) % std::min(lhs, rhs), std::min(lhs, rhs));
		}
	}

	static const char slash_{ '/' };
};

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


