#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main()
{
char a[1500],ch;
int i,j,k,n,cas=0,sum;
cin>>n;
while(n--)
    {
    cas++;
    cin>>a;
    sum=0;
    int len=strlen(a);
    for(i=0;i<len;i++)
        sum+=a[i]-'0';
    int coun=0;
    for(i=0;i<len;i++)
        {
        int fl=0;
        if((coun+1)==len)
            {
            coun++;
            break;
            }
        else
        for(j=0;j<len;j++)
            {
            if(a[j]!='0'&&(sum-(a[j]-'0'))%3==0)
                {
                coun++;
                sum-=a[j]-'0';
                a[j]='0';
                fl=1;
                break;
                }
            }
        if(fl==0)
            break;
        }
    cout<<"Case "<<cas<<": ";
    if(coun%2==0)
        cout<<"T"<<endl;
    else
        cout<<"S"<<endl;
    }
return 0;
}
