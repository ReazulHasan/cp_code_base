#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

char a[109][109];
int p[]={-1,0,0,1};
int q[]={0,-1,1,0};
int r,c,coun=0;

int flood(int ro,int col)
{
int i,j;
a[ro][col]='v';
for(i=0;i<4;i++)
    {
    int x=ro+p[i],y=col+q[i];
    if(a[x][y]=='T')
        return 0;
    }
for(i=0;i<4;i++)
    {
    int x=ro+p[i],y=col+q[i];
    if(a[x][y]=='G')
        {
        coun++;
        flood(x,y);
        }
    else if(a[x][y]=='.')
        flood(x,y);
    }
return coun;
}

int main()
{
int i,j,k;
while(cin>>c>>r)
    {
    for(i=0;i<r;i++)
        cin>>a[i];
    for(i=0;i<r;i++)
        {
        for(j=0;j<c;j++)
            if(a[i][j]=='P')
                {
                coun=0;
                flood(i,j);
                break;
                }
        }
    cout<<coun<<endl;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            a[i][j]='\0';
    }
return 0;
}
