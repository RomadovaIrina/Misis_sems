#include <iostream>
#include <string>
#include <vector>


int main()
{
	int t, k = 0, n = 0;
	bool flg = 1;
	std::string s;
	unsigned char sym;
	std::cin >> t;
	for (int j = 0; j < t; j += 1)
	{
		std::cin >> n;
		std::cin >> s;
		std::cin >> k;
		std::vector<char> spec(k);
		std::vector<unsigned char> is_spec(256, '0');
		for (int l = 0; l < k; l += 1) {
			std::cin >> sym;
			is_spec[sym] = '1';
		}
		int counter = 0, max_counter = 0;
		for (int i = 0; i < s.length(); i += 1) {
			if (is_spec[s[i]] != '1') {
				counter += 1;
			}
			else {
				max_counter = std::max(counter, max_counter);
				counter = 1;
			}
		}
		std::cout << max_counter << std::endl;
	}
}

