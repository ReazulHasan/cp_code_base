#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
char a[100][100];
int i,j,k;
for(i=0;i<5;i++)
    cin>>a[i];
for(i=0;i<5;i++)
    {
    for(j=0;j<5;j++)
        {
        cout<<a[i][j];
        }
    cout<<endl;
    }
}
