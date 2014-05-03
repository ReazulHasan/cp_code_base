#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
using namespace std;

int main()
{
//pair<char,int> pa;
vector< pair<char,int> > v;
char x;
int y,i,j;
while(cin>>x>>y&&x&&y)
    {
    pair<char,int> pa(x,y);
    v.push_back(pa);
    }
int len=v.size();
cout<<len<<endl;
for(i=0;i<len;i++)
    cout<<v[i]<<endl;
return 0;
}
