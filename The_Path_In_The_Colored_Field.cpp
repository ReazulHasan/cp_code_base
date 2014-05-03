#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;

int main()
{
int n,i,j,k;
char a[1003][1003],b[1003][1003],c[5];
while(cin>>n)
    {
    queue<int> qi,qj;
    gets(c);
    for(i=0;i<n;i++)
        {
        int k=0;
        gets(b[i]);
        int len=strlen(b[i]);
        for(j=0;j<len;j++)
            if(b[i][j]=='1'||b[i][j]=='2'||b[i][j]=='3')
                a[i][k++]=b[i][j];
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j]=='1')
                {
                qi.push(i);
                qj.push(j);
                }
    int max=0;
    while(!qi.empty())
        {
        int ro,col;
        int x=qi.front();
        qi.pop();
        int y=qj.front();
        qj.pop();
        int min=268435456;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i][j]=='3')
                    {
                    if(x>i)
                        ro=x-i;
                    else
                        ro=i-x;
                    if(y>j)
                        col=y-j;
                    else
                        col=j-y;
                    int now=ro+col;
                    if(now<min)
                        min=now;
                    }
        if(max<min)
            max=min;
        }
    cout<<max<<endl;
    for(i=0;i<1000;i++)
        for(j=0;j<1000;j++)
            {
            a[i][j]='\0';
            b[i][j]='\0';
            }
    }
return 0;
}
