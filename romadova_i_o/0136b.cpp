#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> f(int x)
{
	std::vector<int> t;
	int coun = 0;
	while (x)
	{
		t.push_back(x % 3);
		x /= 3;
		coun += 1;
	}
	t.resize(32);
	for (int i = 0; i < t.size()/2; i += 1) {
		int trm = t[i];
		t[i] = t[t.size() - i-1];
		t[t.size() - i-1] = trm;
	}
	return t;
}
long long f(std::vector<int>& t)
{
	long long  r = 0;
	int step = 32;
	for (int i = 0; i < t.size(); i += 1) {
		step -= 1;
		r += t[i] * (std::pow(3, step));
	}
	return r;
}

int main()
{
	int a,c;
	std::cin >> a >> c;
	std::vector<int> a_3 = f(a), c_3 = f(c);
	std::vector<int> b_3(32);
	for (int i = 0; i < a_3.size(); i += 1)
	{
		if (c_3[i] < a_3[i]) {
			b_3[i] = ((c_3[i] + 3) - a_3[i]);
		}
		else {
			b_3[i] = (c_3[i] - a_3[i]);
		}
	}
	std::cout << f(b_3);

}
