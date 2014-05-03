#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
int count=0,x,y,z,i,j,a[30],b[30],res=0,high=0;
while(scanf("%d %d %d",&x,&y,&z))
    {
    a[0]=0;
    count++;
    if(x==0&&y==0&&z==0) break;
    for(i=0;i<30;i++)
        {
        b[i]=0;
        a[i]=0;
        }
    for(i=1;i<=x;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=y;i++)
        {
        scanf("%d",&j);
        if(b[j]==0)
            {
            res+=a[j];
            b[j]=1;
            }
        else if(b[j]==1)
            {
            res-=a[j];
            b[j]=0;
            }
        if(high<=res)
            high=res;
        }
    if(high>z)
        cout<<"Sequence "<<count<<endl<<"Fuse was blown."<<endl;
    else
        {
        cout<<"Sequence "<<count<<endl;
        cout<<"Fuse was not blown."<<endl;
        cout<<"Maximal power consumption was "<<high<<" amperes."<<endl;
        }
        cout<<endl;
    res=0; high=0;
    }
}
