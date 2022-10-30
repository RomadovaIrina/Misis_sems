#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <array>




int main()
{
	int t;
	std::cin >> t;
	for (int tt = 0; tt < t; tt += 1) {
		int m, n, minH=1000, minL=1000,h=1000, l=1000;
		std::cin >> n >> m;
		for (int i = 0; i < n; i += 1) {
			std::string s;
			std::cin >> s;
			for (int j = 0; j < m; j += 1) {
				if (s[j] == 'R') {
					minH = std::min(minH, i);
					minL = std::min(minL, j);
					if (i < h && j < l) {
						h = i;
						l = j;
					}
				}
			}
		}
		if (minH == h && minL == l) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
}
