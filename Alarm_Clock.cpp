#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int a,b,c,d;
while(cin>>a>>b>>c>>d)
    {
    if(a==0&&b==0&&c==0&&d==0)
        break;
    int res=0;
    if(c>a)
        {
        if(d>b)
            res=((c-a)*60)+(d-b);
        else
            res=((c-a)*60)-(b-d);
        }
    else if(c==a)
        {
        if(d>=b)
            res=d-b;
        else
            res=24*60-(b-d);
        }
    else if(c<a)
        {
        int x=24-(a-c);
        if(d>=b)
            res=x*60+(d-b);
        else
            res=x*60-(b-d);
        }
    cout<<res<<endl;
    }
return 0;
}
