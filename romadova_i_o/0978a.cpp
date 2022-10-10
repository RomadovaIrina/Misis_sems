#include <iostream>
#include <array>

int main()
{
    const int n_max=50;
    std::array<int, n_max> a{0};
    int n, temp=0;
    std::cin>>n;
    for (int i=0;i<n;i+=1)
    {
        std::cin>>a[i];
    }
    for (int i=n-1; i>0; i-=1)
    {
        for (int j=i-1; j>=0; j-=1)
        {
            if (a[j]==a[i])
            {
                a[j]=-1;
            }
        }
    }
    int leng=0;
    for (int i=0; i<n; i+=1)
    {
        if (a[i]!=-1)
        {
            leng+=1;
        }
    }
    std::cout<<leng<<std::endl;
    for (int i=0; i<n;i+=1)
    {
            if (a[i]!=-1){
                std::cout<<a[i]<<" ";
            }
    }
}
