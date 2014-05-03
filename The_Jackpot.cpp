#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int a[10009],i,j;
int max,now,n;
while(cin>>n&&n)
    {
    max=0; now=0;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        {
        now+=a[i];
        if(now>max)
            max=now;
        if(now<0)
            now=0;
        }
    if(max>0)
        cout<<"The maximum winning streak is "<<max<<"."<<endl;
    else
        cout<<"Losing streak."<<endl;
    }
}
