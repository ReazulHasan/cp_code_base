#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;

unsigned long long gcd(unsigned long long x,unsigned long long y)
{
if(y==0)
    return x;
return gcd(y,x%y);
}

int main()
{
int i,j,k,n,cas=0;
cin>>n;
while(n--)
    {
    cas++;
    int num,a[100];
    cin>>num;
    unsigned long long lob=1,hor=0;
    for(i=0;i<num;i++)
        {
        cin>>a[i];
        lob*=a[i];
        }
    for(i=0;i<num;i++)
        hor+=lob/a[i];
    lob*=num;
    unsigned long long x=gcd(hor,lob);
    cout<<"Case "<<cas<<": "<<lob/x<<"/"<<hor/x<<endl;
    }
return 0;
}
