#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
int i,j,k,n,cas=0;
while(cin>>n)
    {
    cas++;
    map<int,int> mp;
    int x,y,fl=0,bol=0,a[200],dif;
    for(i=0;i<n;i++)
        cin>>a[i];
    //sort(a,a+n);
    if(a[0]<1)
        bol=1;
    if(bol==0)
    for(i=1;i<n;i++)
        {
        if(a[i]<=a[i-1])
            {
            bol=1;
            break;
            }
        if(a[i]<1)
            {
            bol=1;
            break;
            }
        }
    if(bol==0)
    for(i=0;i<n;i++)
        {
        for(j=i;j<n;j++)
            {
            int sum=a[i]+a[j];
            if(mp[sum]==0)
                mp[sum]=1;
            else
                {
                bol=1;
                break;
                }
            }
        if(bol)
            break;
        }
    cout<<"Case #"<<cas<<": ";
    if(bol)
        cout<<"It is not a B2-Sequence."<<endl;
    else
        cout<<"It is a B2-Sequence."<<endl;
    cout<<endl;
    }
return 0;
}
