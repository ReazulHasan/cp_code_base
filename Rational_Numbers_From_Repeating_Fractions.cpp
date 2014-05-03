#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

int GCD(int x,int y)
{
if(y==0)
    return x;
return GCD(y,x%y);
}

int main()
{
int k,i,h,j,cas=0;
string s;
while(cin>>k)
    {
    if(k==-1)
        break;
    cas++;
    cin>>s;
    int len=s.size();
    long long num=0,x=0,up,down;
    int ind=len-k;
    for(i=2;i<len;i++)
        {
        //cout<<s[i]<<endl;
        num*=10;
        num+=s[i]-'0';
        if(i<ind)
            {
            x*=10;
            x+=s[i]-'0';
            }
        }
    if(ind<len)
        up=num-x;
    else
        up=num;
    down=0;
    for(i=0;i<k;i++)
        {
        down*=10;
        down+=9;
        }
    if(down==0)
        down=1;
    for(i=0;i<(ind-2);i++)
        down*=10;
    int div=GCD(up,down);
    //cout<<div<<endl;
    if(div!=0)
        {
        up/=div;
        down/=div;
        }
    cout<<"Case "<<cas<<": "<<up<<"/"<<down<<endl;
    }
return 0;
}
