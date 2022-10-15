#include <iostream>
#include <string>


int main()
{
	int n, x=0,y=0;
	std::string s;
	std::cin >> n;
	std::cin >> s;
	int pay = 0;
	for (int i = 0; i < n; i += 1)
	{
		if (s[i] == 'U') {
			y += 1;
		}
		else if (s[i] == 'R') {
			x += 1;
		}
		if (x == y && s[i]==s[i+1]) {
			pay += 1;
		}
	}
	std::cout << pay;

}
