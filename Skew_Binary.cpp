#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
//#include<string>
using namespace std;

int a[100];

void precalc()
{
int i,j,p;
a[1]=1;
for(i=2;i<32;i++)
    {
    p=i;
    int mult=1;
    for(j=1;j<=p;j++)
        mult*=2;
    a[i]=mult-1;
    }
/*for(i=1;i<32;i++)
    cout<<a[i]<<endl;*/
}

int main()
{
int i,j,p;
char c,m;
queue<int> q;
precalc();
while(cin>>m)
{
if(m=='0')
    break;
q.push(m-'0');
while((c=getchar())!='\n')
    q.push(c-'0');
int n=q.size(),it;
int x=n;
long long res=0;
for(i=0;i<n;i++)
    {
    it=q.front();
    q.pop();
    res+=(it*a[x]);
    x--;
    }
cout<<res<<endl;
}
return 0;
}
