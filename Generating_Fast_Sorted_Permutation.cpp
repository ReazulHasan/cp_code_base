#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<deque>
#include<algorithm>
#include<map>
using namespace std;

vector<char> v;
vector<string> vstr;
map<string,int> mp,mp1;
long long coun=0;

int permut(int star,int n)
{
int i,j,k;
string s1;
if(star==n-1)
    {
    s1.clear();
    for(i=0;i<n;i++)
        s1+=v[i];
    if(coun<1000000)
        {
        if(mp[s1]==0)
            {
            coun++;
            mp[s1]=1;
            vstr.push_back(s1);
            }
        }
    else if(coun>=1000000)
        {
        if(mp1[s1]==0)
            {
            coun++;
            mp1[s1]=1;
            vstr.push_back(s1);
            }
        }
    }
else
    for(i=star;i<n;i++)
        {
        int temp=v[i];
        v[i]=v[star];
        v[star]=temp;
        permut(star+1,n);
        v[star]=v[i];
        v[i]=temp;
        }
return 0;
}

int main()
{
int i,j,k,cas,fl=0;
string s;
cin>>cas;
while(cas--)
    {
    cin>>s;
    int ln=s.size();
    for(i=0;i<ln;i++)
        v.push_back(s[i]);
    sort(v.begin(),v.end());
    coun=0;
    permut(0,ln);
    sort(vstr.begin(),vstr.end());
    /*if(fl)
        cout<<endl;
    fl=1;*/
    int len=vstr.size();
    for(i=0;i<len;i++)
        cout<<vstr[i]<<endl;
    cout<<endl;
    v.clear(); s.clear(); vstr.clear(); mp.clear(); mp1.clear();
    }
return 0;
}
