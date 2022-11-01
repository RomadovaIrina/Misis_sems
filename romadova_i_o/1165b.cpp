#include <iostream>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i += 1) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	int cnt = 0, k=1;
	for (int i = 0; i < n; i += 1) {
		if (a[i] >= k) {
			cnt++;
			k++;
		}
		else {
			continue;
		}
	}
	std::cout << cnt;

}
