
#pragma once

#include <iostream>
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

	Rational& operator=(Rational& frac) = default;
	Rational& operator+=(const Rational& frac);
	Rational& operator-=(const Rational& frac);
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
		char slash{ 0 };
		int64_t numerator{ 0 };
		int64_t denumerator{ 0 };

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
	int64_t num_{ 0 };
	int64_t denum_{ 1 };
	void modify() {
		int64_t gcd = GCD(num_, denum_);
		num_ /= gcd;
		denum_ /= gcd;

	}
	void format() {
		if (num_ * denum_ < 0) {
			denum_ = std::abs(denum_);
			num_ = -std::abs(num_);
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
