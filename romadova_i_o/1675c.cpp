#include <iostream>
#include <string>

int main()
{
	int t;
	std::string s;
	std::cin >> t;
	while (t)
	{
		std::cin >> s;
		bool flag = 1;
		int n = s.length();
		int first_zero = n -1, las_one =0;
		for (int i = 0; i < n; i += 1) {
			if (s[i] == '0')
			{
				first_zero = i;
				break;
			}
		}
		for (int j = n-1; j >=0; j -= 1) {
			if (s[j] == '1')
			{
				las_one = j;
				break;
			}
		}
		int ans = first_zero-las_one+1;
		std::cout << ans << std::endl;
		t -= 1;
	}
}
