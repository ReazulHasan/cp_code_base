#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
int a[100][100],i,j,k,t,x1,y1,x2,y2,strong=0,weak=0,none=0;
cin>>t;
for(i=1;i<=t;i++)
    {
    int p=0;
    for(j=0;j<100;j++)
            for(k=0;k<100;k++)
                a[j][k]=0;

    while(p<2)
        {
        cin>>x1>>y1>>x2>>y2;
                for(j=y1;j<y2;j++)
                    for(k=x1;k<x2;k++)
                        a[j][k]+=1;
        p++;
        }
        for(j=0;j<100;j++)
            for(k=0;k<100;k++)
                {
                    if(a[j][k]==0)
                        none++;
                    if(a[j][k]==1)
                        weak++;
                    if(a[j][k]==2)
                        strong++;
                }
            cout<<"Night "<<i<<": "<<strong<<" "<<weak<<" "<<none<<endl;
    strong=0; weak=0; none=0;
    }
}
