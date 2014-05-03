#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<deque>
#include<stack>
using namespace std;

vector<int> v[1009];
int color[1009],prev[1009],k=0;
stack<int> st;

int BFS(int star,int en)
{
int i,j;
for(i=0;i<=k;i++)
    {
    color[i]=0;
    prev[i]=0;
    }
queue<int> q;
color[star]=1;
prev[star]=-1;
q.push(star);
//cout<<star<<" "<<en<<endl;
while(!q.empty())
    {
    int x=q.front();
    //cout<<x<<endl;
    if(x==en)
        break;
    q.pop();
    int len=v[x].size();
    for(i=0;i<len;i++)
        {
        int now=v[x][i];
        if(color[now]==0)
            {
            color[now]=1;
            prev[now]=x;
            q.push(now);
            }
        }
    }
return 0;
}

int print_path(int x)
{
//cout<<x<<endl;
st.push(x);
if(prev[x]==-1)
    return 1;
return print_path(prev[x]);
}

int main()
{
int i,j,nod,quer,cas,fl=0;
cin>>cas;
while(cas--)
    {
    map<string,int> mpstr;
    map<int,string> mpint;
    cin>>nod>>quer;
    string s1,s2;
    k=1;
    for(i=0;i<nod;i++)
        {
        cin>>s1>>s2;
        if(mpstr[s1]==0)
            {
            mpstr[s1]=k;
            mpint[k]=s1;
            k++;
            }
        if(mpstr[s2]==0)
            {
            mpstr[s2]=k;
            mpint[k]=s2;
            k++;
            }
        v[mpstr[s1]].push_back(mpstr[s2]);
        v[mpstr[s2]].push_back(mpstr[s1]);
        }
    if(fl)
        cout<<endl;
    fl=1;
    for(j=0;j<quer;j++)
        {
        cin>>s1>>s2;
        int x=mpstr[s1],y=mpstr[s2];
        //cout<<x<<" "<<y<<endl;
        BFS(x,y);
        print_path(y);
        while(!st.empty())
            {
            int x=st.top();
            st.pop();
            s1=mpint[x];
            cout<<s1[0];
            }
        cout<<endl;
        }
    /*for(i=1;i<k;i++)
        {
        cout<<i<<"  ";
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
        }*/
    for(i=0;i<=k;i++)
        {
        v[i].clear();
        }
    }
return 0;
}
