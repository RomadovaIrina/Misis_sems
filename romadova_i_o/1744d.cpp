#include <iostream>
#include <cmath>
int f(int q)
{
    int am_2=0, div=2;
    while (q % div==0) 
    {
        am_2 += 1;
        q /= div;
    }
    return am_2;
}
int even(int q)
{
    int even_i = 0;
    for (int i = 1; i <= q; i += 1)
    {
        if (i % 2 == 0) {
            even_i += f(i);
        }
    }
    return even_i;
}

int main()
{
    int t;
    std::cin >> t;
    while (t)
    {
        int n, p = 1, temp;
        std::cin >> n;
        for (int i = 0; i < n; i += 1) {
            std::cin >> temp;
            p *= temp;
        }
        int amount_2 = f(p), n_2=even(n);
        std::cout << amount_2 << ' ' << n <<' '<<n_2<< std::endl;
        if (amount_2 >= n) {
            std::cout << 0 << std::endl;
        }
        else if( amount_2+n_2<n) {
            std::cout << -1 << std::endl;

        }
        else {
            std::cout << n - amount_2 << std::endl;
        }
        t -= 1;
    }
}
