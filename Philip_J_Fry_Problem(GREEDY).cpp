#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
int i,j,k,n,x,y;
while(cin>>n&&n)
    {
    pair<int,int> pa;
    vector<pair<int,int> > v;
    for(i=0;i<n;i++)
        {
        cin>>x>>y;
        pa.first=x;
        pa.second=y;
        v.push_back(pa);
        }
    sort(v.begin(),v.end());
    int res=0,flag[500],sphere=0,minx=91474837;
    for(i=0;i<n;i++)
        flag[i]=0;
    int fl=0;
    for(i=0;i<n;i++)
        if(v[i].second>0)
            {
            flag[i]=1;
            res+=v[i].first;
            sphere+=v[i].second;
            fl=1;
            break;
            }
    if(fl)
        {
        for(i=n-1;i>=0;i--)
            if(v[i].second>0&&flag[i]==0)
                {
                flag[i]=1;
                sphere--;
                res+=(v[i].first)/2;
                sphere+=v[i].second;
                }
        }
    for(i=n-1;i>=0;i--)
        {
        if(flag[i]==0)
            {
            flag[i]=1;
            if(sphere)
                {
                sphere--;
                res+=(v[i].first)/2;
                }
            else
                res+=v[i].first;
            }
        }
    cout<<res<<endl;
    }
return 0;
}
