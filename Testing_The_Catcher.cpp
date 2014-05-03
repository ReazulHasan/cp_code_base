#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

vector<int> v,ind;

int LIS()
{
int i,j,k;
int len=v.size();
vector<int> prev(len);
ind.push_back(0);
for(i=1;i<len;i++)
    {
    if(v[i]>=v[ind.back()])
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
            if(v[i]>=v[ind[mid]])
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
int ln=ind.size();
cout<<"  maximum possible interceptions: "<<ln<<endl;
return 0;
}

int main()
{
int i,j,k,n,coun=0;
vector<int> inp;
while(cin>>n)
    {
    if(n==-1)
        break;
    inp.push_back(n);
    while(cin>>n)
        {
        if(n==-1)
            break;
        inp.push_back(n);
        }
    int ln=inp.size();
    for(i=ln-1;i>=0;i--)
        v.push_back(inp[i]);
    if(coun)
        cout<<endl;
    coun++;
    cout<<"Test #"<<coun<<":"<<endl;
    LIS();
    v.clear(); ind.clear(); inp.clear();
    }
}
