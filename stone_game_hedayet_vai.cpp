#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main()
{
    int n;
    while(cin>>n&&n)
    {
        int res=0;
        for(int i=0;i<n;i++)
        {
            int j;
            cin>>j;
            res^=j;
        }
        if(res==0)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
