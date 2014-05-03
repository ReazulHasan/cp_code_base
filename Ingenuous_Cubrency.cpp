#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

unsigned long long a[100000];

int main()
{
int i,j,k;
vector<int> coin;
a[0]=1;
coin.push_back(1);
for(i=2;i<=21;i++)
    {
    long long x=i*i*i;
    coin.push_back(x);
    }
int len=coin.size();
for(i=0;i<len;i++)
    {
    int c=coin[i];
    for(j=0;j<30000;j++)
        a[j+c]+=a[j];
    }
int m;
while(cin>>m)
    {
    cout<<a[m]<<endl;
    }
/*for(i=0;i<len;i++)
    cout<<coin[i]<<" ";
cout<<endl;*/
return 0;
}
