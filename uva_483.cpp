#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int main()
{
int i,j,k,len,t,index=0;
char a[1000],b[1000],c;
cin>>t;
for(i=1;i<=t;i++)
    {
    gets(a);
    len=strlen(a);
    for(j=0;j<len;j++)
        {
        if(a[j]==' ')
            {
            do
                {
                k=j-1;
                b[index++]=a[k--];
                }
            while(a[k]!=' '&&k>=0);
            b[index++]=' ';
            }
        }
    //puts(b);
    index=0;
    }
}
