#include <iostream>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

int main()
{
	int n;
	unsigned long long k;
	std::cin >> n >> k;
	std::queue<int> a;
	int p, p_1;
	for (int i = 0; i < n; i++) {
		std::cin >> p;
		a.push(p);
	}
	p_1 = a.front();
	a.pop();
	int cnt = 0, ans=-1;
	for (int i = 0; i < n -1; i += 1) {
		if (p_1 > a.front()) {
			int t = a.front();
			a.pop();
			a.emplace(t);
			cnt += 1;
			ans = p_1;
		}
		else if (p_1 < a.front()) {
			cnt = 0;
			a.push(p_1);
			p_1 = a.front();
			a.pop();
			cnt += 1;
			ans = p_1;
		}
		if (cnt == k) {
			ans = p_1;
			break;
		}
	}
	std::cout << p_1 << std::endl;

}
