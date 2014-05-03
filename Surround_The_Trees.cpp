#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;

pair<int,int> pa;
vector<pair<int,int> >v;

int cross(int xa,int ya,int xb,int yb,int xc,int yc)
{
return (xb-xa)*(yc-yb)-(xc-xb)*(yb-ya);
}

int main()
{
int i,j,k,n,cas=0,fl=0;
int x,y;
while(cin>>n&&n)
    {
    cas++;
    v.clear();
    vector<pair<int,int> >res(2*n);
    for(i=0;i<n;i++)
        {
        cin>>x>>y;
        pa.first=x;
        pa.second=y;
        v.push_back(pa);
        }
    sort(v.begin(),v.end());
    int k=0;
    for(i=0;i<n;i++)
        {
        while(k>=2&&cross(res[k-2].first,res[k-2].second,res[k-1].first,res[k-1].second,v[i].first,v[i].second)<=0)
            k--;
        res[k++]=v[i];
        }
    int t=k+1;
    for(i=n-2;i>=0;i--)
        {
        while(k>=t&&cross(res[k-2].first,res[k-2].second,res[k-1].first,res[k-1].second,v[i].first,v[i].second)<=0)
            k--;
        res[k++]=v[i];
        }
    double dist=0;
    for(i=1;i<k;i++)
        {
        int x1,y1,x2,y2;
        x1=res[i-1].first; y1=res[i-1].second;
        x2=res[i].first; y2=res[i].second;
        dist+=(double) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }
    dist+=0.001;
    printf("%.2lf\n",dist);
    }
return 0;
}
