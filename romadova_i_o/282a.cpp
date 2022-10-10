#include <iostream>
#include <string>

int main()
{
    int n,x=0,i;
    std::string s;
    std::cin>>n;
    for (int i=0; i<n;i+=1)
    {
        std::cin>>s;
        if (s[0]=='-' || s[1]=='-'){
            x-=1;
        }
        else{
            x+=1;
        }
    }
    std::cout<<x;
}
