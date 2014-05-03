//Bismillahir Rahmanir Rahim

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>

#define si  100000
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define mp make_pair
#define fo(i,n) for(int i=0;i<(n);i++)
#define sorta(a) sort(a.begin(),a.end())
#define sortab(a,n) sort(a,a+n)
#define sz size()
#define eps 0.000000000001

using namespace std;

typedef long long ll;
typedef vector<int>VI;
typedef vector<string>VS;
typedef set<int>SI;
typedef pair<int,int>par;
typedef vector<par>VP;

ll gcd(ll a,ll b)
{if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b)
{return (a/gcd(a,b))*b;}

bool eq(double a,double b)
{return !(fabs(a-b)>eps);}

int n,m,s,v;
double allowed_dis,gopherx[190],gophery[190],holex[190],holey[190];
int hole[190],pigeon[190];
bool graph[190][190],seen[190];
int matchR[109],matchL[109];


int bpm(int u)
{
    for(int v=0;v<n;v++)
    if(graph[u][v])
    {
        if(seen[v])continue;
        seen[v]=true;
        if(matchR[v]<0||bpm(matchR[v]))
        {
            matchL[u]=v;
            matchR[v]=u;
            return 1;
        }
    }
    return 0;
}

double dis(double a,double b,double c,double d)
{
    return ((a-c)*(a-c))+((b-d)*(b-d));
}

int main()
{
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	while(cin>>n)
	{
	    cin>>m>>s>>v;
	    allowed_dis=(double)(s*v);
	    allowed_dis*=allowed_dis;


	    for(int i=0;i<109;i++)
	    {
	        for(int j=0;j<109;j++)
	        graph[i][j]=false;
	    }

	    for(int i=0;i<n;i++)
	    {
	        double a,b;
	        cin>>a>>b;
	        gopherx[i]=a;
	        gophery[i]=b;
	    }
	    for(int i=0;i<m;i++)
	    {
	        double a,b;
	        cin>>a>>b;

	        for(int j=0;j<n;j++)
	        {
	            double ps=dis(a,b,gopherx[j],gophery[j]);
	            if(eq(ps,allowed_dis)||(allowed_dis>ps))
	            {
	                graph[j][i]=true;
	            }
	        }
	    }

	    for(int i=0;i<102;i++)
	    matchL[i]=matchR[i]=-1;
	    int count=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<102;j++)
	        seen[j]=false;
            count+=bpm(i);
	    }
	    cout<<n-count<<endl;

	}

	return 0;
}
