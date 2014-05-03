#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

vector<int> ind,v;

int LIS()
{
int i,j,k;
int len=v.size();
vector<int> prev(len);
cout<<len<<endl;
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
int lo,hi;
cout<<ind.size()<<"size"<<ind.back()<<endl;
for(i=0;i<ind.size();i++)
    cout<<ind[i]<<" ";
cout<<endl;
for(lo=ind.size(),hi=ind.back();lo--;hi=prev[hi])
    {
    cout<<"hi "<<hi<<endl;
    //cout<<lo<<endl;
    ind[lo]=hi;
    }
int ln=ind.size();
for(i=0;i<ln;i++)
    cout<<v[ind[i]]<<" ";
cout<<endl;
for(i=0;i<prev.size();i++)
    cout<<prev[i]<<" ";
return 0;
}

int main()
{
int i,j,k,n;
cin>>n;
for(i=0;i<n;i++)
    {
    cin>>k;
    v.push_back(k);
    }
LIS();
return 0;
}
