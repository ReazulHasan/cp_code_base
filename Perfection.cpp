#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

int main()
{
int n,i,j,k=0,a[1000];
while(cin>>n&&n)
    a[k++]=n;
cout<<"PERFECTION OUTPUT"<<endl;
for(j=0;j<k;j++)
    {
    n=a[j];
    int sum=0;
    for(i=1;i<=n/2;i++)
        if(n%i==0)
            sum+=i;
    printf("%5d ",n);
    if(sum==n)
        cout<<" PERFECT"<<endl;
    if(sum>n)
        cout<<" ABUNDANT"<<endl;
    if(sum<n)
        cout<<" DEFICIENT"<<endl;
    }
cout<<"END OF OUTPUT"<<endl;
return 0;
}
