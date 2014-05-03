#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int main()
{
int i,j,k;
string s1,s2;
while(cin>>s1>>s2)
    {
    int res[8009];
    for(i=0;i<=800;i++)
        res[i]=0;
    int len1=s1.size();
    int len2=s2.size();
    k=800;
    for(i=len1-1;i>=0;i--)
        {
        int pos=k;
        int x=s1[i]-'0';
        int car=0,lat=0;
        for(j=len2-1;j>=0;j--)
            {
            int y=s2[j]-'0';
            int now=x*y+car;
            int rem=now%10;
            car=now/10;
            int hm=res[pos]+rem+lat;
            lat=hm/10;
            res[pos]=hm%10;
            //cout<<res[pos]<<" ";
            pos--;
            }
        if(car>0||lat>0)
            res[pos]+=car+lat;
        //cout<<endl;
        k--;
        }
    int fl=0;
    for(i=0;i<=800;i++)
        {
        if(res[i]!=0)
            fl=1;
        if(fl)
            cout<<res[i];
        }
    if(fl==0)
        cout<<"0";
    cout<<endl;
    }
return 0;
}
