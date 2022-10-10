#include <iostream>

int main() 
{
	int t, n,m;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		std::cin >> n >> m;
		std::cout << std::min(2, n - 1) * m << std::endl;
		}
}
