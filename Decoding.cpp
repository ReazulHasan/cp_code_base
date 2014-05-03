#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
int t,i,j,cas=0;
char a[5000];
cin>>t;
while(t--)
    {
    cas++;
    cin>>a;
    cout<<"Case "<<cas<<": ";
    int len=strlen(a);
    for(i=0;i<len;)
        {
        char c;
        c=a[i];
        i++;
        int x=a[i]-'0';
        i++;
        while(a[i]>='0'&&a[i]<='9'&&i<len)
            {
            x*=10;
            x+=a[i]-'0';
            i++;
            }
        for(j=1;j<=x;j++)
            cout<<c;
        }
    cout<<endl;
    }
return 0;
}
