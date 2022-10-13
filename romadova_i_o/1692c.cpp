#include <iostream>

const int n = 8;
int main()
{
	int t;
	std::cin >> t;
	char sym;
	for (int q = 0; q < t; q += 1)
	{
	    int r = 0, c = 0;
		for (int i = 0; i < n; i += 1) {
			int prev=-1, cur=-1;
			for (int j = 0; j < n; j += 1) {
				std::cin >> sym;
				if (sym == '#' && prev==-1) {
					prev = j;
				}
				else if (sym == '#' && prev != -1) {
					cur = j;
				}

			}
			if (cur - prev == 2 && (r==0 && c==0)) {
				r = i + 2;
				c = prev + 2;
			}
			else {
				continue;
			}

		}
		std::cout << r <<" "<< c << std::endl;
	}
}
