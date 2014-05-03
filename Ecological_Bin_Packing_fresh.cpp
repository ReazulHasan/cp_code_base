#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
long long a[15][15],b[20],c[100],x;
int i,j,k,p;
map<int,string> mp;
while(cin>>x)
    {
    b[0]=x;
    for(i=1;i<9;i++)
        cin>>b[i];
    for(i=0;i<9;i++)
        {
        p=i%3;
        if(i<3)
            a[p][0]=b[i+3]+b[i+6];
        else if(i>=3&&i<6)
            a[p][1]=b[i-3]+b[i+3];
        else if(i>=6&&i<9)
            a[p][2]=b[i-3]+b[i-6];
        }
    c[3]=a[1][0]+a[2][1]+a[0][2];
        mp[c[3]]="GCB";
    c[2]=a[1][0]+a[0][1]+a[2][2];
        mp[c[2]]="GBC";
    c[5]=a[2][0]+a[1][1]+a[0][2];
        mp[c[5]]="CGB";
    c[4]=a[2][0]+a[0][1]+a[1][2];
        mp[c[4]]="CBG";
    c[1]=a[0][0]+a[1][1]+a[2][2];
        mp[c[1]]="BGC";
    c[0]=a[0][0]+a[2][1]+a[1][2];
        mp[c[0]]="BCG";
    sort(c,c+6);
    cout<<mp[c[0]]<<" "<<c[0]<<endl;
    mp.clear();
    }
return 0;
}
