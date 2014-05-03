#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

vector<int> v[100];
stack<int> st;
int color[100],dis[100],fin[100],t=1;

int TOPO(int x)
{
int i,j;
color[x]=1;
dis[x]=t++;
int len=v[x].size();
for(i=0;i<len;i++)
    if(color[v[x][i]]==0)
        TOPO(v[x][i]);
fin[x]=t++;
st.push(x);
return 0;
}

int main()
{
int ed,i,j,x,y,n;
while(cin>>n)
{
cin>>ed;
for(i=0;i<ed;i++)
    {
    cin>>x>>y;
    v[x].push_back(y);
    }
for(i=0;i<n;i++)
    {
    if(color[i]==0)
        TOPO(i);
    }
while(!st.empty())
    {
    int p=st.top();
    st.pop();
    cout<<p<<" ";
    }
cout<<endl;
}
return 0;
}
