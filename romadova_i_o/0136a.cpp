#include <iostream>
#include <string>
#include <vector>

int main()
{
	int n, present=0;
	std::cin >> n;
	std::vector<int> presents(n);
	for (int i = 0; i < n; i += 1) {
		std::cin >> present;
		presents[present - 1] = i + 1;
	}
	for (int j = 0; j < n; j += 1) {
		std::cout << presents[j] << " ";
	}
}
