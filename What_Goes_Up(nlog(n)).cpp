#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

vector<int> v;
vector<int> ind;

int LIS()
{
int i,j,k;
int len=v.size();
vector<int> prev(len);
ind.push_back(0);
for(i=1;i<len;i++)
    {
    if(v[i]>v[ind.back()])
        {
        prev[i]=ind.back();
        ind.push_back(i);
        }
    else
        {
        int lo=0,hi=ind.size()-1;
        while(lo<hi)
            {
            int mid=(lo+hi)/2;
            if(v[i]>v[ind[mid]])
                lo=mid+1;
            else
                hi=mid;
            }
        if(v[i]<v[ind[lo]])
            {
            if(lo>0)
                prev[i]=ind[lo-1];
            ind[lo]=i;
            }
        }
    }
int now=ind.back();
int ln=ind.size();
int m=ln;
cout<<m<<endl;
cout<<"-"<<endl;
while(ln--)
    {
    ind[ln]=now;
    now=prev[now];
    }
for(i=0;i<m;i++)
    cout<<v[ind[i]]<<endl;
return 0;
}

int main()
{
int i,j,k;
string s;
while(getline(cin,s))
    {
    int len=s.size();
    if(len==0)
        break;
    int flag=0,x=0;
    for(i=0;i<len;i++)
        {
        if(s[i]=='-')
            flag=1;
        else
            {
            x*=10;
            x+=(s[i]-'0');
            }
        }
    if(flag)
        x*=-1;
    v.push_back(x);
    }
LIS();
return 0;
}
