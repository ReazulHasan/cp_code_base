#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

/*int a[100],prim[100];

int seive()
{
int i,j;
for(i=2;i*i<=10;)
    {
    for(j=i+i;j<=10;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
int k=1;
prim[0]=2;
for(i=3;i<=10;i+=2)
    if(a[i]==0)
        prim[k++]=i;
for(i=0;i<k;i++)
    cout<<prim[i]<<" ";
return 0;
}*/

int main()
{
//seive();
int s,t,i,j,a[]={2,3,5,7},cas=0;
while(cin>>s>>t)
    {
    if(s==0&&t==0)
        break;
    cas++;
    int flag=0;
    if(s==0||t==0)
        {
        cout<<"Case "<<cas<<": "<<"-1"<<endl;
        continue;
        }
    if(s==t)
        {
        cout<<"Case "<<cas<<": "<<"-1"<<endl;
        continue;
        }
    for(i=3;i>=0;i--)
        {
        int coun=0;
        if(s>a[i])
        if(s%a[i]==0)
            {
            //cout<<a[i]<<endl;
            int now=a[i],n=s;
            while(n<t)
                {
                n+=now;
                //cout<<n<<" ";
                coun++;
                }
            if(n==t)
                {
                flag=1;
                cout<<"Case "<<cas<<": "<<coun<<endl;
                break;
                }
            }
        }
    if(flag==0)
        cout<<"Case "<<cas<<": "<<"-1"<<endl;
    }
}
