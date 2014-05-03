        //Bismillah
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
vector<int> v;
int a[100],t,i,j=0,n,k,res=0;
cin>>t;
for(i=0;i<t;i++)
    {
    while(cin>>n)
        {
        if(n==0)
            break;
        a[j++]=n;
        }
    v.resize(j);
    for(k=0;k<j;k++)
        v[k]=a[k];
    sort(v.begin(),v.end());
    int flag=0,c=0;
    for(k=j-1;k>=0;k--)
        {
        int mult=1,m=1;
        flag++;
        while(m<=flag)
            {
            mult*=v[k];
            m++;
            }
        m=1;
        res+=mult*2;
        if((res)>5000000)
            {
            cout<<"Too expensive"<<endl;
            c=1;
            break;
            }
        }
    if(c==0)
        {
        cout<<res<<endl;
        }
    c=0;
    for(k=0;k<100;k++)
        a[k]=0;
    res=0; j=0;
    }
}
