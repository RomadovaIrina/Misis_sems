#include <iostream>
#include <cmath>
#include <array>
#include <string>
int main()
{
	int t;
	std::cin >> t;
	for (int tt = 0; tt < t; tt += 1) {
		int n;
		std::string s;
		std::cin >> n >> s;
		int b = 0, r = 0;
		int ans = -1;
		for (int i = 0; i < n; i += 1) {
			if (s[i] == 'B')
				b += 1;
			if (s[i] == 'R')
				r += 1;

			if (s[i] == 'W') {
				if ((b==0 && r>0)||(r==0 && b>0)) {
					ans = 0;
					break;
				}
				if (b + r == 1) {
					ans = 0;
					break;
				}
				b= 0;
				r = 0;
			}
		}
		if ((b == 0 && r > 0) || (r == 0 && b > 0)) {
			ans = 0;
			std::cout << "NO" << std::endl;
		}
		else if (ans = -1) {
			ans = 1;
			std::cout << "YES" << std::endl;
		}
	}
}
