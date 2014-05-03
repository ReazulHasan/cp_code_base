#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int main()
{
int i,j,k,cas;
cin>>cas;
while(cas--)
    {
    long long n;
    cin>>n;
    long long res=0,a=0,b=0;
    for(i=1;i*i<=n;i++)
        {
        int x=i;
        a=n/x;
        res+=a;
        int dif=b-a;
        if(dif>0)
            res+=dif*(x-1);
        b=a;
        }
    cout<<res<<endl;
    }
return 0;
}
