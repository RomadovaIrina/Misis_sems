
#include <iostream>
#include <string>

int main()
{
	int t;
	std::cin >> t;
	bool flag = 1;
	for (int q = 0; q < t; q += 1)
	{
		std::string s;
		std::cin >> s;
		for (int i = 0; i < s.length(); i += 1) {
			if ((i == 0 || s[i] != s[i - 1]) && (i == s.length() - 1 || s[i] != s[i + 1])) {
				flag = 0;
			}
		}
		if (flag) {
			std::cout << "Yes" << std::endl;
		}
		else {
			std::cout << "No" << std::endl;
		}
		flag = 1;
	}
}

