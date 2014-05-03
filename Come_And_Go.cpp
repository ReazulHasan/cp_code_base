#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<cmath>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<cctype>
#include<cstdlib>
#include<algorithm>

typedef long long ll;

using namespace std;

vector<int> v[30000];
int coun=0,color[30000];

int dfs(int x)
{
int i,j,k;
color[x]=1;
coun++;
//cout<<x<<" ";
int len=v[x].size();
for(i=0;i<len;i++)
    if(color[v[x][i]]==0)
        dfs(v[x][i]);
return 0;
}

int main()
{
int i,j,k,nod,edg,a,b,x;
while(cin>>nod>>edg)
    {
    if(!nod&&!edg)
        break;
    for(i=0;i<edg;i++)
        {
        cin>>a>>b>>x;
        v[a].push_back(b);
        if(x==2)
            v[b].push_back(a);
        }
    int flg=1;
    for(i=1;i<=nod;i++)
        {
        for(j=0;j<=nod;j++)
            color[j]=0;
        coun=0;
        dfs(i);
        //cout<<endl;
        //cout<<"coun: "<<coun<<endl;
        if(coun<nod)
            {
            flg=0;
            break;
            }
        }
    cout<<flg<<endl;
    for(i=0;i<=nod;i++)
        v[i].clear();
    }
return 0;
}
