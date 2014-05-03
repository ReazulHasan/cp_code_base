#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;

int primitive[1000009],all[1000009];
map<int,int> mp;

int relative_prime(int x,int y)
{
if(y==0)
    {
    if(x==1)
        return 1;
    else
        return 0;
    }
return relative_prime(y,x%y);
}

int triple()
{
int i,j,k,a,b,c,flag=0;
for(i=1;i<=1000;i++)
    {
    for(j=i+1;j<=1000;j++)
        {
        int x=i,y=j;
        if(((x%2==0&&y%2==1)||(x%2==1&&y%2==0))&&relative_prime(x,y))
            {
            a=y*y-x*x;
            b=2*x*y;
            c=x*x+y*y;
            //if(c<100)
                //cout<<i<<" "<<j<<" : "<<a<<" "<<b<<" "<<c<<endl;
            if(c<=1000000)
                {
                primitive[c]+=1;
                if(all[c]==0)
                    all[c]=c;
                if(all[b]==0)
                    all[b]=c;
                if(all[a]==0)
                    all[a]=c;
                int hi=c*2,mult=2;
                while(hi<=1000000)
                    {
                    if(all[hi]==0)
                        all[hi]=hi;
                    if(all[a*mult]==0)
                        all[a*mult]=hi;
                    if(all[b*mult]==0)
                        all[b*mult]=hi;
                    mult++;
                    hi=c*mult;
                    }
                }
            }
        }
    }
for(i=1;i<=1000000;i++)
    {
/*    if(i<100)
        cout<<primitive[i]<<" ";*/
    primitive[i]+=primitive[i-1];
    /*if(i<100)
        cout<<all[i]<<" ";*/
    }
return 0;
}

int main()
{
int i,j,k,n;
triple();
//return 0;
while(cin>>n)
    {
    int coun=0;
    for(i=0;i<=n;i++)
        if(all[i]<=n&&all[i]!=0)
            coun++;
    cout<<primitive[n]<<" "<<coun<<endl;
    }
return 0;
}
