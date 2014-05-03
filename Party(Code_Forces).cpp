#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<stack>
using namespace std;

vector<int> v[3000];
stack<int> st;
int color[3000],col[3000],coun=0;

int DFS(int a)
{
color[a]=1;
int i,j,k;
for(i=0;i<v[a].size();i++)
    if(color[v[a][i]]==0)
        DFS(v[a][i]);
st.push(a);
}

int go(int a)
{
int i,j,k;
//cout<<a<<endl;
coun++;
col[a]=1;
for(i=0;i<v[a].size();i++)
    if(col[v[a][i]]==0)
        go(v[a][i]);
col[a]=0;
return 0;
}

int main()
{
int i,j,k,n,x;
cin>>n;
for(i=0;i<=n;i++)
    {
    color[i]=0;
    col[i]=0;
    }
for(i=1;i<=n;i++)
    {
    cin>>x;
    if(x!=-1)
        v[i].push_back(x);
    }
for(i=1;i<=n;i++)
    if(color[i]==0)
        DFS(i);
int maxn=0;
while(!st.empty())
    {
    int m=st.top();
    st.pop();
    if(col[m]==0)
        {
        coun=0;
        //cout<<m<<endl;
        go(m);
        if(maxn<coun)
            maxn=coun;
        }
    }
cout<<maxn<<endl;
return 0;
}
