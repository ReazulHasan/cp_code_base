#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

#define sz 6000
int a[sz+3],b[sz+3];
map<int,int> mp;

int seive()
{
int i,j;
for(i=2;i*i<=sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
b[0]=2;
int k=1;
for(i=3;i<=sz;i+=2)
    if(a[i]==0)
        {
        b[k++]=i;
        mp[i]=1;
        }
/*for(i=0;i<k;i++)
    cout<<b[i]<<" ";*/
return 0;
}

int main()
{
seive();
int t,n,i,j,k,x,y;
scanf("%d",&t);
for(k=1;k<=t;k++)
    {
    int final=999999;
    cin>>x>>y;
    cout<<"Case "<<k<<":"<<endl;
    int res=0;
    if(mp[x]==1)
        {
        while(y>0)
            {
            int nw=y/x;
            res+=nw;
            y/=x;
            }
        if(res==0)
            cout<<"Impossible to divide"<<endl;
        else
            cout<<res<<endl;
        }
    else
        {
        for(i=0;b[i]*b[i]<=x;i++)
            {
            int coun=0,fact=y,res=0;
            while(x%b[i]==0)
                {
                x/=b[i];
                coun++;
                }
            //cout<<coun<<endl;
            if(coun>0)
                {
                while(fact>0)
                    {
                    int nw=fact/b[i];
                    res+=nw;
                    fact/=b[i];
                    }
                res/=coun;
                }
            if(res<final&&coun>0)
                final=res;
            }
        res=0;
        if(x>1)
            {
            while(y>0)
                {
                int nw=y/x;
                res+=nw;
                y/=x;
                }
            if(res<final)
                final=res;
            }
        if(final==0)
            cout<<"Impossible to divide"<<endl;
        else
        cout<<final<<endl;
        }
    }
}
