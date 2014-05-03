#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int main()
{
int a[100][100];
int i,j,k,coun=0;
int n;
while(cin>>n&&n)
    {
    coun++;
    int rang=n/2;
    if(n%2==1)
        rang++;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    int rolo=0,rohi=n-1;
    int colo=0,cohi=n-1;
    cout<<"Case "<<coun<<":";
    while(rang--)
        {
        int sum=0;
        for(i=rolo;i<=rohi;i++)
            for(j=colo;j<=cohi;j++)
                {
                if(i==rolo||i==rohi||j==colo||j==cohi)
                    sum+=a[i][j];
                }
        cout<<" "<<sum;
        rolo++; colo++; rohi--; cohi--;
        }
    cout<<endl;
    }
return 0;
}
