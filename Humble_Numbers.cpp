#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

vector<long long> v;

int humble_number()
{
double hm=2000000000;
int i,j,k,p;
for(i=0;i<=32;i++)
    for(j=0;j<=20;j++)
        for(k=0;k<=14;k++)
            for(p=0;p<=12;p++)
                {
                double x;
                x=pow(2.0,i)*pow(3.0,j)*pow(5.0,k)*pow(7.0,p);
                double mon=x*1.0;
                if(mon>hm)
                    break;
                else
                    {
                    long long vou=(long long) x;
                    v.push_back(vou);
                    }
                }
sort(v.begin(),v.end());
return 0;
}

string suffix(int n)
{
if((n%100)/10==1)
    return "th";
else if(n%10==1)
    return "st";
else if(n%10==2)
    return "nd";
else if(n%10==3)
    return "rd";
else
    return "th";
}

int main()
{
humble_number();
int n;
while(cin>>n&&n)
    {
    string s1=suffix(n);
    //cout<<s1<<endl;
    cout<<"The "<<n<<s1<<" humble number is "<<v[n-1]<<"."<<endl;
    //printf("The %d%s humble number is %lld.\n",n,s1,v[n-1]);
    }
return 0;
}
