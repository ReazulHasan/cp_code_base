#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
int i,j,k,cas;
cin>>cas;
while(cas--)
    {
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int len1=s1.size();
    int len2=s2.size();
    int len3=s3.size;
    int minx=1000000;
    for(i=0;i<len1;i++)
        if(minx>(s1[i]-'0'))
            minx=(s1[i]-'0');
    for(i=0;i<len2;i++)
        if(minx>(s2[i]-'0'))
            minx=(s2[i]-'0');
    for(i=0;i<len3;i++)
        if(minx>(s3[i]-'0'))
            minx=(s3[i]-'0');
    int bas=minx+1;
    if(len1>len2)
        {
        int rem=0;
        for(i=len1-1;i>=0;i--)
            {
            len2--; len3--;
            int x=s1[i]-'0';
            int y=s2[len2]-'0';
            int res=x+y+rem;
            if(res%10!=(s3[len3]-'0'))
                if(bas<res)
                    {
                    bas=res-1;

                    }
            else if(res>(s3[len3]-'0'))
                {
                if(bas<(res-s3[len3]))
                    bas=res-s3[len3];
                }

            }
        }
    }
return 0;
}
