#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int t,n,i,j,k,x;
cin>>t;
while(t--)
    {
    cin>>n;
    int tot=0,maxn=0;
    for(i=0;i<n;i++)
        {
        cin>>x;
        tot+=x;
        if(maxn<x)
            maxn=x;
        }
    if((tot%4)!=0)
        cout<<"no"<<endl;
    else
        {
        tot/=4;
        if(maxn<=tot)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        }
    }
return 0;
}
