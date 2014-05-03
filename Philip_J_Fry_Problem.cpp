#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
int i,j,k,n,x,y;
while(cin>>n&&n)
    {
    pair<int,int> pa;
    vector<pair<int,int> > v;
    for(i=0;i<n;i++)
        {
        cin>>x>>y;
        pa.first=x;
        pa.second=y;
        v.push_back(pa);
        }
    sort(v.begin(),v.end());
    int res=0,flag[500],sphere=0,minx=91474837;
    for(k=0;k<n;k++)
        {
        for(i=0;i<=n;i++)
            flag[i]=0;
        res=0; sphere=0;
        flag[k]=1;
        x=v[k].first; y=v[k].second;
        res+=x;
        cout<<"res1: "<<res<<endl;
        sphere+=y;
        while(1)
            {
            /*if(flag[i])
                continue;*/
            int fl=1;
            for(j=0;j<n;j++)
                if(!flag[j])
                    fl=0;
            if(fl)
                break;
            if(sphere>0)
                {
                if(sphere==1)
                    {
                    for(j=n-1;j>=0;j--)
                        if(flag[j]==0&&v[j].second>0)
                            {
                            res+=(v[j].first)/2;
                            sphere+=v[j].second;
                            }
                    }
                else
                for(j=n-1;j>=0;j--)
                    {
                    int p,q;
                    if(sphere>1)
                        {
                        if(flag[j]==0)
                            {
                            sphere--;
                            flag[j]=1;
                            p=v[j].first; q=v[j].second;
                            res+=p/2;
                            cout<<"res2: "<<res<<endl;
                            sphere+=q;
                            }
                        }
                    else break;
                    }
                }
            if(!sphere)
                {
                for(j=0;j<n;j++)
                    {
                    int p,q;
                    if(sphere) break;
                    if(flag[j]==0)
                        {
                        flag[j]=1;
                        p=v[j].first; q=v[j].second;
                        sphere+=q;
                        res+=p;
                        cout<<"res3: "<<res<<endl;
                        if(sphere)
                            break;
                        }
                    }
                }
            }
        cout<<"minx: "<<minx<<", res: "<<res<<endl;
        if(res<minx)
            minx=res;
        }
        cout<<minx<<endl;
        //cout<<v[i].first<<" "<<v[i].second<<endl;
    }
return 0;
}
