#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
char a[150][150];
int r,c,i,j,count=0;
while(cin>>r>>c)
    {
    if(r==0&&c==0)
        break;
    count++;
    for(i=0;i<150;i++)
        for(j=0;j<150;j++)
            a[i][j]='.';
    for(i=0;i<r;i++)
            cin>>a[i];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(a[i][j]!='*')
                {
                a[i][j]='0';
                if(j>0)
                if(a[i][j-1]=='*')
                    a[i][j]++;
                if(j<c-1)
                if(a[i][j+1]=='*')
                    a[i][j]++;
                if(i>0)
                if(a[i-1][j]=='*')
                    a[i][j]++;
                if(i<r-1)
                if(a[i+1][j]=='*')
                    a[i][j]++;
                if(i>0&&j>0)
                if(a[i-1][j-1]=='*')
                    a[i][j]++;
                if(i>0&&j<c-1)
                if(a[i-1][j+1]=='*')
                    a[i][j]++;
                if(i<r-1&&j<c-1)
                if(a[i+1][j+1]=='*')
                    a[i][j]++;
                if(i<r-1&&j>0)
                if(a[i+1][j-1]=='*')
                    a[i][j]++;
                }
    if(count>1)
        cout<<endl;
    cout<<"Field #"<<count<<":"<<endl;
    for(i=0;i<r;i++)
        {
        for(j=0;j<c;j++)
            {
            if(a[i][j]=='*')
                cout<<a[i][j];
            else
                cout<<a[i][j];
            }
        cout<<endl;
        }
    }
return 0;
}
