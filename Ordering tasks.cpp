#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdio>
#include<stack>
#include<map>
using namespace std;

vector<int> v[1000],vn;
int color[1000];
stack<int> st;

int DFS(int x)
{
color[x]=1;
int len=v[x].size();
int i,j;
for(i=0;i<len;i++)
    if(color[v[x][i]]==0)
        DFS(v[x][i]);
st.push(x);
return 0;
}

int main()
{
int node,edge,i,j,k;
while(cin>>node>>edge)
    {
    if(node==0&&edge==0)
        break;
    int x,y;
    map<int,int> mp;
    for(i=1;i<=edge;i++)
        {
        cin>>x>>y;
        if(mp[x]==0)
            {
            vn.push_back(x);
            mp[x]=1;
            }
        if(mp[y]==0)
            {
            vn.push_back(y);
            mp[y]=1;
            }
        v[x].push_back(y);
        }
    int len=vn.size();
    for(i=1;i<=node;i++)
        {
        int it=i;
        if(color[it]==0)
            {
            DFS(it);
            //st.push(it);
            }
        }
    while(!st.empty())
        {
        int now=st.top();
        st.pop();
        cout<<now<<" ";
        }
    cout<<endl;
    for(i=0;i<=node;i++)
        {
        v[i].clear();
        color[i]=0;
        }
    vn.clear();
    }
return 0;
}
