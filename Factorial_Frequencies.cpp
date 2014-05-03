#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

#define sz 9000

char a[1009][sz+9];

int main()
{
int i,j,k,car;
for(i=0;i<=1005;i++)
    for(j=0;j<=sz;j++)
        a[i][j]='0';
a[0][sz]='1';
a[1][sz]='1';
a[2][sz]='2';
car=0;
for(i=3;i<=1005;i++)
    {
    int n=i;
    int pos=sz;
    int sum=0;
    while(n)
        {
        car=0;
        int x=n%10;
        n/=10;
        k=pos;
        sum=0;
        if(x>0)
        for(j=sz;j>=0;j--)
            {
            int y=a[i-1][j]-'0';
            int m=x*y;
            m+=car;
            int val=m%10;
            int fin=val+(a[i][k]-'0')+sum;
            int res=fin%10;
            sum=fin/10;
            car=m/10;
            a[i][k]=(res+'0');
            k--;
            }
        pos--;
        }
    if(sum>0)
        a[i][pos]=sum+'0';
    }
    int it;
    while(cin>>it&&it)
        {
        char ch;
        int fl=0;
        map<char,int> mp;
        mp.clear();
        long long s=0;
        for(i=0;i<=sz;i++)
            {
            if(a[it][i]>'0')
                fl=1;
            if(fl==1)
                mp[a[it][i]]++;
            }
        cout<<it<<"! --"<<endl;
        for(ch='0';ch<='9';ch++)
            {
            if(ch=='0'||ch=='5')
                cout<<"   ("<<ch<<")";
            else
                cout<<"    ("<<ch<<")";
            int r=mp[ch];
            printf("%5d",r);
            if(ch=='4')
                cout<<endl;
            }
        cout<<endl;
        }
return 0;
}
