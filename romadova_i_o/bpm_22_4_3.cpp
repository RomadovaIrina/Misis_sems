#include <iostream>
#include <string>

int main()
{
	std::string w_1, w_2;
	std::cin >> w_1;
	std::cin >> w_2;
	int k_1 = 0, k_2 = 0;
	int j = w_2.length()-1;
	for (int i = w_1.length()-1; (i >= 0) && (j >= 0); i -= 1, j -= 1) {
		if (w_1[i] == w_2[j]) {
			k_1 += 1;
			k_2 += 1;
		}
		else {
			break;
		}
	}
	std::cout << w_1.length() + w_2.length() - k_1 - k_2<<"\n";
}
