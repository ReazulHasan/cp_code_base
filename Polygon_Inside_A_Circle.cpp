#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double pi=2.0*acos(0.0);

int main()
{
double sid,rad;
while(cin>>rad>>sid)
    printf("%.3lf\n",((sin((2*pi)/sid))*sid*rad*rad)/2.0);
return 0;
}
