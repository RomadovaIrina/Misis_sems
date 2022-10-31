//разобраться с решением
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
		char c;
		std::cin >> n >> c >> s;
		if (c == 'g') {
			std::cout << 0 << std::endl;
			continue;
		}
		s += s;
		int begin = 0;
		for (int i = 0; i < 2*n; i += 1) {
			if (s[i] == 'g') {
				begin = i;
				break;
			}
		}
		int end = n - 1;
		for (int i =2* n-1 ; i >= 0; i-=1) {
			if (s[i] == 'g') {
				end = i;
				break;
			}
		}
		int ans = -10000,time=0 ;
		for (int i = end; i >= begin; i -= 1) {
			if (s[i] == 'g') {
				time = i;
			}
			else if (s[i] == c) {
				ans = std::max(time-i, ans);
			}
		}
		std::cout << ans << std::endl;
	}
}
