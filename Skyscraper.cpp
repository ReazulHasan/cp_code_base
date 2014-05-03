#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
typedef long long ll;
using namespace std;

struct ss{
int star,len,c;
};

class comp{
    public:
    bool operator()(const ss &a,const ss &b){
                    return a.star>b.star;
                    };
};

priority_queue<ss,vector<ss>,comp> pq;
int a[200009];

int main()
{
ss t;
int i,j,k,cas,ad,x,y,z,star,len,c;
cin>>cas;
while(cas--)
    {
    cin>>ad;
    for(i=0;i<ad;i++)
        {
        cin>>x>>y>>z;
        t.star=x;
        t.len=y;
        t.c=z;
        pq.push(t);
        }
    int last=0,past=0,res=0;
    while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        star=t.star; len=t.len; c=t.c;
        if(a[star]>0)
            {
            if(a[star]>c+last)
                {
                for(i=star;i<star+len;i++)
                    a[i]=a[star];
                res=a[star];
                }
            else
                {
                int m=a[star];
                for(i=star;i<star+len;i++)
                    a[i]=c+last;
                res=c+last;
                last=m;
                }
            }
        else
            {
            if(past)
                for(i=past;i<star;i++)
                    a[i]=a[i-1];
            int cos=a[i]+c;
            for(i=star;i<star+len;i++)
                a[i]=cos;
            res=cos;
            }
        past=last+len;
        //cout<<t.star<<" "<<t.len<<" "<<t.c<<endl;
        }
    cout<<res<<endl;
    }
return 0;
}
