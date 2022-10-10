#include <iostream>
#include <string>
#include <vector>
std::string replaced(std::string& s, std::vector<char> &spec) {
	for (int i = 0; i < s.length(); i += 1) {
		for (int j = 0; j < spec.size(); j += 1) {
			if (s[i] == spec[j]) {
				s[i] = '1';
			}
		}
	}
	return s;
}

int main()
{
	int t, k=0, n=0;
	bool flg = 1;
	std::string s;
	std::cin >> t;
	for (int j = 0; j < t; j += 1) 
	{
		std::cin >> n;
		std::cin >> s;
		std::cin >> k;
		std::vector<char> spec(k);
		for (int l = 0; l < k; l += 1) {
			std::cin >> spec[l];
		}
		s = replaced(s, spec);
		int counter = 0, max_counter = 0;
		for (int i = 0; i < s.length(); i += 1) {
			if (s[i] != '1') {
				counter += 1;
			}
			else {
				max_counter = std::max(counter, max_counter);
				counter = 1;
			}
		}
		std::cout << max_counter<<std::endl;
	}
}