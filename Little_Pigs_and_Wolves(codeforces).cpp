#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

string a[100];
int ro,co,maxn=0,coun=0;

int recur(int x)
{
int i,j,k;
/*if(x)
    coun++;*/
for(i=0;i<ro;i++)
    {
    for(j=0;j<co;j++)
        {
        if(a[i][j]=='W')
            {
            if(i-1>=0)
                if(a[i-1][j]=='P')
                    {
                    a[i][j]='.';
                    a[i-1][j]='.';
                    coun++;
                    recur(1);
                    a[i-1][j]='P';
                    a[i][j]='W';
                    coun--;
                    }
            if(j-1>=0)
                if(a[i][j-1]=='P')
                    {
                    a[i][j]='.';
                    a[i][j-1]='.';
                    coun++;
                    recur(1);
                    a[i][j-1]='P';
                    a[i][j]='W';
                    coun--;
                    }
            if(i+1<ro)
                if(a[i+1][j]=='P')
                    {
                    a[i][j]='.';
                    a[i+1][j]='.';
                    coun++;
                    recur(1);
                    a[i+1][j]='P';
                    a[i][j]='W';
                    coun--;
                    }
            if(j+1<co)
                if(a[i][j+1]=='P')
                    {
                    a[i][j+1]='.';
                    a[i][j]='.';
                    coun++;
                    recur(1);
                    a[i][j+1]='P';
                    a[i][j]='W';
                    coun--;
                    }
            }
        }
    }
if(maxn<coun)
    maxn=coun;
return 0;
}

int main()
{
int i,j,k;
cin>>ro>>co;
for(i=0;i<ro;i++)
    cin>>a[i];
recur(0);
cout<<maxn<<endl;
return 0;
}
