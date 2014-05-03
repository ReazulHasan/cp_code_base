#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
int t,i,j;
char a[100],c,p;
cin>>t;
//cout<<p;
while(t--)
    {
    cin>>p;
    int k=0,res1=0,res2=0;
    a[k++]=p;
    while((c=getchar())!='\n')
        {
        //cout<<c;
        if(c!=' ')
            a[k++]=c;
        }
    /*for(i=0;i<k;i++)
        cout<<a[i];*/
    for(i=0;i<k;i+=2)
        {
        int it=a[i]-'0';
        it*=2;
        int x=it%9;
        //cout<<it<<" "<<x<<endl;
        if(x==0&&it!=0)
            res1+=9;
        else
            res1+=x;
        }
    for(i=1;i<k;i+=2)
        res2+=(a[i]-'0');
    int res=res1+res2;
    int h=res%10;
    if(h==0)
        cout<<"Valid";
    else
        cout<<"Invalid";
    cout<<endl;
    }
//cout<<"c";
return 0;
}
