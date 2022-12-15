#include <iostream>
#include <cmath>

int main()
{
    int num=0, ans=0;
    for (int i=0; i<5;i+=1){
        for (int j=0; j<5;j+=1){
            std::cin>>num;
            if (num==1)
            {
                ans=std::abs(i-2)+std::abs(j-2);
            }
        }
    }
    std::cout<<ans;
}
