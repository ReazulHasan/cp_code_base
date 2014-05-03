#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<stack>
using namespace std;

vector<int> v[1000];
int color[1000];
stack<int> st;

int DFS(int x)
{
int i,j,k;
color[x]=1;
int len=v[x].size();
for(i=0;i<len;i++)
    if(color[v[x][i]]==0)
        DFS(v[x][i]);
st.push(x);
return 0;
}

int col[1000],coun=0;

int visit(int x)
{
int i,j;
coun++;
col[x]=1;
int len=v[x].size();
for(i=0;i<len;i++)
    if(col[v[x][i]]==0)
        visit(v[x][i]);
return 0;
}

int main()
{
int n,i,j,k;
while(cin>>n&&n)
    {
    for(i=0;i<=n;i++)
        {
        color[i]=0;
        v[i].clear();
        }
    int x,inp;
    for(i=1;i<=n;i++)
        {
        cin>>x;
        for(j=1;j<=x;j++)
            {
            cin>>inp;
            v[i].push_back(inp);
            }
        }
    for(i=1;i<=n;i++)
        if(color[i]==0)
            DFS(i);
    int maxn=0,res;
    while(!st.empty())
        {
        coun=0;
        for(i=0;i<=n;i++)
            col[i]=0;
        int it=st.top();
        st.pop();
        visit(it);
        //cout<<it<<" "<<coun<<endl;
        if(maxn<=coun)
            {
            res=it;
            maxn=coun;
            }
        }
    cout<<res<<endl;
    }
return 0;
}
