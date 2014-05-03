#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
using namespace std;

vector<int> v[10000];
map<string,int> mp1;
map<int,string> mp2;
stack<int> st;

int color[10000],cost[10000],prev[10000],z;

int BFS(int s,int d)
{
int i,j;
queue<int> q;
q.push(s);
for(i=0;i<z;i++)
    {
    color[i]=0;
    cost[i]=0;
    prev[i]=0;
    }
color[s]=1;
//cout<<" "<<d<<endl;
while(!q.empty())
    {
    int now;
    now=q.front();
    q.pop();
    //cout<<"now "<<now;
    if(now==d)
        return 1;
    for(i=0;i<v[now].size();i++)
        {
        if(color[v[now][i]]==0)
            {
            color[v[now][i]]=1;
            cost[v[now][i]]=cost[now]+1;
            prev[v[now][i]]=now;
            q.push(v[now][i]);
            }
        }
    }
return 0;
}

int main()
{
int i,j,t,s,d,res,flg=0;
string s1,s2;
while(cin>>t)
    {
    mp1.clear();
    mp2.clear();
    int n=1;
    for(i=0;i<t;i++)
        {
        cin>>s1>>s2;
        if(mp1[s1]==0)
            {
            mp1[s1]=n;
            mp2[n]=s1;
            n++;
            }
        if(mp1[s2]==0)
            {
            mp1[s2]=n;
            mp2[n]=s2;
            n++;
            }
        //cout<<s1<<" "<<mp1[s1]<<" "<<s2<<" "<<mp1[s2]<<endl;
        v[mp1[s1]].push_back(mp1[s2]);
        v[mp1[s2]].push_back(mp1[s1]);
        }
    z=n+10;
    cin>>s1>>s2;
    s=mp1[s1]; d=mp1[s2];
    if(flg)
        cout<<endl;
    flg=1;
    if(s==0||d==0)
        cout<<"No route"<<endl;
    //cout<<s<<" "<<d;
    else
        {
        res=BFS(s,d);
        if(res==0)
            cout<<"No route"<<endl;
        else
            {
            while(d!=s)
                {
                st.push(d);
                d=prev[d];
                }
            st.push(d);
            int r=st.top();
            st.pop();
            while(!st.empty())
                {
                int p=st.top();
                st.pop();
                cout<<mp2[r]<<" "<<mp2[p]<<endl;
                r=p;
                }
            }
        }
        for(i=0;i<z;i++)
            v[i].clear();
    }
return 0;
}
