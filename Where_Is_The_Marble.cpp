#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int m,n,i,j,a[10000],it,cas=0,b[10000];
while(cin>>m>>n&&m&&n)
    {
    cas++;
    int flag=0,coun=0;
    for(i=0;i<m;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        cin>>b[i];
    cout<<"CASE# "<<cas<<":"<<endl;
    for(i=0;i<n;i++)
        {
        int it=b[i];
        coun=0; flag=0;
        for(j=0;j<m;j++)
            {
            if(a[j]<it)
                coun++;
            if(a[j]==it)
                flag=1;
            }
        if(flag==1)
            cout<<it<<" found at "<<coun+1<<endl;
        else
            cout<<it<<" not found"<<endl;
        }
    }
return 0;
}
