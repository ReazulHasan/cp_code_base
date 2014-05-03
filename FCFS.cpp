#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
using namespace std;

struct ss{
int burst,arr,proc,flag;
};

class comp{

int x;
public:
    bool operator() (const ss &a,const ss &b)
        {
        return a.arr>b.arr;
        }
};

vector<ss> v[1009];
priority_queue<ss,vector<ss>,comp> pq;

int main()
{

int i,j,k,num,b,a,p;
ss t;
cout<<"Please Enter the Total Number of Processes: ";
cin>>num;
cout<<"Please Enter the Process Number, Burst Time & Arrival Time consequently: "<<endl;
for(i=1;i<=num;i++)
    {
    cin>>p>>b>>a;
    t.proc=p;
    t.burst=b;
    t.arr=a;
    t.flag=0;
    pq.push(t);
    }
int x=0,y=0;
cout<<"The output is in the format ( Start-Procss_No-Finish )"<<endl;
while(!pq.empty())
    {
    if(y)
        cout<<" | ";
    //y=1;
    t=pq.top();
    pq.pop();
    if(y==0)
        {
        x=t.arr;
        }
    cout<<"( "<<x<<"-";
    //cout<<t.proc<<" "<<t.burst<<" "<<t.arr<<" "<<t.flag<<endl;
    cout<<"P"<<t.proc<<"-"<<x+t.burst<<" )";
    x+=t.burst;
    y=1;
    }

}
