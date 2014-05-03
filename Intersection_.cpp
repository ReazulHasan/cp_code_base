#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct ss{
    int x,y;
};

vector<ss> v;

int direction(int p,int q,int r)
{
return ((v[p].x-v[r].x)*(v[q].y-v[r].y)-(v[q].x-v[r].x)*(v[p].y-v[r].y));
}

int on_seg(int p,int q,int r)
{
int a,b,maxx,minx,maxy,miny;
a=v[r].x; b=v[r].y;
maxx=max(v[p].x,v[q].x);
minx=min(v[p].x,v[q].x);
maxy=max(v[p].y,v[q].y);
miny=min(v[p].y,v[q].y);
if(a>=minx&&a<=maxx&&b<=maxy&&b>=miny)
    return 1;
return 0;
}

int main()
{
int cas,i,j,k,a,b,c,d;
ss t;
cin>>cas;
while(cas--)
    {
    v.clear();
    cin>>a>>b>>c>>d;
    t.x=a; t.y=b;
    v.push_back(t);
    t.x=c; t.y=d;
    v.push_back(t);
    cin>>a>>b>>c>>d;
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    if(a<c&&d>b)
        {
        //cout<<"1"<<endl;
        t.x=a; t.y=d;
        v.push_back(t);
        t.x=c; t.y=b;
        v.push_back(t);
        }
    else if(a<c&&b>d)
        {
        //cout<<"2"<<endl;
        t.x=a; t.y=b;
        v.push_back(t);
        t.x=c; t.y=d;
        v.push_back(t);
        }
    else if(a>c&&d>b)
        {
        //cout<<"3"<<endl;
        t.x=c; t.y=d;
        v.push_back(t);
        t.x=a; t.y=b;
        v.push_back(t);
        }
    else if(a>c&&b>d)
        {
        //cout<<"4"<<endl;
        t.x=c; t.y=b;
        v.push_back(t);
        t.x=a; t.y=d;
        v.push_back(t);
        }
    t.x=v[2].x; t.y=v[3].y;
    v.push_back(t);
    t.x=v[3].x; t.y=v[2].y;
    v.push_back(t);
//cout<<v.size()<<endl;
/*    for(i=0;i<v.size();i++)
        cout<<v[i].x<<" v "<<v[i].y<<endl;*/

    if(v[0].x>=v[2].x&&v[0].x<=v[3].x&&v[0].y<=v[2].y&&v[0].y>=v[3].y)
        {
        cout<<"T"<<endl;
        continue;
        }
    if(v[1].x>=v[2].x&&v[1].x<=v[3].x&&v[1].y<=v[2].y&&v[1].y>=v[3].y)
        {
        cout<<"T"<<endl;
        continue;
        }
    int flag=1;
    for(i=2;i<=3;i++)
        {
        k=4;
        int m=0;
        double d1,d2,d3,d4;
        while(m<2)
            {
            m++;
            //cout<<v[i].x<<" "<<v[i].y<<" "<<v[k].x<<" "<<v[k].y<<endl;
            d1=direction(i,k,0);
            d2=direction(i,k,1);
            d3=direction(0,1,i);
            d4=direction(0,1,k);
            //cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
            if(((d1<0&&d2>0)||(d1>0&&d2<0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
                {
                flag=0;
                cout<<"T"<<endl;
                break;
                }
            else if(d1==0&&on_seg(i,k,0))
                {
                flag=0;
                cout<<"T"<<endl;
                break;
                }
            else if(d2==0&&on_seg(i,k,1))
                {
                flag=0;
                cout<<"T"<<endl;
                break;
                }
            else if(d3==0&&on_seg(0,1,i))
                {
                flag=0;
                cout<<"T"<<endl;
                break;
                }
            else if(d4==0&&on_seg(1,0,k))
                {
                flag=0;
                cout<<"T"<<endl;
                break;
                }
            k++;
            }
        if(flag==0)
            break;
        }
    if(flag)
        cout<<"F"<<endl;
    }
return 0;
}
