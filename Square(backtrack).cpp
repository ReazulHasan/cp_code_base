#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int peri=0,a[100],n,flag=0;

int square(int p,int q,int r,int s,int ii)
{
int i,j,k;
if(flag)
    return 1;
if(p==q&&q==r&&r==s&&ii<0)
    flag=1;
if(flag)
    return 1;
//cout<<a[ii]<<" "<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
if(p+a[ii]<=peri)
    square(p+a[ii],q,r,s,ii-1);
if(flag)
    return 1;
if(q+a[ii]<=peri&&p!=q)
    square(p,q+a[ii],r,s,ii-1);
if(flag)
    return 1;
if(r+a[ii]<=peri&&r!=p&&r!=q)
    square(p,q,r+a[ii],s,ii-1);
if(flag)
    return 1;
if(s+a[ii]<=peri&&s!=p&&s!=q&&s!=r)
    square(p,q,r,s+a[ii],ii-1);
if(flag)
    return 1;
}

int main()
{
int i,j,k,t;
cin>>t;
while(t--)
    {
    cin>>n;
    peri=0;
    int res=0;
    for(i=0;i<n;i++)
        {
        cin>>a[i];
        peri+=a[i];
        }
    if(peri%4!=0)
        cout<<"no"<<endl;
    else
        {
        peri/=4;
        sort(a,a+n);
        if(a[n-1]>peri)
            cout<<"no"<<endl;
        else
            {
            //ii=n-1;
            flag=0;
            square(0,0,0,0,n-1);
            if(flag)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
            }
        }
    }
return 0;
}
