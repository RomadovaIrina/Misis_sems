#include <iostream>

int main()
{
    int n=0, count_tsk=0;
        std::cin>>n;
        for (int i=0; i<n;i+=1){
            int pet, vas, ton;
            std::cin>>pet>>vas>>ton;
            int s=pet+vas+ton;
            if (s>1){
                count_tsk+=1;
            }
        }
        std::cout<<count_tsk;
}
