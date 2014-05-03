#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
long long x,i,j,n;
while(cin>>x&&x)
    {
    int flg=0;
    for(i=40;i>1;i--)
        {
        double p,q;
        p=x*1.0; q=i*1.0;
        double res=pow(p,1/q);
        if(ceil(res)==floor(res))
            {
            cout<<i<<endl;
            flg=1;
            break;
            }
        }
    if(flg==0)
        cout<<"1"<<endl;
    }
return 0;
}
