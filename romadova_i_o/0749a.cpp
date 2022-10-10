#include <iostream>
#include <string>

int main() 
{
	int n;
	int k = 0, temp;
	std::cin >> n;
	temp = n;
	while (n != 0) {
		if (n % 2 == 0) {
			n -= 2;
			k += 1;
		}
		else {
			n -= 3;
			k += 1;
		}

	}
	std::cout << k<<std::endl;
	while (temp != 0) {
		if (temp% 2 == 0) {
			temp-= 2;
			std::cout << "2 ";
		}
		else {
			temp -= 3;
			std::cout << "3 ";
		}

	}
}
