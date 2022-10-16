#include <iostream>
#include <string>
#include <array>
#include <vector>


int main()
{
	int t,n;
	std::cin >> t;
	while (t)
	{
		std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; i += 1) {
			std::cin >> a[i];
		}
		int ans = a[0];
		for (int i = 1; i <n; i += 1)
		{
			ans &= a[i];
		}
		std::cout << ans << std::endl;
		t -= 1;
	}
}
