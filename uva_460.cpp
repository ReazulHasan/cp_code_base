#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
int a[99][99],i,j,k,p,t,r1,r2,s1,s2,count=0,flag=0,z=0,x1,x2,y1,y2,point1=90000,point2=0;
cin>>t;
for(p=1;p<=t;p++)
    {
    for(i=0;i<99;i++)
        for(j=0;j<99;j++)
            a[i][j]=0;
    while(z<2)
        {
        cin>>x1>>y1>>x2>>y2;
        for(i=y1;i<y2;i++)
            for(j=x1;j<x2;j++)
                a[i][j]+=1;
        z++;
        }
    z=0;
    for(i=0;i<99;i++)
        for(j=0;j<99;j++)
            {
            if(a[i][j]==2)
                {
                flag=1;
                if(point1<(i+j))
                    {
                    point1=i+j;
                    r1=j;
                    s1=i;
                    }
                if(point2>(i+j))
                    {
                    point2=i+j;
                    r2=j;
                    s2=i;
                    }
                }
            }
        if(flag==0)
            cout<<"No Overlap"<<endl;
        else
            cout<<r1<<" "<<s1<<" "<<r2<<" "<<s2<<endl;
        cout<<endl;
    flag=0;
    }
}
