#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
int a[10000],i,j,k,t,n,m,max,now;
while(cin>>t)
    {
    for(m=1;m<=t;m++)
        {
        int s=1,d=0,p=1;
        cin>>n;
        max=0; now=0;
        for(i=1;i<n;i++)
            cin>>a[i];
        for(i=1;i<n;i++)
            {
            now+=a[i];
            if(now>=max)
                {
                s=p; d=i;
                max=now;
                }
            if(now<0)
                {
                p=i+1;
                now=0;
                }
            }
        //cout<<max<<endl;
        if(m>0)
            cout<<"The nicest part of route "<<m<<" is between stops "<<s<<" and "<<d+1<<endl;
        else
            cout<<"Route "<<m<<" has no nice parts"<<endl;
        }
    }
return 0;
}
