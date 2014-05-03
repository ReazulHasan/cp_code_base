#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int main()
{
int i,j,k,cas,n;
cin>>cas;
while(cas--)
    {
    cin>>n;
    int num=n,coun=0,a[20];
    int akok,doshok,sotok,hajar,ojut;
    for(i=0;i<10;i++)
        a[i]=0;
    for(i=1;i<=n;i++)
        {
        num=i;
        while(num>0)
            {
            int x=num%10;
            num/=10;
            a[x]++;
            }
        }
    cout<<a[0];
    for(i=1;i<=9;i++)
        cout<<" "<<a[i];
    cout<<endl;
    /*while(num>0)
        {
        int a[20];
        for(i=0;i<15;i++)
            a[i]=0;
        coun++;
        if(coun==1)
            akok=num%10;
        if(coun==2)
            doshok=num%10;
        if(coun==3)
            sotok=num%10;
        if(coun==4)
            hajar=num%10;
        if(coun==5)
            ojut=num%10;
        num/=10;
        }
    for(i=1;i<=akok;i++)
        a[i]++;
    for(i=1;i<doshok;i++)
        a[i]+=10;
    for(i=0;i<=9;i++)
        a[i]+=doshok;
    for(i=)*/
    }
return 0;
}
