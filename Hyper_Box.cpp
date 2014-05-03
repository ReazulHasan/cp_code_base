#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
typedef long long ll;
using namespace std;

vector<ll> fib;

int fibo()
{
int i,j,k;
ll a=1,b=2;
fib.push_back(a);
fib.push_back(b);
while((a+b)<=2000000000LL)
    {
    fib.push_back(a+b);
    ll tmp=b;
    b=a+b;
    a=tmp;
    }
return 0;
}

int main()
{
int i,j,k,cas,pos,kas=0,m;
ll dim,side[100],x,y;
fibo();
int len=fib.size();
/*for(i=0;i<len;i++)
    cout<<fib[i]<<endl;*/
//scanf("%d",&cas);
cin>>cas;
while(cas--)
    {
    kas++;
    ll ans=1;
    //scanf("%I64d",&dim);
    cin>>dim;
    for(m=0;m<dim;m++)
        {
        //scanf("%I64d",&y);
        cin>>y;
        x=y;
        for(i=0;i<len;i++)
            {
            if(fib[i]==x)
                {
                pos=i;
                break;
                }
            if(fib[i]>x)
                {
                pos=i-1;
                break;
                }
            }
        ll coun=0;
        for(i=pos;i>=0;i--)
            {
            if(x>=fib[i]&&x)
                {
                x-=fib[i];
                coun++;
                }
            if(x==0)
                break;
            }
        ans*=coun;
        }
    //printf("Case %d: %I64d\n",kas,ans);
    cout<<"Case "<<kas<<": "<<ans<<endl;
    }
return 0;
}
