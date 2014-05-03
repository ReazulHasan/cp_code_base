#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int knap[109][50009],coin[109];

int main()
{
int t,i,j,k,n;
cin>>t;
while(t--)
    {
    cin>>n;
    int tot=0;
    for(i=1;i<=n;i++)
        {
        cin>>coin[i];
        tot+=coin[i];
        }
    int m=tot;
    tot/=2;
    sort(coin,coin+n);
    for(i=0;i<=tot;i++)
        knap[0][i]=0;
    for(i=0;i<=n;i++)
        knap[i][0]=0;
    for(i=1;i<=n;)
        {
        int val=coin[i];
        for(j=1;j<=tot;j++)
            {
            if(j>=val)
                {
                if((val+knap[i-1][j-val])>knap[i-1][j])
                    knap[i][j]=(val+knap[i-1][j-val]);
                else
                    knap[i][j]=knap[i-1][j];
                }
            else
                knap[i][j]=knap[i-1][j];
            }
        i++;
        }
    int res=knap[n][tot];
    //cout<<res<<" "<<n<<" "<<tot<<endl;
    res*=2;
    cout<<m-res<<endl;
    for(i=0;i<=n;i++)
        for(j=0;j<=tot;j++)
            {
            knap[i][j]=0;
            coin[i]=0;
            }
    }
return 0;
}
