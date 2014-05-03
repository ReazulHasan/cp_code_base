#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

int main()
{
int i,j,k=0,n,cas,x;
cin>>cas;
while(cas--)
    {
    map<int,int> mp;
    k++;
    int flg=0;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
            cin>>x;
            mp[x]++;
            if(mp[x]>n)
                flg=1;
            }
    if(flg)
        cout<<"Case "<<k<<": no"<<endl;
    else
        cout<<"Case "<<k<<": yes"<<endl;
    }
return 0;
}
