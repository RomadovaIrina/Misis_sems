#include <iostream>
#include <string>
int count_0(std::string l) {
	int counter_0 = 0;
	for (int i = 0; i < l.length(); i += 1) {
		if (l[i] == '0') {
			counter_0 += 1;
		}
	}
	return counter_0;
}
 
int count_1(std::string l) {
	int counter_1 = 0;
	for (int i = 0; i < l.length(); i += 1) {
		if (l[i] == '1') {
			counter_1 += 1;
		}
	}
	return counter_1;
}
 
bool flag = true;
void we_did_wrong() {
	flag = false;
	std::cout << "-1" << std::endl;
 
}
 
int main()
{
	std::string s;
	int t, n, count_repl = 0;
	int a, b;
	std::cin >> t;
	for (int j = 0; j < t; j += 1)
	{
		bool flg = 1;
		std::cin >> a >> b;
		std::cin >> s;
		n = s.length();
		a -= count_0(s);
		b -= count_1(s);
		if (a < 0 || b < 0) {
			we_did_wrong();
		}
 
for (int i = 0; i < n && flag; i += 1) {
			if (s[i] != s[n - i - 1] && s[i] != '?' && s[n - i - 1] != '?') {
				we_did_wrong();
			}
			else if (s[i] == '?' && s[n - i - 1] != '?') {
				if (s[n - i - 1] == '0' && a > 0)
				{
					a -= 1;
					s[i] = s[n - i - 1];
				}
				else if (s[n - i - 1] == '1' && b > 0)
				{
					b -= 1;
					s[i] = s[n - i - 1];
				}
				else {
					we_did_wrong();
				}
			}
			else if (s[n - i - 1] == '?' && s[i] != '?') {
				if (s[i] == '0' && a > 0) {
 
					a -= 1;
					s[n - i - 1] = s[i];
				}
				else if (s[i] == '1' && b > 0)
				{
					b -= 1;
					s[n - i - 1] = s[i];
				}
				else {
					we_did_wrong();
				}
			}
		}
 
		if (n % 2 == 1 && s[ceil(n / 2)]) {
			if (a % 2 != 0) {
				s[ceil(n / 2)] = '0';
				a -= 1;
			}
			else if (b % 2 != 0) {
				s[ceil(n / 2)] = '1';
				b -= 1;
			}
		}
		for (int i = 0; i < n && flag; i += 1) {
 
			
		 if (s[i] == s[n - i - 1] && s[i] == '?') {
				if (a % 2 == 0 && a >= 2) {
					s[i] = '0';
					s[n - i - 1] = s[i];
					a -= 2;
				}
				else if (b % 2 == 0 && b >= 2) {
					s[i] = '1';
					s[n - i - 1] = s[i];
					b -= 2;
				}
				else {
					we_did_wrong();
				}
			}
		}
			if (flag) {
				std::cout << s << std::endl;
			}
			else {
				flag = true;
			}
		
	}
	return 0;
}
