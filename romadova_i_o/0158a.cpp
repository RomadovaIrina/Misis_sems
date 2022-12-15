#include <iostream>

int main()
{
    int n,k, player=0;//p-person
    std::cin>>n>>k;
    int balls[n];
    for (int i=0; i<n;i+=1)
        {
        std::cin>>balls[i];
    }
    for (int i=0; i<n;i+=1){
        if (balls[i]>=balls[k-1] && balls[i]>0){
            player+=1;
        }
    }
    std::cout<<player;
}
