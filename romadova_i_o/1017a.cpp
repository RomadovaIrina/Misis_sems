#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <array>
#include <set>
#include <algorithm>


int main()
{
	int n;
	std::cin >> n;
	int x1, x2, x3, x4;
	std::cin >> x1 >> x2 >> x3 >> x4;
	int s_std = x1 + x2 + x3 + x4;
	int ans = 1;
	for (int i=1; i<n; i+=1){
		std::cin >> x1 >> x2 >> x3 >> x4;
		if (x1 + x2 + x3 + x4 > s_std) {
			ans += 1;
		}
	}
	std::cout << ans;

}
