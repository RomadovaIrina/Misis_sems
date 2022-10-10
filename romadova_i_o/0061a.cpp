#include <iostream>
#include <string>
int main() 
{
    std::string n_1, n_2;
    std::cin >> n_1;
    std::cin >> n_2;
    for (int i = 0; i < n_1.length(); i += 1)
    {
        if (n_1[i] == n_2[i]) {
            std::cout << '0';
        }
        else {
            std::cout << '1';
        }
    }
}
