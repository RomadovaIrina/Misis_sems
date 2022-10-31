#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <array>




int main()
{
	int t;
	std::cin >> t;
	for (int tt = 0; tt < t; tt += 1) {
		int m, n, minH=1000, minL=1000,h=1000, l=1000;
		std::cin >> n >> m;
		for (int i = 0; i < n; i += 1) {
			std::string s;
			std::cin >> s;
			for (int j = 0; j < m; j += 1) {
				if (s[j] == 'R') {
					minH = std::min(minH, i);//мин робот до верхней границы
					minL = std::min(minL, j);//мин робот до левой
					if (i < h && j < l) {//если обе координаты R в пределах поля и минимальны
						h = i;//то запоминаем как минимального робота
						l = j;
					}
				}
			}
		}
		if (minH == h && minL == l) {//если на координтах мин расстояния есть мин робот, то можем провести
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
}
