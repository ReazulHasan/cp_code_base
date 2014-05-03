#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> v;

int ugly_number()
{
int i,j,k;
//v.push_back(1);
for(i=0;i<=100;i++)
    for(j=0;j<=100;j++)
        for(k=0;k<=100;k++)
            {
            double x=pow(2.0,i)*pow(3.0,j)*pow(5.0,k);
            if(x<100000000000000LL)
                {
                long long mn=(long long) x;
                v.push_back(mn);
                }
            }
sort(v.begin(),v.end());
}

int main()
{
//ugly_number();
//cout<<v[1498]<<" "<<v[1499]<<" "<<v[1500]<<endl;
printf("The 1500'th ugly number is 859963392.\n");
return 0;
}
