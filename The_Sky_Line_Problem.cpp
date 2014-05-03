#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;

int main()
{
int a[10000],b,i,j,k;
int x,h,y;
for(i=0;i<10000;i++)
    a[i]=-1;
int max=0,min=100000,flag=0;
while(cin>>x>>h>>y)
    {
    for(i=x;i<y;i++)
        {
        flag=1;
        if(a[i]<h)
            a[i]=h;
        if(max<y)
            max=y;
        if(min>x)
            min=x;
        }
    }
    if(flag==1)
    {
    int nw=a[min];
    cout<<min<<" "<<nw;
    for(i=min;i<=max;i++)
        if(nw!=a[i])
            {
                cout<<" "<<i;
                if(a[i]==-1)
                    cout<<" "<<'0';
                if(a[i]!=-1)
                    cout<<" "<<a[i];
                nw=a[i];
            }
    cout<<endl;
    }
return 0;
}
