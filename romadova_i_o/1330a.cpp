#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	int n, x, t, temp;
	std::cin >> t;
	for (int y = 0; y < t; y += 1) {
		std::cin >> n >> x;
		std::vector <int> a(n);

		for (int i = 0; i < n; i += 1)
		{
			std::cin >> a[i];
		}
		sort(a.begin(), a.end());
		std::vector <int> chek(250);
		for (int j = 0; j < n; j += 1) {
			chek[a[j] - 1] = 1;
		}
		for (int k = 0; k < chek.size(); k += 1) {
			if (chek[k] == 0) {
				chek[k] = 1;
				x -= 1;
			}
			if (x == 0) {
				break;
			}
			
		}
		for (int d = 0; d < chek.size(); d += 1) {
			if (chek[d] == 0) {
				std::cout << d<<std::endl;
				break;
			}
		}
	}

}
