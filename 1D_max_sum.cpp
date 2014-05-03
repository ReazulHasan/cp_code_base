#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
int a[1000],i,j,n;
while(cin>>n)
    {
    int s=0,d=0,p=0,q=0;
    for(i=0;i<n;i++)
        cin>>a[i];
    int now=0,max=0;
    for(i=0;i<n;i++)
        {
        now+=a[i];
        if(now>max)
            {
            s=p; d=i;  //s=source, d=destination;
            max=now;
            }
        if(now<0)
            {
            p=i+1;   //from next item, the sum could start to be max. so, p=i+1;
            now=0;
            }
        }
    cout<<max<<" "<<s+1<<" "<<d+1<<endl;
    }
return 0;
}
