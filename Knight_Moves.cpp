#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

int r1,r2,c1,c2;
int po1[]={-2,-1,1,2,2,1,-1,-2};
int po2[]={1,2,2,1,-1,-2,-2,-1};

int BFS()
{
queue<int>q1,q2;
int i,j,color[100][100],cost[100][100];
for(i=0;i<100;i++)
    for(j=0;j<100;j++)
        {
        color[i][j]=0;
        cost[i][j]=0;
        }
q1.push(r1);
q2.push(r2);
//cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;
color[r1][r2]=1;
cost[r1][r2]=0;
while(!q1.empty()&&!q2.empty())
    {
    int nw1,nw2;
    nw1=q1.front();
    q1.pop();
    nw2=q2.front();
    q2.pop();
    //cout<<nw1<<" "<<nw2<<endl;
    if(nw1==c1&&nw2==c2)
        return cost[nw1][nw2];
    for(i=0;i<8;i++)
        {
        if((nw1+po1[i])>0&&(nw1+po1[i])<=8&&(nw2+po2[i])<=8&&(nw2+po2[i])>0&&color[nw1+po1[i]][nw2+po2[i]]==0)
            {
            color[nw1+po1[i]][nw2+po2[i]]=1;
            q1.push(nw1+po1[i]);
            q2.push(nw2+po2[i]);
            cost[nw1+po1[i]][nw2+po2[i]]=cost[nw1][nw2]+1;
            }
        }
    }
return 0;
}

int main()
{
int i,j,k;
char a1,a2,b1,b2;
while(cin>>a1>>a2>>b1>>b2)
    {
    r1=a1-'a'+1;
    r2=a2-'0';
    c1=b1-'a'+1;
    c2=b2-'0';
    //cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;
    int res=BFS();
    cout<<"To get from "<<a1<<a2<<" to "<<b1<<b2<<" takes "<<res<<" knight moves."<<endl;
    }
return 0;
}
