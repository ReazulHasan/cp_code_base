#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

char a[100][100];
int p[]={-1,-1,-1,0,0,1,1,1};
int q[]={-1,0,1,-1,1,-1,0,1};

int flood(int r,int c)
{
int i;
//cout<<r<<" "<<c<<endl;
a[r][c]='#';
for(i=0;i<8;i++)
    if(a[r+p[i]][c+q[i]]=='*'||a[r+p[i]][c+q[i]]=='_'||a[r+p[i]][c+q[i]]==' ')
        flood(r+p[i],c+q[i]);
return 0;
}

int main()
{
char z[5];
int i,j,k,r,c,t;
cin>>t;
gets(z);
while(t--)
    {
    i=0;
    while(1)
        {
        int flag=0;
        gets(a[i]);
        int len=strlen(a[i]);
        for(j=0;j<len;j++)
            if(a[i][j]!='_')
                flag=1;
        //cout<<flag<<endl;
        if(!flag)
            break;
        i++;
        }
    for(j=0;j<i;j++)
        {
        for(k=0;k<strlen(a[j]);k++)
            if(a[j][k]=='*')
                {
                flood(j,k);
                break;
                }
        }
    for(j=0;j<=i;j++)
        {
        int len=strlen(a[j]);
        for(k=0;k<len;k++)
            cout<<a[j][k];
        cout<<endl;
        }
    for(i=0;i<100;i++)
        for(j=0;j<100;j++)
            a[i][j]='\0';
    }
return 0;
}
