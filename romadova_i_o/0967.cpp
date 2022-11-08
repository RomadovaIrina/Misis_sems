#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <array>
#include <set>
#include <algorithm>


int main()
{

	int n = 0, a = 0, b = 0;
	std::cin >> n >> a >> b;
	int t;
	std::vector<int> s(n);
	int s_open = 0;
	for (int i = 0; i < n; i += 1) {
		std::cin >> t;
		if (i != 0) {
			s.push_back(t);
		}
		else {
			a *= t;
		}
		s_open += t;
	}
	sort(s.begin(), s.end(), std::greater<>());
	int k = 0;
	int j = 0;
	while (a / s_open < b) {
		k += 1;
		s_open -= s[j];
		j += 1;
	}
	std::cout << k;
}
