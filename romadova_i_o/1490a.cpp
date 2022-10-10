#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main() 
{
	int t,n, nums=0;
	std::cin >> t;
	for (int q=0; q < t; q += 1) 
	{
		std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; i += 1) {
			std::cin >> a[i];
		}
		for (int i = 0; i < a.size()-1; i += 1) {
			int mina = std::min(a[i], a[i + 1]), maxa=std::max(a[i], a[i+1]);
			while (mina*2<maxa) {
				mina *= 2;
				nums += 1;

			}
		}
		std::cout << nums << std::endl;
		nums = 0;

	}

}
