#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int i,j,k,stop,ent,ext,maxn=0,sum=0;
cin>>stop;
while(stop--)
    {
    cin>>ext>>ent;
    sum-=ext;
    sum+=ent;
    if(maxn<sum)
        maxn=sum;
    }
cout<<maxn<<endl;
return 0;
}
