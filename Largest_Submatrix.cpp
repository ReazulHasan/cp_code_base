#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
int a[100][100],b[100],i,j,k,m,n,t;
char p[100][100];
cin>>t;
while(t)
    {
    for(i=0;i<100;i++)
        {
        b[i]=0;
        for(j=0;j<100;j++)
            {
            a[i][j]=0;
            p[i][j]='0';
            }
        }
    cin>>p[0];
    m=strlen(p[0]);
    //cout<<m<<endl;
    n=m;
    for(i=1;i<m;i++)
        cin>>p[i];
    //cout<<endl;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            {
            if(p[i][j]=='0')
                a[i][j]=-1000;
            else
                a[i][j]=1;
            }
    /*for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cout<<a[i][j];*/
    int max=0;
    for(i=0;i<m;i++)
        {
        for(j=0;j<n;j++)
            b[j]=0;
        for(j=i;j<m;j++)
            {
            int now=0;
            for(k=0;k<n;k++)
                {
                b[k]+=a[j][k];
                now+=b[k];
                if(max<now)
                    max=now;
                if(now<0)
                    now=0;
                }
            }
        }
    cout<<max<<endl;
    if(t>1)
        cout<<endl;
    t--;
    }
return 0;
}
