#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

int main()
{
char a[100][100];
int t,i,j,k,ro,co,hi,lo,m=0;
cin>>t;
while(t--)
    {
    m++;
    map<char,int> mp;
    cin>>ro>>co>>hi>>lo;
    for(i=0;i<ro;i++)
        cin>>a[i];
    int big=0;
    for(i=0;i<ro;i++)
        for(j=0;j<co;j++)
            {
            mp[a[i][j]]++;
            if(big<mp[a[i][j]])
                big=mp[a[i][j]];
            }
    char c;
    int res=0;
    for(c='A';c<='Z';c++)
        if(mp[c]!=0)
            {
            if(mp[c]==big)
                res+=big*hi;
            else
                res+=mp[c]*lo;
            }
    cout<<"Case "<<m<<": "<<res<<endl;
    }
return 0;
}
