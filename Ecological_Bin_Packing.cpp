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
int a[15][15],b[20],c[100];
int i,j,k,p;
map<int,string> mp1,mp2;
mp1[0]="B";
mp1[1]="G";
mp1[2]="C";
for(i=0;i<9;i++)
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
int row,col,res=0;
k=0;
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        {
        int nw1=a[i][j],nw2,nw3;
        if(i==0&&j==0)
            {
            nw2=(nw1+a[i+1][j+1]+a[i+2][j+2]);
            nw3=(nw1+a[i+1][j+2]+a[i+2][j+1]);
            mp2[nw2]="BGC";
            mp2[nw3]="BCG";
            c[k++]=nw2;
            c[k++]=nw3;
            cout<<nw2<<" "<<nw3<<endl;
            }
        if(i==0&&j==1)
            {
            nw2=a[i+1][j-1]+a[i+2][j+2];
            nw3=a[i+2][j-1]+a[i+1][j+1];
            c[k++]=nw2;
            c[k++]=nw3;
            cout<<nw2<<" "<<nw3<<endl;
            }
        }
       for(i=0;i<k;i++)
            cout<<c[i]<<" ";
        cout<<endl;
        for(i=0;i<k;i++)
            cout<<mp2[c[i]]<<" ";
        cout<<endl;
return 0;
}
