#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
string s;
int i,j,k,n;
while(cin>>s)
    {
    vector<int> v;
    int len=s.size();
    for(i=0;i<len;i++)
        {
        int it=s[i]-'0';
        v.push_back(it);
        }
    sort(v.begin(),v.end());
    i=0;
    while(v[i]==0)
        i++;
    long long smal=0,big=0,sub,mult;
    smal+=v[i];
    for(j=0;j<i;j++)
        smal*=10;
    for(j=i+1;j<len;j++)
        {
        smal*=10;
        smal+=v[j];
        }
    for(i=len-1;i>=0;i--)
        {
        big*=10;
        big+=v[i];
        }
    sub=big-smal;
    mult=sub/9;
    cout<<big<<" - "<<smal<<" = "<<sub<<" = 9 * "<<mult<<endl;
    }
return 0;
}
