#include <iostream>
#include <string>
#include <vector>

int main()
{
	int t;
	std::cin >> t;
	while (t)
	{
		int n, k, ans=300000;
		std::string s;
		std::cin >> n >> k;
		std::cin >> s;
		std::vector<int> sums(n + 1);
		for (int i = 1; i <= n; i += 1) {
			if (s[i-1] == 'W')
			{
				sums[i] = sums[i - 1] + 1;

			}
			else {

				sums[i] = sums[i - 1];
			}
		}
		for (int i = k; i <= n; i += 1)
		{
			ans = std::min(ans, sums[i] - sums[i - k]);
		}
		std::cout << ans << std::endl;

		t -= 1;
	}
}
