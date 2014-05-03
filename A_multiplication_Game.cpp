#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<cmath>
using namespace std;

//typedef long long ll;

int main()
{
long long a,b;
while(cin>>a)
    {
    int coun=0;
    b=1;
    while(b<a)
        {
        b*=9;
        coun++;
        }
    if(coun%2)
        cout<<"Stan wins."<<endl;
    else
        cout<<"Ollie wins."<<endl;
    }
return 0;
}
