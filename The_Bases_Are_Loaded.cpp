#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
using namespace std;

int main()
{
int a,b,i,j,k;
char c[15],d[15];
while(cin>>a>>b>>c)
    {
    int bas1,bas2,num=0,flag=0;
    bas1=a; bas2=b;
    for(i=0;i<strlen(c);i++)
        {
        num*=bas1;
        if(c[i]>='A'&&c[i]<='Z')
            {
            if(c[i]-'0'-7>=bas1)
                {
                flag=1;
                break;
                }
            num+=(c[i]-'0')-7;
            }
        else
            {
            if((c[i]-'0')>=bas1)
                {
                flag=1;
                break;
                }
            num+=c[i]-'0';
            }
        }
    if(flag==0)
        {
        int j=0;
        while(num>0)
            {
            int x=(num%bas2);
            if(x>=10)
                d[j++]=(x+7)+'0';
            else
                d[j++]=x+'0';
            num/=bas2;
            }
        /*if(num>=10)
            d[j++]=(num+7)+'0';
        else
            d[j++]=num+'0';*/
        cout<<c<<" base "<<bas1<<" = ";
        /*while(j)
            {
            j--;
            cout<<d[j];
            }*/
        cout<<" base "<<bas2<<endl;
        }
    else if(flag==1)
        cout<<c<<" is an illegal base "<<bas1<<" number"<<endl;
    for(i=0;i<15;i++)
        {
        c[i]='\0';
        d[i]='\0';
        }
    }
return 0;
}
