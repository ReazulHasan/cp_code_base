#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define sz 500000
int a[sz+3],b[sz+3],det[sz+3],diff[sz+3];
int m=0;

int seive()
{
int i,j;
for(i=2;i*i<=sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
int k=1;
b[0]=2;
for(i=3;i<=sz;i+=2)
    if(a[i]==0)
        b[k++]=i;
m=0;
for(i=1;i<=k;)
    {
    int pos=i;
    int coun=0;
    int x=b[i]-b[i-1];
    i++;
    while(!((b[i]-b[i-1])-x)&&i<k)
        {
        i++;
        coun++;
        }
    int num=i-pos+1;
    if(num>2)
        {
        for(j=pos-1;j<i;j++)
            {
            det[m]=b[j];
            diff[m]=det[m]-det[m-1];
            m++;
            //cout<<b[j]<<" ";
            }
        //cout<<endl;
        }
    }
/*cout<<endl;
for(i=0;i<100;i++)
    cout<<i<<":"<<det[i]<<" "<<diff[i]<<" ";*/
}

int main()
{
seive();
int lo,hi,i,j,k;
//cout<<diff[1499]<<endl;
while(cin>>lo>>hi)
    {
    if(lo==0&&hi==0)
        break;
    if(lo>hi)
        {
        int temp=hi;
        hi=lo;
        lo=temp;
        }
    int fl=0;
    int poslo=0,poshi=0;
    for(i=0;i<m;i++)
        {
        if(det[i]>=lo&&fl==0)
            {
            poslo=i;
            fl=1;
            }
        if(det[i]==hi)
            {
            poshi=i;
            break;
            }
        if(det[i]>hi)
            {
            poshi=i-1;
            break;
            }
        }
    //cout<<poslo<<" "<<poshi<<endl;
    while(!(diff[poslo]-diff[poslo+1]))
        poslo++;
    poslo++;
    while(diff[poslo+1]!=diff[poslo])
        poslo++;
    while(!(diff[poshi]-diff[poshi+1]))
        poshi--;
    poshi--;
    while(diff[poshi+1]!=diff[poshi])
        poshi--;
    //cout<<poslo<<" "<<poshi<<endl;
    i=poslo-1;
    while(i<=poshi+1)
        {
        cout<<det[i];
        i++;
        int d=diff[i];
        int prev=0;
        while(!(diff[i]-d)&&i<=(poshi+1))
            {
            if(prev==det[i])
                break;
            cout<<" ";
            cout<<det[i];
            prev=det[i];
            i++;
            }
        cout<<endl;
        }
    }
return 0;
}
