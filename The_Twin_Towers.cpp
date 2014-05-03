#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int res[1000][1000];

int main()
{
int i,j,k,first,second,cas=0;
int a[1000],b[1000];
while(cin>>first>>second)
    {
    if(first==0&&second==0)
        break;
    cas++;
    for(i=0;i<=first;i++)
        for(j=0;j<=second;j++)
            res[i][j]=0;
    for(i=0;i<first;i++)
        cin>>a[i];
    for(i=0;i<second;i++)
        cin>>b[i];
    for(i=0;i<=first;i++)
        res[0][i]=0;
    for(i=0;i<=second;i++)
        res[i][0]=0;
    for(i=1;i<=first;i++)
        for(j=1;j<=second;j++)
            {
            if(a[i-1]==b[j-1])
                res[i][j]=res[i-1][j-1]+1;
            else if(res[i-1][j]>res[i][j-1])
                res[i][j]=res[i-1][j];
            else
                res[i][j]=res[i][j-1];
            }
    cout<<"Twin Towers #"<<cas<<endl;
    cout<<"Number of Tiles : "<<res[first][second]<<endl;
    cout<<endl;
    }
return 0;
}
