#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;

int a[10][10],wro[30],wco[30];
int p[]={1,-1,0,0};
int q[]={0,0,-1,1};
int sx,sy,dx,dy;
stack<int> st;

int check(int x,int y,int m,int n)
{
int i;
for(i=0;i<6;i+=2)
    {
    int p=wro[i],q=wco[i],r=wro[i+1],s=wco[i+1];
    if(x==m&&q==s)
        if((x>=p&&x<r)||(x>=r&&x<p))
            if((y<q&&n==s||n<q&&y==s))
                return 0;
    if(y==n&&p==r)
        if((y>=q&&y<s)||(y>=s&&y<q))
            if(x<p&&m==r||m<p&&x==r)
                return 0;
    }
return 1;
}

int BFS()
{
int i,j,k;
int color[10][10],prev[10][10];
for(i=0;i<10;i++)
    for(j=0;j<10;j++)
        {
        color[i][j]=0;
        prev[i][j]=0;
        }
queue<int> qx,qy;
qx.push(sx);
qy.push(sy);
color[sx][sy]=1;
prev[sx][sy]=-1;
while(!qx.empty())
    {
    int x=qx.front();
    qx.pop();
    int y=qy.front();
    qy.pop();
    //cout<<x<<" "<<y<<endl;
    if(x==dx&&y==dy)
        {
        int mn=dx*6+dy;
        st.push(mn);
        while(prev[x][y]!=-1)
            {
            int now=prev[x][y];
            st.push(now);
            x=now/6;
            y=now%6;
            }
        break;
        }
    for(i=0;i<4;i++)
        {
        int m=x+p[i];
        int n=y+q[i];
        if(m>=0&&m<6&&n>=0&&n<6&&color[m][n]==0)
            {
            //if(a[x][y]==0||a[m][n]==0||a[x][y]==a[m][n])
            if(check(x,y,m,n))
                {
                color[m][n]=1;
                prev[m][n]=(6*x)+y;
                qx.push(m);
                qy.push(n);
                }
            }
        }
    }
return 0;
}

int print_path()
{
int i,j;
if(!st.empty())
    st.pop();
int m=sx,n=sy;
while(!st.empty())
    {
    int it=st.top();
    st.pop();
    int x=it/6;
    int y=it%6;
    //cout<<x<<" "<<y<<endl;
    if(y==n)
        {
        if(x<m)
            cout<<"N";
        else if(x>m)
            cout<<"S";
        }
    else if(x==m)
        {
        if(y>n)
            cout<<"E";
        else if(y<n)
            cout<<"W";
        }
    m=x; n=y;
    }
cout<<endl;
return 0;
}

int main()
{
int i,j,k,x1,y1,x2,y2;
while(cin>>sy>>sx)
    {
    if(sy==0&&sx==0)
        break;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            {
            a[i][j]=0;
            wro[i]=0;
            wco[i]=0;
            }
    cin>>dy>>dx;
    sx--; sy--; dx--; dy--;
    int t=3;
    char fl=1;
    k=0;
    while(t--)
        {
        cin>>y1>>x1>>y2>>x2;
        wro[k]=x1; wco[k]=y1;
        k++;
        wro[k]=x2; wco[k]=y2;
        k++;
        }
    BFS();
    print_path();
    }
return 0;
}
