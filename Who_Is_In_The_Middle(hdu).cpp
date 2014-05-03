#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
int i,j,k,n,a[10009];
while(cin>>n)
    {
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
/*for(i=0;i<n;i++)
    cout<<a[i]<<" ";*/
    cout<<a[n/2]<<endl;
    }
return 0;
}
