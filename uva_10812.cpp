#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
int t,a,b,i,res1,res2;
cin>>t;
for(i=1;i<=t;i++)
    {
    cin>>a>>b;
    if(a%2==b%2&&a>=b)
        {
        res1=(a+b)/2;
        res2=(a-b)/2;
        cout<<res1<<" "<<res2<<endl;
        }
    else
        cout<<"impossible"<<endl;
    }
}
