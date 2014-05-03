#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int flag=0;

int loop(char chr,int count)
    {
    int e,f;
    e=chr-'0'-'0'-1;
    f=count-e;
    cout<<e<<" step(s) before a loop of "<<f<<" step(s)"<<endl;
    flag=1;
    return 0;
    }


int main()
{
char a[100][100],ch,p='a';
int i,j,k,r,c,s,e,f;
while(cin>>r>>c>>s)
    {
    if(r==0&&c==0&&s==0)
        break;
    for(i=0;i<100;i++)
        for(j=0;j<100;j++)
            a[i][j]='\0';
    int count=0;
    p='a';
    for(i=0;i<r;i++)
        scanf("%s",&a[i]);
    i=0; j=s-1;
    ch=a[i][j];
    while((i>=0&&i<r)&&(j>=0&&j<c))
        {
        count++;
        a[i][j]=p++;
        if(ch=='W')
            {
            ch=a[i][--j];
            if(ch>='a'&&ch!='\0')
                loop(ch,count);
            }
        else if(ch=='S')
            {
            ch=a[++i][j];
            if(ch>='a'&&ch!='\0')
                loop(ch,count);
            }
        else if(ch=='E')
            {
            ch=a[i][++j];
            if(ch>='a'&&ch!='\0')
                loop(ch,count);
            }
        else if(ch=='N')
            {
            ch=a[--i][j];
            if(ch>='a'&&ch!='\0')
                loop(ch,count);
            }
        if(flag==1)
            break;
        }
    if(flag==0)
        cout<<count<<" step(s) to exit"<<endl;
    flag=0;
    }
return 0;
}
