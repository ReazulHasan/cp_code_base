#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<stack>
using namespace std;

int color[1000000],col[1000000];
vector<int> v[1000000],vt[1000000];
stack<int> st;

int DFS1(int x)
{
color[x]=1;
int i,j;
int len=v[x].size();
for(i=0;i<len;i++)
    if(color[v[x][i]]==0)
        DFS1(v[x][i]);
st.push(x);
return 0;
}

int visit(int x)
{
int i,j;
col[x]=1;
int len=vt[x].size();
for(i=0;i<len;i++)
    if(col[vt[x][i]]==0)
        visit(vt[x][i]);
return 0;
}

int main()
{
int nod,edg,i,j,k;
string s,sp;
while(cin>>nod>>edg)
    {
    if(nod==0&&edg==0)
        break;
    map<string,int> mpstr;
    map<int,string> mpint;
    for(i=0;i<=nod;i++)
        {
        v[i].clear();
        vt[i].clear();
        color[i]=0;
        col[i]=0;
        }
    k=1;
    getline(cin,sp);
    for(i=1;i<=nod;i++)
        {
        getline(cin,s);
        mpstr[s]=k;
        mpint[k]=s;
        k++;
        }
    string s1,s2;
    for(i=1;i<=edg;i++)
        {
        getline(cin,s1);
        getline(cin,s2);
        int x=mpstr[s1];
        int y=mpstr[s2];
        v[x].push_back(y);
        vt[y].push_back(x);
        }
    for(i=1;i<=nod;i++)
        if(color[i]==0)
            DFS1(i);
    int coun=0;
    while(!st.empty())
        {
        int it=st.top();
        st.pop();
        if(col[it]==0)
            {
            //cout<<it<<" ";
            coun++;
            visit(it);
            }
        }
    cout<<coun<<endl;
    /*for(i=1;i<=nod;i++)
        cout<<mpint[i]<<endl;*/
    }
return 0;
}
