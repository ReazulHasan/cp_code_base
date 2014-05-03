#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
int a,b,c,e,count=0;
float h,d,n,f,res=0,fat,p=100;
while(scanf("%d %d %d %d",&a,&b,&c,&e)==4)
    {
    h=a; d=b; n=c; f=e;
    if(h==0) break;
    fat=d*f/100;
    while(res<=h&&p>=0)
        {
        if(d>=0)
            res+=d;
        d-=fat;
        count++;
        if(res>h)
            {
            cout<<"success on day "<<count<<endl;
            break;
            }
        res-=n;
        p=res;
        if(res<0)
            {
            cout<<"failure on day "<<count<<endl;
            break;
            }
        }
    count=0; res=0; p=100;
    }
return 0;
}
