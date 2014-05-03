#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
int a[12],b[12],i,j,s,count=0,sum=0;
while(scanf("%d",&s)==1)
    {
    if(s<0) break;
    sum=s;
    count++;
    for(i=0;i<12;i++)
        cin>>a[i];
    for(i=0;i<12;i++)
        cin>>b[i];
    cout<<"Case "<<count<<":"<<endl;
    j=0;
    while(j<12)
        {
        if(b[j]<=sum)
            {
            cout<<"No problem! :D"<<endl;
            sum-=b[j];
            }
        else cout<<"No problem. :("<<endl;
        sum+=a[j++];
        }
    }
}
