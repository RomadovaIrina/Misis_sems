#include <iostream>

int main() 
{
	int t, a,b;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		std::cin >> a >> b;
		if (a == b) {
			std::cout << "0" << std::endl;
		}
		else if ((a > b && (a - b) % 2 == 0) || (a < b && ( b-a) % 2 != 0)) {
			std::cout<<"1"<<std::endl;
		}
		else {
			std::cout<<"2"<<std::endl;
		}
		}
}
