#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
using namespace std;

pair<double,double> pa;
vector<pair<double,double> > v;

double cross(double x1,double y1,double x2,double y2,double x3,double y3)
{
return (x2-x1)*(y3-y2)-(y2-y1)*(x3-x2);
}

int main()
{
int t,i,j,k,n;
double x,y;
while(cin>>n&&n)
    {
    v.clear();
    vector<pair<double,double> > res(n*2);
    for(i=0;i<n;i++)
        {
        cin>>x>>y;
        pa.first=x;
        pa.second=y;
        v.push_back(pa);
        }
    sort(v.begin(),v.end());
    k=0;
    for(i=0;i<n;i++)
        {
        while(k>=2&&cross(res[k-2].first,res[k-2].second,res[k-1].first,res[k-1].second,v[i].first,v[i].second)>=0)
            k--;
        res[k++]=v[i];
        }
    int t=k+1;
    for(i=n-1;i>=0;i--)
        {
        while(k>=t&&cross(res[k-2].first,res[k-2].second,res[k-1].first,res[k-1].second,v[i].first,v[i].second)>=0)
            k--;
        res[k++]=v[i];
        }
    if(n==(k-1))
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
    /*for(i=0;i<k;i++)
        cout<<res[i].first<<" "<<res[i].second<<endl;*/
    }
return 0;
}
