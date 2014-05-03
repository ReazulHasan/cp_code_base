#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int n;
while(cin>>n)
    {
    int res=n;
    while(n>=3)
        {
        res+=n/3;
        int ex=n%3;
        n/=3;
        n+=ex;
        }
    if(n==2)
        res++;
    cout<<res<<endl;
    }
return 0;
}
