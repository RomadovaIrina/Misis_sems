#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
bool pow_2(long long  num) {
	while (num % 2 == 0) {
		if ((num / 2) == 1) {
			return true;
		}
		num /= 2;
	}
	return false;
}

int main() 
{
	long long  t, n;
	std::cin >> t;
	for (long long  i = 0; i < t; i += 1) {
		std::cin >> n;
		if (pow_2(n)) {
			std::cout << "NO" << std::endl;
		}
		else {
			std::cout << "YES" << std::endl;
		}
	}
}
