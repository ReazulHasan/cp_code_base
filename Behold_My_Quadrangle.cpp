#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
long long a[10];
int i,j,k,cas;
cin>>cas;
while(cas--)
    {
    for(i=0;i<4;i++)
        cin>>a[i];
    if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])
        cout<<"square"<<endl;
    else
        {
        sort(a,a+4);
        if((a[0]==a[1]&&a[2]==a[3])||(a[0]==a[2]&&a[1]==a[3])||(a[0]==a[3]&&a[1]==a[2]))
            cout<<"rectangle"<<endl;
        else if((a[0]+a[1]+a[2])>a[3])
            cout<<"quadrangle"<<endl;
        else
            cout<<"banana"<<endl;
        }
    }
return 0;
}
