#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
int a[10],i,j,cas;
cin>>cas;
while(cas--)
    {
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]+a[1]>a[2])
        cout<<"OK"<<endl;
    else
        cout<<"Wrong!!"<<endl;
    }
return 0;
}
