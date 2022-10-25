#include <iostream>
#include <string>

int main()
{
	int n;

	std::cin >> n;
	int k = 0;
	while (n)
	{
		k += (n & 1);
		n >>= 1;
	}
	std::cout << k;
}
