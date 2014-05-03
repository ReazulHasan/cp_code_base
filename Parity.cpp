#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
char a[10000];
long long n;
while(cin>>n&&n)
    {
    int i=0,coun=0,j;
    while(1)
        {
        int x=n%2;
        a[i++]=x+'0';
        if(x==1)
            coun++;
        n/=2;
        if(n==0)
            break;
        }
    //int p=coun%2;
    cout<<"The parity of ";
    for(j=i-1;j>=0;j--)
        cout<<a[j];
    cout<<" is "<<coun<<" (mod 2)."<<endl;
    }
return 0;
}
