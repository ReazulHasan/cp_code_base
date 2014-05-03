#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
char a[10000],c;
int i,j,k,sum;
while((c=getchar())&&c!='0')
    {
    sum=0;
    sum+=c-'0';
    while((c=getchar())!='\n')
        sum+=c-'0';
    int res=sum%9;
    if(res==0)
        res=9;
    cout<<res<<endl;
    }
return 0;
}
