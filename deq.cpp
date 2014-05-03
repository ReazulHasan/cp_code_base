#include<iostream>
#include<deque>
using namespace std;

int main()
{
deque<int> dq;
for(int i=0;i<5;i++)
    dq.push_front(i);
while(!dq.empty())
    {
    cout<<dq.front()<<" ";
    dq.pop_front();
    }
return 0;
}
