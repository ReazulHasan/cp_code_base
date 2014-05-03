#include<iostream>
#include<cstdio>
#include<deque>
#include<queue>
using namespace std;

int main()
{
/*deque<int> q1;
deque<string> q2;
q1.assign(7,100);*/
priority_queue<int> pq;
for(int i=0;i<10;i++)
    pq.push(i);
cout<<pq.top();
}
