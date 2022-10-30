
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int count_2(int num) {
	int cnt = 0;
	if (num == 0) {
		return 0;
	}
	while (num%2 == 0) {
		num /= 2;
		cnt += 1;
	}
	return cnt;
}

int main()
{
	int t;
	std::cin >> t;
	for (int tt=0; tt<t; tt+=1)
	{
		int n, p;
		int cnt_2 = 0, max_pow_2=-1;
		std::cin >> n;
		for (int i = 1; i <= n; i += 1) {
			std::cin >> p;
			cnt_2 += count_2(p);//количество двоек в числе 
			max_pow_2 = std::max( (int) std::log2(p), i);//макс степень двойки для чисел
		}
		if (cnt_2 >= n) {
			std::cout << 0 << std::endl;
			continue;
		}

		bool flg = false;
		std::vector<int> pows_2(max_pow_2 + 1); //массив из степеней двойки от 0 до макс в числах, храним количество двоек к индексах
		for (int i = 1; i <= n; i += 1) {
			if (i % 2 != 0) {//если число нечет то в разложении нет 2; по нулевому индексу +=1
				pows_2[0] += 1;
			}
			else {
				pows_2[count_2(i)] += 1; //по индексу кол-ва двоек в числе +=1
			}
		}
		int count_add = 0;
		for (int i = max_pow_2; i >= 0; i -= 1) {//по убыванию от макс степени до 0 в массиве
			for (int j = 0; j < pows_2[i]; j += 1) { //по количеству, сколько добавляем
				if (i == 0) { //если дошли до 0, там нечетные числа оно не интересно
					break;
				}
				cnt_2 += i; //кол-во двоек в пр-и +=степень двойки в массиве
				count_add += 1;//количество добавлений 
				if (cnt_2 >= n) {
					flg = true;
					break;
				}

			}
			if (flg) {
				break;
			}
		}
		if (flg) {
			std::cout << count_add << std::endl;
		}
		else {
			std::cout << -1 << std::endl;
		}

	}

}
