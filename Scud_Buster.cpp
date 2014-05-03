#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

int now=0;
double Total=0;

struct ss{
double x,y;
};

ss res[209][209];

double cross(double x1,double y1,double x2,double y2,double x,double y)
{
return (x2-x1)*(y-y2)-(x-x2)*(y2-y1);
}

int test_point(double a,double b)
{
int i,j,k;
int coun=0;
ss p1,p2;
for(i=0;i<now;i++)
    {
    if(res[i][199].x!=-1)
        {
        int len=(int) res[i][200].x;
        p1=res[i][0];
        for(j=1;j<len;j++)
            {
            p2=res[i][j];
            if(b>min(p1.y,p2.y))
                if(b<max(p1.y,p2.y))
                    if(a<max(p1.x,p2.x))
                        if(p1.y!=p2.y)
                            {
                            double xinters=p1.x+((b-p1.y)*(p2.x-p1.x))/(p2.y-p1.y);
                            if(p1.x==p2.x||a<xinters)
                                coun++;
                            }
            p1=p2;
            }
        //cout<<"coun "<<coun<<endl;
        if(coun%2==1)
            {
            //cout<<"yes"<<endl;
            double sum=0;
            res[i][199].x=-1;
            for(k=0;k<len-1;k++)
                {
                sum+=res[i][k].x*res[i][k+1].y-res[i][k+1].x*res[i][k].y;
                }
            Total+=sum/2;
            break;
            }
        }
    }
return 0;
}

int main()
{
int n,i,j,k;
double x,y;
pair<double,double> pa;
vector<pair<double,double> > v[120];
while(cin>>n)
    {
    if(n==-1)
        break;
    for(i=0;i<n;i++)
        {
        cin>>x>>y;
        pa.first=x;
        pa.second=y;
        v[now].push_back(pa);
        }
    sort(v[now].begin(),v[now].end());
    now++;
    }
for(j=0;j<now;j++)
    {
    k=0;
    int sz=v[j].size();
    for(i=0;i<sz;i++)
        {
        while(k>=2&&cross(res[j][k-2].x,res[j][k-2].y,res[j][k-1].x,res[j][k-1].y,v[j][i].first,v[j][i].second)<=0)
            k--;
        res[j][k].x=v[j][i].first;
        res[j][k].y=v[j][i].second;
        k++;
        }
    int t=k+1;
    for(i=sz-2;i>=0;i--)
        {
        while(k>=t&&cross(res[j][k-2].x,res[j][k-2].y,res[j][k-1].x,res[j][k-1].y,v[j][i].first,v[j][i].second)<=0)
            k--;
        res[j][k].x=v[j][i].first;
        res[j][k].y=v[j][i].second;
        k++;
        }
    /*for(i=0;i<k;i++)
        cout<<res[j][i].x<<" "<<res[j][i].y<<endl;*/
    res[j][200].x=k;
    }
    while(cin>>x>>y)
        {
        /*if(x==999&&y==999)
            break;*/
        test_point(x,y);
        }
printf("%.2lf\n",Total);
return 0;
}
