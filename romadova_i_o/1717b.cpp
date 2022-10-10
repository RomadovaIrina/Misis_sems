#include <iostream>

int main()
{
	int n, k, r, c, t;
	std::cin >> t;
	for (int y = 0; y < t; y += 1) {
		std::cin >> n >> k >> r >> c;
		for (int i = 1; i < n+1; i += 1) {
			for (int j = 1; j < n+1; j += 1) {
				if ((i+j)%k==(r+c)%k) {
					std::cout << "X";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << "\n";
		}
	}

}
