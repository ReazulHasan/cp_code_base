#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<utility>
using namespace std;

pair<double,double> pa;
vector<pair<double,double> > v;

double convex_hull(double x1,double y1,double x2,double y2,double x3,double y3)
{
return (x2-x1)*(y3-y2)-(y2-y1)*(x3-x2);
}

int main()
{
int n,i,j,k,cas=0;
double x,y,poly,con;
while(cin>>n&&n)
    {
    cas++;
    vector<pair<double,double> > res(n*2);
    v.clear();
    for(i=0;i<n;i++)
        {
        cin>>x>>y;
        pa.first=x;
        pa.second=y;
        v.push_back(pa);
        }
    pa.first=v[0].first;
    pa.second=v[0].second;
    v.push_back(pa);
    poly=0;
    for(i=0;i<n;i++)
        poly+=((v[i].first)*(v[i+1].second)-(v[i+1].first)*(v[i].second));
    poly/=2.0;
    v.pop_back();
    sort(v.begin(),v.end());
    k=0;
    for(i=0;i<n;i++)
        {
        while(k>=2&&convex_hull(res[k-2].first,res[k-2].second,res[k-1].first,res[k-1].second,v[i].first,v[i].second)>=0)
            k--;
        res[k++]=v[i];
        }
    int t=k+1;
    for(i=n-1;i>=0;i--)
        {
        while(k>=t&&convex_hull(res[k-2].first,res[k-2].second,res[k-1].first,res[k-1].second,v[i].first,v[i].second)>=0)
            k--;
        res[k++]=v[i];
        }
    con=0.0;
    for(i=0;i<(k-1);i++)
        con+=((res[i].first*res[i+1].second)-(res[i+1].first*res[i].second))/2.0;
    if(poly<0)
        poly*=-1;
    if(con<0)
        con*=-1;
    //cout<<poly<<" "<<con<<endl;
    double fin=((con-poly)/con)*100.0;
    cout<<"Tile #"<<cas<<endl;
    printf("Wasted Space = %.2lf",fin);
    cout<<" %"<<endl<<endl;
    /*for(i=0;i<k;i++)
        cout<<res[i].first<<" "<<res[i].second<<endl;*/
    /*for(i=0;i<n;i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;*/
    }
return 0;
}
