#include <iostream>
#include <string>
#include <vector>

int main()
{
	int n, p=0;
	std::cin >> n;
	std::vector<int> pres(n);
	for (int i = 0; i < n; i += 1) {
		std::cin >> p;
		pres[p - 1] = i + 1;
	}
	for (int j = 0; j < n; j += 1) {
		std::cout << pres[j] << " ";
	}
}
