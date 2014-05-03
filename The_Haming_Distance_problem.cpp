#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

vector<string> v;

int main()
{
int i,j,k=0,cas,n,h;
cin>>cas;
while(cas--)
    {
    v.clear();
    if(k)
        cout<<endl;
    k=1;
    string s;
    cin>>n>>h;
    for(i=0;i<(n-h);i++)
        s+='0';
    for(i=0;i<h;i++)
        s+='1';
    //cout<<s<<endl;
    v.push_back(s);
    while(next_permutation(s.begin(),s.end()))
        v.push_back(s);
    sort(v.begin(),v.end());
    int len=v.size();
    for(i=0;i<len;i++)
        cout<<v[i]<<endl;
    }
}
