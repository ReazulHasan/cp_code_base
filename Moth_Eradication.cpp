#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;

pair<double,double> pa;
vector<pair<double,double> >v;

double cross(double xa,double ya,double xb,double yb,double xc,double yc)
{
return (xb-xa)*(yc-yb)-(xc-xb)*(yb-ya);
}

int main()
{
int i,j,k,n,cas=0,fl=0;
double x,y;
while(cin>>n&&n)
    {
    cas++;
    v.clear();
    vector<pair<double,double> >res(2*n);
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
    if(fl)
        cout<<endl;
    fl=1;
    cout<<"Region #"<<cas<<":"<<endl;
    printf("(%.1lf,%.1lf)",res[k-1].first,res[k-1].second);
    for(i=k-2;i>=0;i--)
        printf("-(%.1lf,%.1lf)",res[i].first,res[i].second);
    cout<<endl;
    double dist=0;
    for(i=1;i<k;i++)
        {
        double x1,y1,x2,y2;
        x1=res[i-1].first; y1=res[i-1].second;
        x2=res[i].first; y2=res[i].second;
        dist+=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }
    printf("Perimeter length = %.2lf\n",dist);
        /*cout<<res[i].first<<" "<<res[i].second<<endl;
    /*for(i=0;i<k;i++)
        cout<<res[i].first<<" "<<res[i].second<<endl;
    /*for(i=0;i<n;i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;*/
    }
return 0;
}
