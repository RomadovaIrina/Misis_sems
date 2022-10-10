#include <iostream>

int main()
{
    int n, y;
    std::cin >> n;
    for (int i = 1; i <= n; i += 1)
    {
        if (i % 2 != 0 && i!=n) {
            std::cout << "I hate that ";
        }
        else if (i == n && n % 2 != 0) {
            std::cout << "I hate it ";
        }
        else if (i == n && n % 2 == 0) {
            std::cout << "I love it ";
        }
        else {
            std::cout << "I love that ";
        }

    }
}
