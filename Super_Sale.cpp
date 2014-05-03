#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<utility>
using namespace std;

int knap[1000][1000],price[1000][1000];

int main()
{
int i,j,k,t,goods,x,y,p;
pair<int,int> pa;
vector<pair<int,int> > v;
vector<int> per;
cin>>t;
while(t--)
    {
    pa.first=-1;
    pa.second=-1;
    v.push_back(pa);
    cin>>goods;
    for(i=0;i<goods;i++)
        {
        cin>>x>>y;
        pa.first=y;
        pa.second=x;
        v.push_back(pa);
        }
    cin>>p;
    for(i=0;i<p;i++)
        {
        cin>>x;
        per.push_back(x);
        }
    sort(v.begin(),v.end());
    sort(per.begin(),per.end());
    int n=v.size();
    //cout<<n<<endl;
    int len=per.size();
    //cout<<len<<endl;
    for(i=0;i<len;i++)
        {
        int bag=per[i];
        //cout<<bag<<endl;
        for(j=0;j<=bag;j++)
            {
            knap[0][j]=0;
            price[0][j]=0;
            }
        for(j=0;j<=n;j++)
            {
            knap[j][0]=0;
            price[j][0]=0;
            }
        for(j=1;j<n;j++)
            {
            int it=v[j].first;
            cout<<it<<endl;
            for(k=1;k<=bag;k++)
                {
                if(k>=it)
                    {
                    if((it+knap[j-1][k-it])>knap[j-1][k])
                        {
                        knap[j][k]=(it+knap[j-1][k-it]);
                        if()
                        price[][]
                        }
                    else
                        knap[j][k]=knap[j-1][k];
                    }
                else
                    knap[j][k]=knap[j-1][k];
                }
            }
        cout<<knap[n-1][bag]<<endl;
    for(i=0;i<n;i++)
        {
        for(j=0;j<=bag;j++)
            cout<<knap[i][j]<<" ";
        cout<<endl;
        }
        }
    /*for(i=0;i<v.size();i++)
        cout<<v[i].second<<" "<<v[i].first<<endl;
    for(i=0;i<per.size();i++)
        cout<<per[i]<<endl;*/
    v.clear(); per.clear();
    }
return 0;
}
