#include <iostream>
#include <string>
#include <array>
#include <vector>


int main()
{
	int t,n;
	std::cin >> t;
	while (t)
	{
		std::cin >> n;
		for (int i = 1; i <= n; i += 1) {
			for (int j = 1; j <= i; j += 1) {
				if (j == 1 || j == i) {
					std::cout << '1' << ' ';
				}
				else {
					std::cout << '0' << ' ';
				}
			}
			std::cout << std::endl;
		}
		t -= 1;
	}
}
