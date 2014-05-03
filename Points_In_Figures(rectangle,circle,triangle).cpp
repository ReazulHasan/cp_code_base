#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

struct ss{
    char ch;
    double x1,y1,x2,y2,x3,y3,x4,y4,rad;
};

vector<ss> v,po;
double x,y,eps=0.00000001;

int circle(int m)
{
double p,q,r;
p=v[m].x1; q=v[m].y1; r=v[m].rad;
double dis=sqrt((x-p)*(x-p)+(y-q)*(y-q));
if(dis<r)
    return 1;
return 0;
}

int rect(int m)
{
//if(fabs(x-v[m].x1)>=eps&&fabs(v[m].x2-x)>=eps&&fabs(y-v[m].y2)>=eps&&fabs(v[m].y1-y)>=eps)
if(x>v[m].x1&&x<v[m].x2&&y>v[m].y2&&y<v[m].y1)
    return 1;
return 0;
}

double area(double p1,double q1,double p2,double q2,double p3,double q3)
{
double fu=(p1*q2+p2*q3+p3*q1-p1*q3-p3*q2-p2*q1);
if(fu<0)
    fu*=-1;
return fu;
}

int main()
{
int i,j,k=0;
double p,q,r,s,w,z;
char c;
ss t;
while(cin>>c)
    {
    if(c=='*')
        break;
    if(c=='r')
        {
        t.ch=c;
        cin>>p>>q>>r>>s;
        t.x1=p; t.y1=q; t.x2=r; t.y2=s;
        v.push_back(t);
        }
    if(c=='c')
        {
        t.ch=c;
        cin>>p>>q>>r;
        t.x1=p; t.y1=q; t.rad=r;
        v.push_back(t);
        }
    if(c=='t')
        {
        t.ch=c;
        cin>>p>>q>>r>>s>>w>>z;
        t.x1=p; t.y1=q; t.x2=r; t.y2=s; t.x3=w; t.y3=z;
        v.push_back(t);
        }
    }
int coun=0;
while(cin>>p>>q)
    {
    coun++;
    if((p==9999.9)&&(q==9999.9))
        break;
    //t.x1=p; t.y1=q;
    //po.push_back(t);
    //int len=po.size();
    int sz=v.size();
    //for(i=0;i<len;i++)
    //{
    int flag=0;
    //x=po[i].x1; y=po[i].y1;
    x=p; y=q;
    for(j=0;j<sz;j++)
        {
        c=v[j].ch;
        if(c=='c')
            {
            int res=circle(j);
            if(res)
                {
                flag=1;
                cout<<"Point "<<coun<<" is contained in figure "<<j+1<<endl;
                }
            }
        if(c=='r')
            {
            int res=rect(j);
            if(res)
                {
                flag=1;
                cout<<"Point "<<coun<<" is contained in figure "<<j+1<<endl;
                }
            }
        if(c=='t')
            {
            ss d;
            d=v[j];
            double p1,q1,p2,p3,q2,q3,p4,q4;
            p1=d.x1; q1=d.y1; p2=d.x2; q2=d.y2; p3=d.x3; q3=d.y3;
            double tri=area(p1,q1,p2,q2,p3,q3);
            double tri1,tri2,tri3,tri4;
            tri1=area(p1,q1,x,y,p2,q2);
            tri2=area(p2,q2,x,y,p3,q3);
            tri3=area(p1,q1,x,y,p3,q3);
            //cout<<tri<<" "<<tri1+tri2+tri3<<" tri"<<endl;
            tri4=tri1+tri2+tri3;
            if(fabs(tri4-tri)<=eps)
                {
                double hi,fi,ji;
                hi=(x-p1)*(q1-q2)-(y-q1)*(p1-p2);
                fi=(x-p1)*(q1-q3)-(y-q1)*(p1-p3);
                ji=(x-p2)*(q2-q3)-(y-q2)*(p2-p3);
                if(hi<0) hi*=-1;
                if(fi<0) fi*=-1;
                if(ji<0) ji*=-1;
                if(hi>eps&&fi>eps&&ji>eps)
                    {
                    flag=1;
                    cout<<"Point "<<coun<<" is contained in figure "<<j+1<<endl;
                    }
                }
            }
        }
        if(flag==0)
            cout<<"Point "<<coun<<" is not contained in any figure"<<endl;
        //}
    }
/*int len=v.size();
for(i=0;i<len;i++)
    {
    c=v[i].ch;
    if(c=='c')
        cout<<"c "<<v[i].x1<<" "<<v[i].y1<<" "<<v[i].rad<<endl;
    if(c=='t')
        cout<<"t "<<v[i].x1<<" "<<v[i].y1<<" "<<v[i].x2<<" "<<v[i].y2<<" "<<v[i].x3<<" "<<v[i].y3<<endl;
    if(c=='r')
        cout<<"r "<<v[i].x1<<" "<<v[i].y1<<" "<<v[i].x2<<" "<<v[i].y2<<endl;
    }*/
return 0;
}
