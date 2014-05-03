#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
int k,t,a,b,i,m,j;
cin>>t;
for(k=1;k<=t;k++)
    {
    cin>>a>>b;
    //cout<<endl;
    for(m=1;m<=b;m++)
        {
        for(i=1;i<=a;i++)
            {
            for(j=1;j<=i;j++)
                cout<<i;
            cout<<endl;
            }
        for(i=a-1;i>=1;i--)
            {
            for(j=1;j<=i;j++)
                cout<<i;
            cout<<endl;
            }
        if(k==t&&m==b)
            break;
        else
            cout<<endl;
        }
    }
//cout<<"russel";
return 0;
}
