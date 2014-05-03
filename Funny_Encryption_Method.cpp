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
int i,j,k,cas,n;
cin>>cas;
while(cas--)
    {
    cin>>n;
    int a=n,dec=0,hex=0;
    while(a>0)
        {
        if(a%2)
            dec++;
        a/=2;
        }
    a=n;
    while(a>0)
        {
        int x=a%10;
        a/=10;
        while(x>0)
            {
            if(x%2)
                hex++;
            x/=2;
            }
        }
    cout<<dec<<" "<<hex<<endl;
    }
return 0;
}
