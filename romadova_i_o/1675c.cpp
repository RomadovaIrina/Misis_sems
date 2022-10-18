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
		int first_zero = 0, las_one=0;
		for (int i = 0; i < s.length(); i += 1) {
			if (s[i] == '0' || s[i]=='?')
			{
				first_zero = i;
				break;
			}
		}
		for (int i = s.length(); i >0; i -= 1) {
			if (s[i] == '1' || s[i]=='?')
			{
				las_one = i;
				break;
			}
		}
		std::cout << std::abs(first_zero - las_one) + 1 << std::endl;
		t -= 1;
	}
}
