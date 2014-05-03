#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
int i,j,k,cas,kas=0;
cin>>cas;
while(cas--)
    {
    kas++;
    int maxn=0,a[100];
    string s[100];
    for(i=0;i<10;i++)
        {
        cin>>s[i]>>a[i];
        if(maxn<a[i])
            maxn=a[i];
        }
    cout<<"Case #"<<kas<<":"<<endl;
    for(i=0;i<10;i++)
        if(a[i]==maxn)
            cout<<s[i]<<endl;
    }
return 0;
}
