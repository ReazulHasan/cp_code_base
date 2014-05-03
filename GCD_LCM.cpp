#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
long long i,j,k,t,gcd,lcm;
cin>>t;
while(t--)
    {
    cin>>gcd>>lcm;
    if(gcd>lcm)
        cout<<"-1"<<endl;
    else if((gcd==lcm)||(lcm%gcd)==0)
        cout<<gcd<<" "<<lcm<<endl;
    else
        cout<<"-1"<<endl;
    }
return 0;
}
