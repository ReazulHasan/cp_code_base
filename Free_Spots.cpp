#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int main()
{
int i,j,k,a[600][600],ro,co,sub,x1,y1,x2,y2,temp;
while(cin>>co>>ro>>sub)
    {
    int coun=0;
    if(!ro&&!co&&!sub)
        break;
    for(i=0;i<ro;i++)
        for(j=0;j<co;j++)
            a[i][j]=0;
    for(i=0;i<sub;i++)
        {
        cin>>x1>>y1>>x2>>y2;
        if(x1>x2)
            {
            temp=x1;
            x1=x2;
            x2=temp;
            }
        if(y1>y2)
            {
            temp=y1;
            y1=y2;
            y2=temp;
            }
        x1--; y1--; x2--; y2--;
        for(j=y1;j<=y2;j++)
            for(k=x1;k<=x2;k++)
                a[j][k]=1;
        }
    for(i=0;i<ro;i++)
        for(j=0;j<co;j++)
            if(a[i][j]==0)
                coun++;
    if(coun==0)
        cout<<"There is no empty spots."<<endl;
    else if(coun==1)
        cout<<"There is one empty spot."<<endl;
    else
    cout<<"There are "<<coun<<" empty spots."<<endl;
    }
return 0;
}
