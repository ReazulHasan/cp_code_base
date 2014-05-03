#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
vector<int> v;
int a[150],i,n,x,j,team1=0,team2=0,item;
cin>>n;
for(i=1;i<=n;i++)
    {
    cin>>x;
    v.resize(x);
    for(j=0;j<x;j++)
        cin>>v[j];
    sort(v.begin(),v.end());
    team1=v[0];
    team2=v[x-1];
    int k=1;
    while(team1<=team2&&k<x-1)
        {
         team1+=v[k++];
        }
    if(k<x-1)
    {
    team1+=v[k++];
    for(j=k;j<x-1;)
        {
         if(team1<team2)
                {
                    team2+=v[j++];
                    team1+=v[j++];
                }
        else
            {
                team1+=v[j++];
                team2+=v[j++];
            }
        }
    }
    cout<<team1<<" "<<team2<<endl;
    team1=0; team2=0;
    }
}
