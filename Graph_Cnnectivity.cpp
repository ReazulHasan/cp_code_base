#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

vector<int> v[9000],inp;
int color[9000];

int DFS(int x)
{
int i,j,k;
color[x]=1;
int len=v[x].size();
for(i=0;i<len;i++)
    if(color[v[x][i]]==0)
        DFS(v[x][i]);
return 0;
}

int main()
{
int t,i,j,k;
cin>>t;
while(t--)
    {
    map<int,int> mp;
    char c;
    string s,s1;
    cin>>c;
    getline(cin,s);
    while(getline(cin,s))
        {
        //cout<<s.size()<<endl;
        if(s.size()==0)
            break;
        int x=s[0]-'A'+1;
        int y=s[1]-'A'+1;
        v[x].push_back(y);
        v[y].push_back(x);
        if(mp[x]==0)
            {
            mp[x]=1;
            inp.push_back(x);
            }
        if(mp[y]==0)
            {
            mp[y]=1;
            inp.push_back(y);
            }
        }
    //cout<<"hi"<<endl;
    int coun=0;
    int len=inp.size();
    for(i=0;i<len;i++)
        if(color[inp[i]]==0)
            {
            coun++;
            DFS(inp[i]);
            }
    int hm=c-'A'+1;
    for(i=1;i<=hm;i++)
        if(color[i]==0)
            coun++;
    cout<<coun<<endl;
    if(t>0)
        cout<<endl;
    for(i=0;i<=3000;i++)
        {
        color[i]=0;
        v[i].clear();
        }
        inp.clear();
    }
//cout<<"hi";
return 0;
}
