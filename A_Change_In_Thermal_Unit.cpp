#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;

int main()
{
int i,j,k,cas=0,n;
cin>>n;
while(n--)
    {
    double res,f,c,incr;
    cas++;
    cin>>c>>incr;
    f=(9*c)/5+32;
    f+=incr;
    res=5*(f-32)/9;
    cout<<"Case "<<cas<<": ";
    printf("%.2lf\n",res);
    }
return 0;
}
