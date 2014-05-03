#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
int t,n;
cin>>t;
while(t--)
    {
    cin>>n;
    long long res;
    res=n*567;
    res/=9;
    res+=7492;
    res*=235;
    res/=47;
    res-=498;
    res/=10;
    int x=res%10;
    if(x<0)
        x*=-1;
    cout<<x<<endl;
    }
return 0;
}
