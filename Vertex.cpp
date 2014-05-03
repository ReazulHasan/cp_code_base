#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<cmath>
using namespace std;

int color[100000],coun=0;
vector<int> v[100000];

int DFS(int star)
{
int i,j,k;
int len=v[star].size();
for(i=0;i<len;i++)
    if(color[v[star][i]]==0)
        {
        color[v[star][i]]=1;
        coun++;
        DFS(v[star][i]);
        }
return 0;
}

int main()
{
int i,j,k,n,x,y;
while(cin>>n&&n)
    {
    for(i=0;i<=n;i++)
        v[i].clear();
    while(cin>>x&&x)
        {
        while(cin>>y&&y)
            {
            v[x].push_back(y);
            }
        }
    int quer,star;
    cin>>quer;
    while(quer--)
        {
        coun=0;
        for(i=0;i<=n;i++)
            color[i]=0;
        cin>>star;
        DFS(star);
        cout<<n-coun;
        for(i=1;i<=n;i++)
            if(color[i]==0)
                cout<<" "<<i;
        cout<<endl;
        }
    }
return 0;
}
