#include <iostream>

int main() 
{
	int t, n;
	std::cin >> t;
	for (int i(0); i < t; i += 1) {
		std::cin >> n;
		int temp;
		if (n % 3 == 1) {
			temp = 1;
		}
		else {
			temp = 2;
		}
		int summ = 0;
		while (summ < n) {
			std::cout << temp;
			summ += temp;
			temp = 3 - temp;
		}
		std::cout<<"\n";
	}
}
