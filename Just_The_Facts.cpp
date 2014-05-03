#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<map>
using namespace std;

int main()
{
long long i,j,k,n,x,y,now,mult;
while(cin>>n)
    {
    if(n==0||n==1)
        {
        printf("%5lld -> 1",n);
        }
    else if(n==2)
        printf("%5lld -> 2",n);
    else
        {
        x=n;
        for(i=n-1;i>=2;i--)
            {
            x*=i;
            while(x%10==0)
                {
                //cout<<x<<endl;
                x/=10;
                }
            x%=100000;
            }
        printf("%5lld -> ",n);
        cout<<x%10;
        }
    printf("\n");
    //cout<<x%10<<endl;
    }
return 0;
}
