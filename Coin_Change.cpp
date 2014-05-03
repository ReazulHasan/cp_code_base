#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int a[50000];

int main()
{
int i,j,k;
a[0]=1;
int coin[20];
coin[0]=1; coin[1]=5; coin[2]=10; coin[3]=25; coin[4]=50;
for(i=0;i<5;i++)
    {
    int c=coin[i];
    for(j=0;j<8000;j++)
        a[c+j]+=a[j];
    }
int x;
while(cin>>x)
    cout<<a[x]<<endl;
return 0;
}
