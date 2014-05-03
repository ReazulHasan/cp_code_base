#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[60009];
int color[60009];


int DFS(int x)
{
int i,j;
color[x]=1;
int len=v[x].size();
for(i=0;i<len;i++)
    if(color[v[x][i]]==0)
        DFS(v[x][i]);
}

int main()
{
int nod,edg,x,y,i,j,cas=0;
while(cin>>nod>>edg)
    {
    cas++;
    if(nod==0&&edg==0)
        break;
    for(i=1;i<=edg;i++)
        {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        }
    int coun=0;
    for(i=1;i<=nod;i++)
        if(color[i]==0)
            {
            coun++;
            DFS(i);
            }
    cout<<"Case "<<cas<<": "<<coun<<endl;
    for(i=0;i<=nod;i++)
        {
        color[i]=0;
        v[i].clear();
        }
    }
return 0;
}
