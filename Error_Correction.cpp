#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define max 100

int main()
{
int a[max+9][max+9];
int i,j,k,n,b[max+9],c[max+9];
while(cin>>n&&n)
    {
    for(i=0;i<max;i++)
        for(j=0;j<max;j++)
        {
        a[i][j]=0;
        b[i]=0;
        c[i]=0;
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
            b[i]+=a[i][j];
            c[j]+=a[i][j];
            }
    int coun1=0,coun2=0,row,col;
    for(i=0;i<n;i++)
        {
        if(b[i]%2==1)
            {
            coun1++;
            row=i;
            }
        if(c[i]%2==1)
            {
            coun2++;
            col=i;
            }
        }
    if(coun1==0&&coun2==0)
        cout<<"OK"<<endl;
    else if(coun1>1||coun2>1)
        cout<<"Corrupt"<<endl;
    else
        cout<<"Change bit ("<<row+1<<","<<col+1<<")"<<endl;
    }
return 0;
}
