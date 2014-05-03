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
#define eps 0.00000000001
#define pi 2.0*acos(0.0)

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



int main()
{
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	int kas;cin>>kas;
	while(kas--)
	{
	    double r,m[10],n[10];

	    cin>>r;
	    for(int i=0;i<3;i++){
	        double a,b;
	        cin>>a>>b;
	        m[i]=a,n[i]=b;
	    }

	    double hi = 100000000000LL,low=0;


	    while(1)
	    {
	        if(eq(hi,low))break;

	        double x = m[0]+n[0];


	        double mid = (hi+low)/2.0;
	        double a1=(mid/x)*m[0],a2=(mid/x)*n[0];

	        double b1 = a2, b2 = (b1/m[1])*n[1];
	        double c1 = a1,c2 = b2;


	        double a = a1+a2, b = b1+b2, c = c1+c2;

	        double s = a+b+c;
	        s/=2.0;

	        double f = sqrt(((s-a)*(s-b)*(s-c))/s);

	        if(eq(f,r)){
	        printf("%.4lf\n",sqrt(s*(s-a)*(s-b)*(s-c)));
	        break;
	        }


	        else if(f>r)
	        {
	            hi=mid;
	        }
	        else low=mid;
	    }
	}

	return 0;
}
