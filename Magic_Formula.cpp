#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
int i,j,k;
int f,a,b,c,d,l;
while(cin>>a>>b>>c>>d>>l)
    {
    if(a==0&&b==0&&c==0&&d==0&&l==0)
        break;
    int coun=0;
    for(i=0;i<=l;i++)
        {
        int m=i;
        f=a*m*m+b*m+c;
        if((f%d)==0)
            coun++;
        }
    cout<<coun<<endl;
    }
return 0;
}
