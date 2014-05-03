#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<map>
using namespace std;

struct ss{
int dest;
double dist;
};

vector<ss> v[100];
int com,color[100],coun=0,prev[100],see=0;
double tot=0,men=987654698;
stack<int> st;

int enstak(int x)
{
st.push(x);
if(prev[x]==-1)
    return 0;
return enstak(prev[x]);
}

int recur(int pos)
{
int i,j,k;
for(i=0;i<com-1;i++)
    {
    int nowdest=v[pos][i].dest;
    if(color[nowdest]==0)
        {
        double nowdist=v[pos][i].dist;
        tot+=nowdist;
        prev[nowdest]=pos;
        coun++;
        color[nowdest]=1;
        recur(nowdest);
        if(coun==com&&tot<men)
            {
            while(!st.empty())
                st.pop();
            enstak(nowdest);
            men=tot;
            }
        tot-=nowdist;
        coun--;
        color[nowdest]=0;
        }
    }
return 0;
}

int main()
{
ss t;
int i,j,k,x,y;
see=0;
while(cin>>com&&com)
    {
    see++;
    men=987654698;
    int vx[100],vy[100];
    for(i=0;i<=com;i++)
        {
        v[i].clear();
        vx[i]=0; vy[i]=0;
        color[i]=0;
        prev[i]=0;
        }
    for(i=1;i<=com;i++)
        {
        cin>>x>>y;
        for(j=1;j<i;j++)
            {
            int x1=vx[j],y1=vy[j];
            double dis=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
            t.dist=dis;
            t.dest=i;
            v[j].push_back(t);
            t.dest=j;
            v[i].push_back(t);
            }
        vx[i]=x; vy[i]=y;
        }
    tot=0;
    for(i=1;i<=com;i++)
        {
        for(j=0;j<=com;j++)
            {
            color[j]=0;
            prev[j]=0;
            }
        prev[i]=-1;
        coun=1; tot=0;
        color[i]=1;
        recur(i);
        }
    cout<<"**********************************************************"<<endl;
    cout<<"Network #"<<see<<endl;
    if(!st.empty())
        {
        int from=st.top();
        st.pop();
        while(!st.empty())
            {
            int x2,x3,y2,y3;
            int tw=st.top();
            st.pop();
            x2=vx[from]; y2=vy[from];
            x3=vx[tw]; y3=vy[tw];
            cout<<"Cable requirement to connect ("<<vx[from]<<","<<vy[from]<<") to ("<<vx[tw]<<","<<vy[tw]<<") is ";
            double res=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3))+16.0;
            printf("%.2lf feet.\n",res);
            from=tw;
            }
        }
    double res=men+(com-1)*16.0;
    printf("Number of feet of cable required is %.2lf.\n",res);
    /*for(i=0;i<=com;i++)
        {
        cout<<i<<": "<<endl;
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j].dest<<" "<<v[i][j].dist<<endl;
        cout<<endl;
        }*/
    }
return 0;
}
