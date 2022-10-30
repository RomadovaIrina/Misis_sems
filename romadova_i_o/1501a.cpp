//дорешать
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <array>


int main()
{
	int t;
	std::cin >> t;
	for (int tt = 0; t < tt; tt += 1)
	{
		int n;
		std::cin >> n;
		std::array<std::array<int, 2>, 100> t{};
		std::array<int, 100> tm{};
		for (int i = 0; i < n; i += 1) {
			std::cin >> t[i][0] >> t[i][1];
		}
		for (int j = 0; j < n; j += 1) {
			std::cin >> tm[j];
		}

		int time = t[0][0] + tm[0], diff=std::ceil((float) (t[0][0]-t[0][1])/2);

	}
}
