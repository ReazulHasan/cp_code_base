#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
typedef long long ll;
using namespace std;

int main()
{
int i,j,k,cas,n,kas=0,x;
cin>>cas;
while(cas--)
    {
    int mil=0,juc=0,a,b;
    kas++;
    cin>>n;
    for(i=0;i<n;i++)
        {
        cin>>x;
        a=x/30+1;
        b=x/60+1;
        mil+=a*10;
        juc+=b*15;
        }
    cout<<"Case "<<kas<<": ";
    if(mil==juc)
        cout<<"Mile Juice "<<mil<<endl;
    else if(mil<juc)
        cout<<"Mile "<<mil<<endl;
    else
        cout<<"Juice "<<juc<<endl;
    }
return 0;
}
