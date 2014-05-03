#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdio>
using namespace std;

unsigned long long a[50000];

int main()
{
int i,j,k;
int coin[]={1,5,10,25,50};
a[0]=1;
for(i=0;i<5;i++)
    {
    int c=coin[i];
    for(j=0;j<40000;j++)
        a[j+c]+=a[j];
    }
int num;
while(cin>>num)
    {
    long long res=a[num];
    if(res==1)
        cout<<"There is only "<<res<<" way to produce "<<num<<" cents change."<<endl;
    else
    cout<<"There are "<<res<<" ways to produce "<<num<<" cents change."<<endl;
    }
return 0;
}
