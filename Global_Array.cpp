#include<iostream>
#include<cstdio>
using namespace std;
int a[100];

int hi()
{
int i;
for(i=0;i<10;i++)
    a[i]=i;
}

int main()
{
hi();
int x;
while(cin>>x)
    printf("%3d%3d\n",x,a[x]);
return 0;
}
