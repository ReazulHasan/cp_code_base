#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;

int main()
{
int i,j,k,cas=0;
//ll n=4;
double d;
while(cin>>d)
    {
    cas++;
    double x=(3+sqrt(9+8*d))/2;
    ll res=ceil(x);
    cout<<"Case "<<cas<<": "<<res<<endl;
    }
return 0;
}
