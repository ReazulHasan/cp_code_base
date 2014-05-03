#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int i,j;
vector<int> v;
vector<int>::iterator it;
v.push_back(1);
for(i=2;i<=100;i++)
    if(i%2==0||i%3==0||i%5==0||(i%2==0&&i%3==0)||(i%3==0&&i%5==0)||(i%5==0&&i%2==0)||(i%2==0&&i%3==0&&i%5==0))
        v.push_back(i);
for(it=v.begin();it<v.end();it++)
    cout<<*it<<endl;
return 0;
}
