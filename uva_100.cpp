#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
int a,b,i,j,count=0,res=0;
while(scanf("%d %d",&a,&b)==2)
    {
    for(j=a;j<=b;j++)
        {
            i=j;
            while(i!=1)
                {
                if(i%2==0) i/=2;
                else i=(3*i)+1;
                count++;
                }
            if(res<=count+1)
                res=count+1;
            count=0;
        }
        cout<<a<<" "<<b<<" "<<res<<endl;
        res=0;
    }
return 0;
}
