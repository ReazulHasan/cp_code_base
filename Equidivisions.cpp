#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int a[1009][1009],n;
int p[]={-1,0,0,1};
int q[]={0,-1,1,0};

int flood(int x,int y,int k)
{
int i;
k++;
if(k>n)
    return 1;
int it=a[x][y];
a[x][y]=-1;
for(i=0;i<4;i++)
    {
    int g=x+p[i],h=y+q[i];
    if(g>=0&&g<n&&h>=0&&h<n)
        if(it==a[g][h])
            flood(g,h,k);
    }
return 0;
}

int main()
{
char b[1005][1005],z[5];
int i,j,k,x,y;
while(cin>>n&&n)
    {
    int val=1;
    gets(z);
    for(i=1;i<n;i++)
        gets(b[i]);
    /*for(i=0;i<=n;i++)
        {
        for(j=0;j<=strlen(b[i]);j++)
            cout<<b[i][j];
        cout<<endl;
        }*/
    for(i=1;i<n;i++)
        {
        int x,y;
        int len=strlen(b[i]);
        for(j=0;j<len;)
            {
            if(j<len)
            if(b[i][j]!=' ')
                {
                x=b[i][j]-'0';
                j++;
                if(j<len)
                if(b[i][j]!=' ')
                    {
                    x=(x*10)+(b[i][j]-'0');
                    j++;
                    }
                }
            if(j<len)
            while(b[i][j]==' '&&j<len)
                j++;
            if(j<len)
            if(b[i][j]!=' ')
                {
                y=b[i][j]-'0';
                j++;
                if(j<len)
                if(b[i][j]!=' ')
                    {
                    y=(y*10)+(b[i][j]-'0');
                    j++;
                    }
                }
            if(j<len)
            while(b[i][j]==' '&&j<len)
                j++;
            //cout<<"x y "<<x<<" "<<y<<endl;
            a[x-1][y-1]=val;
            }
        val++;
        }
    /*for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            cout<<a[i][j];
        cout<<endl;
        }
    int m=n*(n-1);
    for(i=0;i<m;i++)
        {
        cin>>x>>y;
        if(i>0&&i%n==0)
            val++;
        a[x-1][y-1]=val;
        }*/
    int coun=0,p=0;
    for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            {
            if(a[i][j]>=0)
                {
                k=0;
                p=flood(i,j,k);
                if(p==1)
                    break;
                coun++;
                }
            if(p==1)
                break;
            }
        }
    if(p==0&&coun==n)
        cout<<"good"<<endl;
    else
        cout<<"wrong"<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=0;
    for(i=0;i<n;i++)
        {
        int l=strlen(b[i]);
        for(j=0;j<l;j++)
            a[i][j]='\0';
        }
    }
return 0;
}
