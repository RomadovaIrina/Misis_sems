#include <iostream>
#include <string>
int factor(int num) {
	int f = 1;
	for (int i = 1; i <= num; i += 1) {
		f *= i;
	}
	return f;
}

int main()
{
	std::string w1;
	std::string w2;
	int k = 0;
	std::cin >> w1 >> w2;
	std::string w_1, w_2;
	if (w1.length() >= w2.length()) {
		w_1 = w1;
		w_2 = w2;

	}
	else {
		w_1 = w2;
		w_2 = w1;
	}
	for (int i = 0; i < w_1.length(); i += 1) {
		for (int j = 0; j < w_2.length(); j += 1) {
			if (w_1[i] == w_2[j]) {
				std::cout << w_1[i] << w_2[j] << "\n";
			}
			else {
				k += 2;
			}
		}
	}
	std::cout << k;
}
