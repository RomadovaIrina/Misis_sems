#include <iostream>

void print_comb(int x1, int y1, int x2, int y2, int n)
{
	std::cout << std::endl;
	if (y1 == y2) {
		int x3 = x1, y3 = (y1+1)%n, x4 = x2, y4 = (y2 +1)%n;
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < n; j += 1) {
				if ((x1 == j && y1 == i) || (x2 == j && y2 == i)
					|| (x3 == j && y3 == i) || (x4 == j && y4 == i)) {
					std::cout << "*";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}

	}
	else if (x1 == x2) {
		int x3 = (x1 + 1)%n, y3 = y1, x4 = (x2 + 1)%n, y4 = y2;
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < n; j += 1) {
				if ((x1 == j && y1 == i) || (x2 == j && y2 == i)
					|| (x3 == j && y3 == i) || (x4 == j && y4 == i)) {
					std::cout << "*";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}

	}
	else {
		int x3 = x1, y3 = y2, x4 = x2, y4 = y1;
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < n; j += 1) {
				if ((x1 == j && y1 == i) || (x2 == j && y2 == i)
					|| (x3 == j && y3 == i) || (x4 == j && y4 == i)) {
					std::cout << "*";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}

	}
}

int main()
{
	int t, n;
	char sym;
	bool flag = 1;
	int x1, y1, x2, y2;
	std::cin >> t;
	for (int q = 0; q < t; q += 1) {
		std::cin >> n;
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < n; j += 1)
			{
				std::cin >> sym;
				if (sym == '*' && flag) {
					x1 = j;
					y1 = i;
					flag = 0;
				}
				else if (sym == '*' && !flag) {
					x2 = j;
					y2 = i;
				}
			}

		}
		print_comb(x1, y1, x2, y2, n);
		std::cout << std::endl;

	}
}
