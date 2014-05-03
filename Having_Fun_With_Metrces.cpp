#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

char a[100][100],q[100];
int x,y,n;

int row()
{
int i,j;
for(i=0;i<n;i++)
    {
    char temp=a[x][i];
    a[x][i]=a[y][i];
    a[y][i]=temp;
    }
return 0;
}

int col()
{
int i;
for(i=0;i<n;i++)
    {
    char temp=a[i][x];
    a[i][x]=a[i][y];
    a[i][y]=temp;
    }
return 0;
}

int inc()
{
int i,j;
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        {
        int it=a[i][j]-'0';
        it++;
        it%=10;
        a[i][j]=it+'0';
        }
return 0;
}

int dec()
{
int i,j;
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        {
        int it=a[i][j]-'0';
        it--;
        if(it<0)
            it+=10;
        a[i][j]=it+'0';
        }
return 0;
}

int transpose()
{
int i,j;
char temp[100][100];
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        temp[j][i]=a[i][j];
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        a[i][j]=temp[i][j];
return 0;
}

int main()
{
int cas=0,t,i,j,k,m;
char gar[10];
cin>>t;
while(t--)
    {
    cas++;
    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
            {
            a[i][j]='\0';
            q[i]='\0';
            }
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    gets(gar);
    for(i=1;i<=m;i++)
        {
        gets(q);
        if(q[0]=='r')
            {
            x=q[4]-'0';
            y=q[6]-'0';
            x--;
            y--;
            //cout<<q[4]<<" "<<q[6]<<endl;
            //cout<<x<<" "<<y<<endl;
            row();
            }
        if(q[0]=='c')
            {
            x=q[4]-'0';
            y=q[6]-'0';
            x--; y--;
            col();
            }
        if(q[0]=='i')
            {
            inc();
            }
        if(q[0]=='d')
            {
            dec();
            }
        if(q[0]=='t')
            {
            transpose();
            }
        }
    cout<<"Case #"<<cas<<endl;
    for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            cout<<a[i][j];
        cout<<endl;
        }
    cout<<endl;
    }
return 0;
}
