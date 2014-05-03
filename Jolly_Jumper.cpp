#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main()
{
int n,a,c,i,j;
while(cin>>n)
    {
    map<int,int> mp;
    int flag1=0,flag2=0,x;
    cin>>a;
    for(i=0;i<(n-1);i++)
        {
        flag1=1;
        cin>>c;
        if(a>c)
            x=a-c;
        else
            x=c-a;
        mp[x]=1;
        a=c;
        }
    if(flag1==0)
        cout<<"Jolly"<<endl;
    else
        {
        for(j=1;j<n;j++)
            if(mp[j]==0)
                {
                //cout<<j<<endl;
                flag2=1;
                cout<<"Not jolly"<<endl;
                break;
                }
        if(flag2==0)
                cout<<"Jolly"<<endl;
        }
    }
return 0;
}
