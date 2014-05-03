#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int main()
{
char a[100],b[]="#",c[100];
int i,j,k;
while(gets(a))
    {
    if(!strcmp(a,b))
        break;
    int n=strlen(a);
    int flag=0;
    for(i=0;i<n;i++)
        {
        if(a[i]<a[i+1]&&(i<=n-1))
            flag=1;
        }
    //cout<<flag<<endl;
    char nw;
    if(flag==1)
    {
    int x;
    for(i=n-1;i>=0;i--)
        {
        nw=a[i];
        //cout<<nw<<endl;
        j=i-1;
        while(nw<=a[j]&&(j>=0))
            j--;
        if(j>=0)
            if(nw>a[j])
                {
                c[j]=nw;
                break;
                }
        }
    for(k=0;k<n;k++)
        {
        if(k==i)
            continue;
        else if(k==j)
            {
            cout<<nw;
            k--; j=-1;
            }
        else
            cout<<a[k];
        }
    cout<<endl;
    }
    else
        cout<<"No Successor"<<endl;
    }
return 0;
}
