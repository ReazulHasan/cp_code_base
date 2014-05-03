#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;

int main()
{
string s[1000],s1;
int i,j,k,t,n,coun=0;
cin>>t;
while(t--)
    {
    coun++;
    map<string,int> mp;
    cin>>n;
    for(i=0;i<n;i++)
        {
        int c;
        cin>>s[i]>>c;
        mp[s[i]]=c;
        }
    cin>>n>>s1;
    int res=mp[s1];
    if(res==0)
        cout<<"Case "<<coun<<": Do your own homework!"<<endl;
    else if(res<=n)
        cout<<"Case "<<coun<<": Yesss"<<endl;
    else if(res<=(n+5))
        cout<<"Case "<<coun<<": Late"<<endl;
    else if(res>(n+5))
        cout<<"Case "<<coun<<": Do your own homework!"<<endl;
    }
return 0;
}
