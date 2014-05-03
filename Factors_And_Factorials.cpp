#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

int a[1000],b[1000];
map<int,int> mp1,mp2;

int seive()
{
int i,j;
for(i=2;i*i<=200;i++)
    for(j=i+i;j<=200;j+=i)
        a[j]=1;
int k=0;
for(i=2;i<200;i++)
    if(a[i]==0)
        {
        b[k++]=i;
        mp1[i]=1;
        }
/*for(i=0;i<k;i++)
    cout<<b[i]<<" ";
cout<<endl;*/
}

int main()
{
int n,i,j;
set<int> s;
seive();
while(cin>>n&&n)
    {
    if(n==1)
        {
        printf("%3d! =  0\n",n);
        continue;
        }
    for(i=2;i<=n;i++)
        {
        int it=i;
        if(mp1[it]==1)
            mp2[it]++;
        else
            {
            int k=0;
            while(it>1)
                {
                while(it%b[k]==0)
                    {
                    mp2[b[k]]++;
                    it/=b[k];
                    }
                k++;
                }
            }
        }
    int q=1,l=1;
    printf("%3d! =",n);
    for(i=2;i<=n;i++)
        if(mp2[i]!=0)
            {
            s.insert(i);
            if(s.size()==16)
                printf("\n      ");
            printf("%3d",mp2[i]);
            }
    cout<<endl;
    mp2.clear(); s.clear();
    }
return 0;
}
