#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
int i,j,k,num;
while(cin>>num&&num)
    {
    int coun=0;
    long long mult=1;
    while(mult<num)
        {
        mult*=2;
        coun++;
        }
    if(mult==num)
        cout<<coun<<endl;
    else
        cout<<coun-1<<endl;
    }
return 0;
}
