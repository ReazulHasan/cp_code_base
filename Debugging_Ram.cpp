#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
using namespace std;

int main()
{
int i,j,k,bit,var,byt;
while(cin>>bit>>var)
    {
    string s;
    map<string,int> mpstr;
    map<int,string> mpint;
    map<int,unsigned long long> mpout;
    queue<int> q;
    int sum=0;
    for(i=1;i<=var;i++)
        {
        cin>>s>>byt;
        mpstr[s]=i;
        mpint[i]=s;
        q.push(byt);
        sum+=byt;
        }
    int pqr=0;
    while(!q.empty())
        {
        pqr++;
        int x=q.front(),pw,mn,fact=0;
        q.pop();
        int pos=bit*x-1;
        for(i=1;i<=x;i++)
            {
            cin>>s;
            for(k=0;k<bit;k++)
                {
                int rem=s[k]-'0';
                if(rem==1)
                    {
                    unsigned long long mult=1;
                    for(j=0;j<pos;j++)
                        mult*=2;
                    mpout[pqr]+=mult;
                    //if(pqr==2)
                    //cout<<mult<<endl;
                    }
                pos--;
                }
            }
        }
    int quer;
    cin>>quer;
    while(quer--)
        {
        cin>>s;
        if(mpstr[s]==0)
            cout<<s<<"="<<endl;
        else
            cout<<s<<"="<<mpout[mpstr[s]]<<endl;
        }
    }
return 0;
}
