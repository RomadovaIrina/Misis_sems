#include <iostream>
#include <vector>
#include <cmath>
#include <string>



int main()
{
	int t;
	std::cin >> t;
	while (t)
	{
		int n, k;
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;
		int counter = 0, ans = 1000000;
		for (int i = 0; i < k; i += 1) {
			if (s[i] == 'W') {
				counter += 1;
			}
		}
		ans = std::min(counter, ans);
		for (int j = k; j < n; j += 1)
		{
			if (s[j] == 'W') {
				counter += 1;
			}
			if (s[j - k] == 'W') {
				counter -= 1;
			}
			ans = std::min(ans, counter);
		}
		std::cout << ans << std::endl;
		t -= 1;
	}

}
