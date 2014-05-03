#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<string>]
#include<cstring>
using namespace std;

int main()
{
int i,j,k,corse,cat;
while(cin>>corse&&corse)
    {
    string x;
    map<string,int> mp;
    cin>>cat;
    for(i=0;i<corse;i++)
        {
        cin>>x;
        //cout<<x<<endl;
        mp[x]=1;
        }
    int flg=0;
    for(i=0;i<cat;i++)
        {
        int tot,must,coun=0;
        cin>>tot>>must;
        for(j=0;j<tot;j++)
            {
            cin>>x;
            if(mp[x]==1)
                coun++;
            }
        if(coun<must)
            {
            flg=1;
            }
        }
    if(flg==1)
        cout<<"no"<<endl;
    else
        cout<<"yes"<<endl;
    }
return 0;
}
