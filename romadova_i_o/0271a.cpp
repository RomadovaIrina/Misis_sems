#include <iostream>

int main()
{
    int i=0;
    std::cin>>i;
    for ( i=i+1; i<=9999; i++){
        int a=i/1000;
        int b=(i-1000*a)/100;
        int c=(i-1000*a-100*b)/10;
        int d=i%10;
        bool q = a != b; q = q && a != c;
        q = q && a != d;
        q = q && b != c;
        q = q && b != d;
        q = q && c != d;
        if (q){
            std::cout<<i;
            break;
        }
        
    }

}
