#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int color[1000009];

int main()
{
int i,j,k;
for(i=1;i<=1000000;i++)
    {
    if(color[i]==0)
        {
        int num=i;
        while(num<=1000000)
            {
            int x=num;
            while(x>0)
                {
                num+=x%10;
                x/=10;
                }
            if(color[num]==1)
                break;
            else
                color[num]=1;
            }
        }
    }
for(i=1;i<=1000000;i++)
    if(color[i]==0)
        cout<<i<<endl;
return 0;
}
