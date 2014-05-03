#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int a[150];
int x,i=0,j,y;
while(cin>>x>>y)
    {
    if(i==0&&x==0&&y==0)
        break;
    while(y>=1&&y<=9)
        {
        a[i++]=y;
        cin>>y;
        }
    for(j=0;j<i;j++)
        if(a[j]==x)
            a[j]=-1;
    for(j=0;j<i;j++)
        if(a[j]!=-1)
            cout<<a[j];
    i=0;
    cout<<endl;
    }
return 0;
}
