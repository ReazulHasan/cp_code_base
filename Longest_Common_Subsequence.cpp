#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int res[2000][2000];

int main()
{
char x[2000],y[2000];
int i,j,k;
while(gets(x))
    {
    gets(y);
    int lenx=strlen(x);
    int leny=strlen(y);
    for(i=0;i<=lenx;i++)
        for(j=0;j<=leny;j++)
            res[i][j]=0;
    for(i=0;i<lenx;i++)
        res[0][i]=0;
    for(i=0;i<leny;i++)
        res[i][0]=0;
    for(i=1;i<=lenx;i++)
        for(j=1;j<=leny;j++)
            {
            if(x[i-1]==y[j-1])
                res[i][j]=res[i-1][j-1]+1;
            else if(res[i-1][j]>res[i][j-1])
                res[i][j]=res[i-1][j];
            else
                res[i][j]=res[i][j-1];
            }
    cout<<res[lenx][leny]<<endl;
    /*
    for(i=0;i<lenx;i++)
        cout<<x[i];
    cout<<endl;
    for(i=0;i<leny;i++)
        cout<<y[i];
    cout<<endl;*/
    }
return 0;
}
