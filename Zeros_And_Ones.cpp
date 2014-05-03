#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

char s[1000009];
int a[1000009];

int main()
{
int i,j,min,max,t,coun=0;
char z[5];
while(gets(s))
    {
    coun++;
    int len=strlen(s);
    if(len==0)
        break;
    a[0]=0;
    for(i=1;i<len;i++)
        {
        if(s[i]!=s[i-1])
            a[i]=a[i-1]+1;
        else
            a[i]=a[i-1];
        }
/*    for(i=0;i<len;i++)
        cout<<a[i]<<" ";*/
    cout<<"Case "<<coun<<":"<<endl;
    cin>>t;
    while(t--)
        {
        cin>>min>>max;
        if(min>max)
            {
            int temp=min;
            min=max;
            max=temp;
            }
        if(max>len)
            max=len-1;
        if(a[min]==a[max])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        //cout<<a[min]<<" "<<a[max]<<endl;
        }
    for(i=0;i<len;i++)
        {
        //s[i]='\0';
        a[i]=0;
        }
    gets(z);
    }
return 0;
}
