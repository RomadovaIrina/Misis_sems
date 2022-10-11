#include <iostream>
#include <string>
#include <vector>

int main()
{
	int t, n, k=0;
	std::cin >> t;
	for (int r = 0; r < t; r += 1) {
		std::cin >> n;
		std::vector<int> flow(n);
		for (int j = 0; j < n; j += 1) {
			std::cin >> flow[j];
		}
		k = 1;
		for (int i = 1; i < n; i += 1) {
			if (flow[i] == flow[i - 1]) {
				if (flow[i] == 1) {
					k += 5;
				}
				else {
					k = -1;
					break;
				}
			}
			else if (flow[i] == 1 && flow[i - 1] == 0) {
				k += 1;
			}
		}
		if (flow[0]==1 && k!=-1) {
			k += 1;
		}
		std::cout << k << std::endl;
		k = 1;
	}
}
