#include <iostream>
#include <string>

int main() 
{
	int t, n;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		std::cin >> n;
		int a = n % 1000, b = n / 1000;
		int s_a = (a % 10) + (a % 100 / 10) + (a / 100), s_b = (b % 10) + (b % 100 / 10) + (b / 100);
		if (s_a == s_b) {
			std::cout << "Yes"<<std::endl;
		}
		else {
			std::cout << "No"<<std::endl;
		}
	}
}
