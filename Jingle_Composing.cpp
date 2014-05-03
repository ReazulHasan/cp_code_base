#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;

int main()
{
int i,j,k;
string s;
map<char,int> mp;
mp['W']=1; mp['H']=2; mp['Q']=4; mp['E']=8; mp['S']=16;
mp['T']=32; mp['X']=64;
while(cin>>s)
    {
    int len=s.size(),coun=0;
    i=0;
    if(s[0]=='*')
        break;
    while(i<(len-1))
        {
        if(s[i]=='/')
            {
            vector<int> v;
            i++;
            int mx=0;
            while(s[i]!='/'&&i<len)
                {
                int x=mp[s[i]];
                v.push_back(x);
                if(mx<x)
                    mx=x;
                i++;
                }
            int up=0,sz=v.size();
            for(j=0;j<sz;j++)
                up+=mx/v[j];
            if(up==mx)
                coun++;
            }
        }
    cout<<coun<<endl;
    }
return 0;
}
