#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int main()
{
queue<int> q;
q.push(12);
q.push(75);
q.push(82);

q.back()-=q.front();
cout<<q.back()<<endl;

queue<int> q1;
int sum=0;
for(int i=1;i<=10;i++)
    q1.push(i);
while(!q1.empty())
    {
        sum+=q1.front();
        q1.pop();
    }
cout<<"The Sum is "<<sum<<endl<<endl;

queue <int> q2;
int x;
while(cin>>x&&x)
    {
    q2.push(x);
    }
cout<<"my queue contains: ";
cout<<q2.back();
while(!q2.empty())
    {
    cout<<q2.front()<<" ";
    q2.pop();
    }
return 0;
}
