#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
int i,x1,y1,x2,y2,x3,y3,x4,y4,pq1,pq2,pq3,strong,weak,none,t;
cin>>t;
for(i=1;i<=t;i++)
    {
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    pq1=(x2-x1)*(y2-y1);
    if(x2>x3||y2>y3)
        pq2=(x2-x3)*(y2-y3);
    else pq2=0;
    pq3=(x4-x3)*(y4-y3);
    strong=pq2;
    weak=pq1+pq3-2*pq2;
    none=10000-weak-strong;
    cout<<"Night "<<i<<": "<<strong<<" "<<weak<<" "<<none<<endl;
    }
return 0;
}
