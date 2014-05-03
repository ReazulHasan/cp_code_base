#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
string s[1000],s1;
int i,j,k;
getline(cin,s1);
int m=0,maxn=0;
while(1)
    {
    int sz=s1.size();
    if(sz==0)
        break;
    if(maxn<sz)
        maxn=sz;
    s[m++]+=s1;
    getline(cin,s1);
    }
k=0;
while(k<maxn)
    {
    for(i=m-1;i>=0;i--)
        {
        if(k<s[i].size())
            cout<<s[i][k];
        else
            cout<<' ';
        }
    cout<<endl;
    k++;
    }
return 0;
}
