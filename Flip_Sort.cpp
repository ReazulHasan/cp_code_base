#include<iostream>
#include<cstdio>
using namespace std;

int a[10000],n,it;

int min(int x)
{
int i,j,mn=100000,coun=0;
for(i=x;i<n;i++)
    if(it>a[i])
        {
        coun++;
        /*j=i;
        mn=a[i];*/
        }
//cout<<mn<<" "<<j<<endl;
return coun;
}

int main()
{
int i,j;
while(cin>>n)
    {
    int coun=0,res=0;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n-1;i++)
        {
        it=a[i];
        int x=min(i);
        res+=x;
        //cout<<x<<" ";
        /*if(a[i]!=a[x])
            {
            coun++;
            /*int temp=a[i];
            a[i]=a[x];
            a[x]=temp;
            }*/
        }
    cout<<"Minimum exchange operations : "<<res<<endl;
    }
return 0;
}
