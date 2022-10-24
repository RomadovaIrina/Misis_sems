#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> f(std::string s)
{
	std::string local_s;
	int n = s.size();
	std::vector<std::string> A;
	for (int i = 0; i < n; i++) {
		char x = s[i];
		if (x != 'W') {
			if (x == 'R') {
				local_s = local_s + "R";
			}
			else {
				local_s = local_s + "B";
			}
		}
		else {
			if (local_s != "") {
				A.push_back(local_s);
				local_s = "";
			}
		}
		if (i == n - 1 && s[i] != 'W') {
			A.push_back(local_s);
		}
	}
	return A;
}
bool is_letter(std::string t, char l) {
	bool flaf = 0;
	for (int i = 0; i < t.length(); i += 1) {
		if (t[i] == l)
		{
			flaf = 1;
			break;
		}
	}
	return flaf;

}


int main()
{
	int t;
	std::cin >> t;
	while (t)
	{
		int n;
		std::string s;
		std::cin >> n;
		std::cin >> s;
		std::vector<std::string> d = f(s);
		bool flag = 1;
		for (int i = 0; i < d.size(); i += 1)
		{
			if (d[i].length() == 1) {
				flag = 0;
				break;
			}
			else {
				bool is_b = is_letter(d[i], 'B'), is_r = is_letter(d[i], 'R');
				if (!is_b || !is_r) {
					flag = 0;
				}
			}
		}
		if (flag) {
			std::cout << "Yes" << std::endl;
		}
		else {
			std::cout << "No" << std::endl;
		}
		t -= 1;
	}
}
