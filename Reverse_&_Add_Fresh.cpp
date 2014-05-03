#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<deque>
#include<queue>
using namespace std;

vector<int>v;
stack<int> st;
deque<int> dq,dq1,dq2;
queue<int> q;
int b[100],n=0,m;

int is_pal()
{
int it1,it2,flag=0,con=0,i;
n=dq.size()-1;
m=n;
//cout<<m<<endl;
while(!dq.empty())
    {
    if(dq.size()==1)
        {
        b[con++]=dq.front();
        //cout<<dq.front()<<" last"<<endl;
        dq.pop_front();
        return 1;
        }
    it1=dq.front();
    dq.pop_front();
    it2=dq.back();
    dq.pop_back();
    b[con++]=it1;
    b[n--]=it2;
    //cout<<"b "<<b[con-1]<<" "<<b[n+1]<<endl;
    //cout<<"it"<<it1<<" "<<it2<<endl;
    if(it1!=it2)
        {
        while(!dq.empty())
            {
            b[con++]=dq.front();
            dq.pop_front();
            }
        /*for(i=0;i<3;i++)
            cout<<b[i]<<" ";
        cout<<endl;*/
        return 0;
        }
    }
return 1;
}

int main()
{
char a[1000];
int i,j,k,t;
cin>>t;
for(j=1;j<=t;j++)
    {
    cin>>a;
    for(i=0;i<strlen(a);i++)
        dq.push_back(a[i]-'0');
    int coun=0;
    while(1)
        {
        int s=dq.size();
        if(is_pal())
            {
            cout<<coun<<" ";
            for(i=0;i<s;i++)
                cout<<b[i];
            cout<<endl;
            break;
            }
        coun++;
        for(i=0;i<s;i++)
            {
            dq1.push_back(b[i]);
            dq2.push_front(b[i]);
            //dq.pop_front();
            //cout<<b[i]<<" ";
            }
        //cout<<endl;
        dq.clear();
        int p=dq1.size();
        int car=0;
        for(i=0;i<p;i++)
            {
            int x=dq1.back()+dq2.back()+car;
            //cout<<"x "<<x<<" ";
            if(x<10)
                {
                dq.push_back(x);
                car=0;
                }
            else
                {
                dq.push_back(x%10);
                car=x/10;
                }
            dq1.pop_back(); dq2.pop_back();
            }
        //cout<<endl;
        if(car>0)
            dq.push_back(car);
        }
    q.empty(); dq.clear(); n=0; dq1.clear(); dq2.clear();
    for(i=0;i<100;i++)
        b[i]=0;
    }
return 0;
}
