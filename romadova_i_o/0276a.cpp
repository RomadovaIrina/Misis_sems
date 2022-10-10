#include <iostream>

int main()
{
    int n,k=1;
    std::cin>>n>>k;
    int max_sat= -10000000000;
    for (int i=0; i<n; i+=1)
    {
        int f,t;
        int obed=-1000000;
        std::cin>>f>>t;
        if (t>k){
            obed=f-t+k;
        }
        if (k>=t){
            obed=f;
        }
        if (obed>max_sat){
            max_sat=obed;
        }
    }
    std::cout<<max_sat;
}
