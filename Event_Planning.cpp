#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
using namespace std;

int main()
{
int per,budg,hot,wee,i,j,k;
while(cin>>per>>budg>>hot>>wee)
    {
    pair<int,int> pa;
    vector<pair<int,int> >vcost;
    vector<int> vbed[100];
    for(i=1;i<=hot;i++)
        {
        int n;
        cin>>n;
        pa.first=n;
        pa.second=i;
        vcost.push_back(pa);
        for(j=0;j<wee;j++)
            {
            int m;
            cin>>m;
            vbed[i].push_back(m);
            }
        }
    int flag=0;
    sort(vcost.begin(),vcost.end());
    //int len=vcost.size();
    for(i=0;i<hot;i++)
        {
        int now=vcost[i].first;
        int pos=vcost[i].second;
        sort(vbed[pos].begin(),vbed[pos].end());
        int len=vbed[pos].size();
        int total=per*now;
        if(vbed[pos][len-1]>=per&&total<=budg)
            {
            cout<<total<<endl;
            flag=1;
            break;
            }
        }
    if(flag==0)
        cout<<"stay home"<<endl;
    }
return 0;
}
