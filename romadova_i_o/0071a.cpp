#include <iostream>
#include <string>
 
int main()
{
    int n=0;
    std::string s;
    std::cin>>n;
    for (int i=0; i<n;i+=1)
    {
            std::cin>>s;
            if (s.length()>10)
            {
                std::cout<<s[0]<<s.length()-2<<s[s.length()-1]<<std::endl;
            }
            else{
                std::cout<<s<<std::endl;
            }
 
    }
}
