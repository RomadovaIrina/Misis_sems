#include <iostream>



int main()
{
	int n, k, ans=101, p;
	std::cin >> n>>k;
	for (int i = 0; i < n; i += 1) 
	{
		std::cin >> p;
		if (k % p == 0) {
			ans = std::min(ans, k / p);
		}
	}
	std::cout << ans;

}
