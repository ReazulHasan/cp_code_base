#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

vector<int> v[1000009];

int main()
{
int i,j,k,ele,quer,x,pos,it;
while(cin>>ele>>quer)
    {
    int mx=0;
    for(i=1;i<=ele;i++)
        {
        cin>>x;
        v[x].push_back(i);
        if(mx<x)
            mx=x;
        }
    for(i=1;i<=quer;i++)
        {
        cin>>pos>>it;
        int len=v[it].size();
        //cout<<len<<endl;
        if(len>0&&len>=pos)
            cout<<v[it][pos-1]<<endl;
        else
            cout<<"0"<<endl;
        }
    for(i=0;i<=mx;i++)
        v[i].clear();
    }
return 0;
}
