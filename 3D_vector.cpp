#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
using namespace std;

vector<int> v[100][100];

int main()
{
int i,j,k;
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        {
        cin>>k;
        v[i][j].push_back(k);
        }
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    for(k=0;k<v[i][j].size();k++)
        {
        cout<<v[i][j][k];
        }
return 0;
}
