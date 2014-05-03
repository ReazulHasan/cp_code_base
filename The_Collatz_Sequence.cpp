#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
long long a,l,b;
int cas=0,coun=0;
while(cin>>a>>l)
    {
    b=a;
    cas++;
    if(a==-1&&l==-1)
        break;
    coun=0;
    while(a!=1)
        {
        coun++;
        if(a%2==0)
            a/=2;
        else
            {
            a*=3;
            a++;
            }
        if(a>l)
            break;
        }
    if(a==1) coun++;
    cout<<"Case "<<cas<<": A = "<<b<<", limit = "<<l<<", number of terms = "<<coun<<endl;
    }
return 0;
}
