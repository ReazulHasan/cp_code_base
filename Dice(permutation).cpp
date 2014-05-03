#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<queue>
using namespace std;

int a[100],coun=0;
map<string,int> mp;

int permut(int star,int n)
{
int i,j,k;
if(star==n-1)
    {
    string s;
    s.clear();
    for(i=0;i<n;i++)
        {
        s+=(a[i]+'0');
        //cout<<a[i];
        }
    //cout<<s<<endl;
    if(mp[s]==0)
        {
        coun++;
        mp[s]=1;
        }
    //cout<<endl;
    }
for(i=star;i<n;i++)
    {
    int temp,fl=0;
    if((i==1&&star==0)||(i==4&&star==2)||(i==5&&star==3))
        {
        temp=a[star];
        a[star]=a[i];
        a[i]=temp;
        fl=1;
        }
    permut(star+1,n);
    if(fl)
        {
        a[i]=a[star];
        a[star]=temp;
        }
    }
}

int main()
{
string s1,s2;
int i,j,k,cas;
cin>>cas;
while(cas--)
    {
    cin>>s1>>s2;
    for(i=0;i<6;i++)
        a[i]=s2[i]-'0';
    permut(0,6);
    cout<<coun<<endl;
    }
return 0;
}
