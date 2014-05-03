#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

int main()
{
char a[100000];
long long x;
int t,j,coun=0;
cin>>t;
while(t)
    {
    coun++;
    int rem=0,q,i=0;
    t--;
    cin>>x;
    while(1)
        {
        rem=(x%(-2));
        x/=(-2);
        //cout<<x<<endl;
        if(rem<0)
            {
            x+=1;
            rem+=2;
            }
        a[i++]=rem+'0';
        if(x==0)
            break;
        }
    cout<<"Case #"<<coun<<": ";
    for(j=i-1;j>=0;j--)
        cout<<a[j];
    cout<<endl;
    }
return 0;
}
