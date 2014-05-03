#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
using namespace std;

int main()
{
char a[100];
int i,j;
while(cin>>a)
    {
    char min='0';
    int n=0;
    for(i=0;i<strlen(a);i++)
        {
        if(a[i]>=min)
            min=a[i];
        n*=10;
        n+=a[i]-'0';
        }
    if(n==0)
        break;
    int bas=min-'0'+1;
    //cout<<bas<<endl;
    int flag=0;
    while(1)
        {
        int num=0;
        for(i=0;i<strlen(a);i++)
            {
            num*=bas;
            num+=a[i]-'0';
            }
        if(ceil(sqrt(num))==floor(sqrt(num)))
            break;
        bas++;
        if(bas>=100)
            {
            break;
            flag=1;
            }
        }
    if(flag==0)
        cout<<bas<<endl;
    }
return 0;
}
