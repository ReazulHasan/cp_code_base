#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
int t,i,j,m,a[1000];
cin>>t;
for(j=1;j<=t;j++)
    {
    double sum=0,n;
    cin>>n;
    for(i=0;i<n;i++)
        {
        cin>>m;
        a[i]=m;
        sum+=m;
        }
    double avg=double(sum/n);
    //cout<<avg<<endl;
    int coun=0;
    for(i=0;i<n;i++)
        if(a[i]>avg)
            coun++;
    double res=double((100*coun)/n);
    printf("%.3lf",res);
    cout<<"%"<<endl;
    }
return 0;
}
