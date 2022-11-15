#include <iostream>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

int main()
{
	int a, m;
	std::cin >> a >> m;
	bool flag = 0;
	for (int i = 0; i <= 16; i+=1) {
		a += a % m;
		if (a % m == 0) {
			std::cout << "Yes";
			flag = 1;
			break;
		}
	}
	if (!flag) {
		std::cout << "No";
	}
}
