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
stack<int> st;
queue<int> q;
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
st.push(x);
return 0;
}

int dfs_visit(int x)
{
int i,j,k;
color[x]=1;
//q.push(x);
//cout<<x<<endl;
coun++;
int len=v[x].size();
for(i=0;i<len;i++)
    {
    if(color[v[x][i]]==0)
        dfs_visit(v[x][i]);
    /*else
        coun+=cos[v[x][i]];*/
    }
return 0;
}

int main()
{
int i,j,k,nod,edg,a,b,x;
while(cin>>nod>>edg)
    {
    string s,s1,s2;
    map<string,int> mp;
    if(!nod&&!edg)
        break;
    for(i=1;i<=nod;i++)
        {
        cin>>s;
        mp[s]=i;
        }
    for(i=0;i<edg;i++)
        {
        cin>>s1>>s2;
        v[mp[s2]].push_back(mp[s1]);
        v[mp[s1]].push_back(mp[s2]);
        }
    /*for(i=1;i<=nod;i++)
        {
        cout<<i<<": ";
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
        }*/
    int maxn=0;
    for(i=1;i<=nod;i++)
        if(color[i]==0)
            dfs(i);
    for(i=0;i<=nod;i++)
        {
        color[i]=0;
        //cos[i]=0;
        }
    while(!st.empty())
        {
        i=st.top();
        //cout<<i<<endl;
        st.pop();
        coun=0;
        if(color[i]==0)
            dfs_visit(i);
        if(maxn<coun)
            maxn=coun;
        }
    cout<<maxn<<endl;
    for(i=0;i<=nod;i++)
        {
        color[i]=0;
        v[i].clear();
        }
    }
return 0;
}
