#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

vector<int> v[30009];
int coun=0,color[30009];

int dfs(int x)
{
int i,j,k;
color[x]=1;
coun++;
int len=v[x].size();
for(i=0;i<len;i++)
    if(color[v[x][i]]==0)
        dfs(v[x][i]);
return 0;
}

int main()
{
int i,j,k,man,grup;
while(scanf("%d %d",&man,&grup)==2)
    {
    if(!man&&!grup)
        break;
    for(i=0;i<grup;i++)
        {
        vector<int> inp;
        int x,a,b;
        cin>>x;
        for(j=0;j<x;j++)
            {
            cin>>a;
            if(j)
                {
                v[a].push_back(b);
                v[b].push_back(a);
                }
            b=a;
            /*int len=inp.size();
            for(k=0;k<len;k++)
                {
                b=inp[k];
                v[a].push_back(b);
                v[b].push_back(a);
                }
            inp.push_back(a);*/
            }
        }
    int ln=v[0].size();
    coun=0;
    dfs(0);
    printf("%d\n",coun);
    //cout<<coun<<endl;
    for(i=0;i<man;i++)
        {
        v[i].clear();
        color[i]=0;
        }
    }
return 0;
}
