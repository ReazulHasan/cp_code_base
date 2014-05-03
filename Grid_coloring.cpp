#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int flag[103][103];
char a[103][103];
int p[]={-1,0,0,1};
int q[]={0,-1,1,0};
char now,boun;

int flood(int ro,int co)
{
int i,j;
flag[ro][co]=1;
a[ro][co]=now;
//cout<<ro<<" "<<co<<endl;
for(i=0;i<4;i++)
    {
    int x=ro+p[i];
    int y=co+q[i];
    if(a[x][y]!=boun&&a[x][y]!='_'&&flag[x][y]==0)
        flood(x,y);
    }
return 0;
}

int main()
{
char z[5];
int i,j,k;
while(gets(a[0]))
    {
    int m=0;
    while(a[m][0]!='_')
        {
        m++;
        gets(a[m]);
        }
    //gets(z);
    for(i=0;i<m;i++)
        {
        int fl=0;
        int ln=strlen(a[i]);
        for(j=0;j<ln;j++)
            if(a[i][j]!=' '&&a[i][j]!='_')
                {
                boun=a[i][j];
                fl=1;
                //cout<<boun<<endl;
                break;
                }
            if(fl==1)
                break;
        }
    //cout<<boun<<endl;
    for(i=0;i<m;i++)
        {
        int len=strlen(a[i]);
        for(j=0;j<len;j++)
            {
            if(a[i][j]!=' '&&a[i][j]!='_'&&a[i][j]!=boun&&flag[i][j]==0)
                {
                now=a[i][j];
                //cout<<now<<endl;
                flood(i,j);
                }
            }
        }
    for(i=0;i<=m;i++)
        {
        int len=strlen(a[i]);
        for(j=0;j<len;j++)
            cout<<a[i][j];
        cout<<endl;
        }
    for(i=0;i<100;i++)
        for(j=0;j<100;j++)
            {
            flag[i][j]=0;
            }
    //gets(z);
    }
return 0;
}
