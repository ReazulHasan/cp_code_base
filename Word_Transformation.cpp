#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;

vector<int> v[500];

int color[500],cost[500];

int BFS(int x,int y)
{
int i,j,k;
queue<int> q;
q.push(x);
while(!q.empty())
    {
    int it=q.front();
    q.pop();
    if(it==y)
        return cost[it];
    int len=v[it].size();
    for(i=0;i<len;i++)
        {
        int now=v[it][i];
        if(color[now]==0)
            {
            color[now]=1;
            cost[now]=cost[it]+1;
            q.push(now);
            }
        }
    }
}

int main()
{
string s[500],star,en,s1,s2,inp;
int i,j,k,l,cas,pq=0;
cin>>cas;
while(cas--)
    {
    map<string,int> mpstr;
    map<int,string> mpint;
    k=0;
    int ind=1;
    while(cin>>s[k])
        {
        if(s[k][0]=='*')
            break;
        mpstr[s[k]]=ind;
        mpint[ind]=s[k];
        k++; ind++;
        }
    for(i=0;i<k;i++)
        {
        s1=s[i];
        int len1=s1.size();
        for(j=i+1;j<k;j++)
            {
            s2=s[j];
            int len2=s2.size();
            if(len1==len2)
                {
                int coun=0;
                for(l=0;l<len1;l++)
                    if(s1[l]!=s2[l])
                        coun++;
                if(coun==1)
                    {
                    v[mpstr[s1]].push_back(mpstr[s2]);
                    v[mpstr[s2]].push_back(mpstr[s1]);
                    }
                }
            }
        }
    getline(cin,s1);
    if(pq) cout<<endl;
    pq=1;
    while(getline(cin,inp))
        {
        i=0; star.clear(); en.clear();
        int sz=inp.size();
        if(sz==0)
            break;
        while(inp[i]!=' '&&i<sz)
            {
            star+=inp[i];
            i++;
            }
        while(inp[i]==' '&&i<sz)
            i++;
        while(inp[i]!=' '&&i<sz)
            {
            en+=inp[i];
            i++;
            }
        int x=mpstr[star],y=mpstr[en];
        for(i=0;i<=ind;i++)
            {
            color[i]=0;
            cost[i]=0;
            }
        int res=BFS(x,y);
        cout<<star<<" "<<en<<" "<<res<<endl;
        }
    for(i=0;i<=ind;i++)
        v[i].clear();
    for(i=0;i<k;i++)
        s[i].clear();
    }
}
