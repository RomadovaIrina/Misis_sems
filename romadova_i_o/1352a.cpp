#include <iostream>
#include <cmath>
int main()
{
    int n,k;
    std::cin>>n;
    for (int i=0; i<n; i+=1)
    {
        int t, tmp=0, k=0;
        std::cin>>t;
        tmp=t;
        while(tmp>0)
        {
            if ((tmp%10)!=0)
            {
                k+=1;
            }
            tmp/=10;
        }
        std::cout<<k<<std::endl;
        int step=0;
        while(t>0)
        {
            int tt=t%10;
            if (tt!=0)
            {
                std::cout<<tt*pow(10, step)<<" ";
            }
            step+=1;
            t/=10;
        }
    }
}
