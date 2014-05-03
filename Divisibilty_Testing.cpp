#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int ro[100005],co[100005];

int main()
{
int i,j,k,t,div,n,x;
vector<int> v;
cin>>t;
while(t--)
    {
    int coun=0;
    cin>>n>>div;
    for(i=0;i<n;i++)
        {
        cin>>x;
        v.push_back(x);
        }
    sort(v.begin(),v.end());
    for(i=0;i<(n-1);i++)
        {
        int it=v[i];
        for(j=i+1;j<n;j++)
            {
            int ti=v[j];
            x=it+ti;
            if(x%div==0&&(ro[it]==0||co[ti]==0))
                {
                ro[it]=1; co[ti]=1;
                cout<<it<<" "<<ti<<endl;
                coun++;
                }
            }
        }
    cout<<coun<<endl;
    }
return 0;
}
