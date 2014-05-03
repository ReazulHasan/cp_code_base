#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<utility>
#include<stack>
using namespace std;

int node,edge;
vector<int> vfront[10009],vback[10009];
stack<int> st;
int cfront[10009],cback[10009];

int DFS(int x)
{
int i,j;
cfront[x]=1;
int len=vfront[x].size();
for(i=0;i<len;i++)
    if(cfront[vfront[x][i]]==0)
        DFS(vfront[x][i]);
st.push(x);
return 0;
}

int second_DFS(int n)
{
int i;
cback[n]=1;
int len=vfront[n].size();
for(i=0;i<len;i++)
    if(cback[vfront[n][i]]==0)
        second_DFS(vfront[n][i]);
}

int main()
{
int i,j,k=0,t,x,y;
cin>>t;
while(t--)
    {
    k++;
    for(i=0;i<10005;i++)
        {
        vfront[i].clear();
        vback[i].clear();
        cfront[i]=0;
        cback[i]=0;
        }
    while(!st.empty())
        st.pop();
    cin>>node>>edge;
    for(i=0;i<edge;i++)
        {
        cin>>x>>y;
        vfront[x].push_back(y);
        vback[y].push_back(x);
        }
    int coun=0;
    for(i=1;i<=node;i++)
        if(cfront[i]==0)
            DFS(i);
    while(!st.empty())
        {
        int it=st.top();
        if(cback[it]==0)
            {
            coun++;
            second_DFS(it);
            }
        st.pop();
        }
    cout<<"Case "<<k<<": "<<coun<<endl;
    }
return 0;
}
