#include <iostream>
using namespace std;
int memo[5009];

int fib (int n)
{
	if(n==0)return 0;
	if(n==1)return 1;
	if(n==2)return 1;
	if(memo[n]!=-1)return memo[n];
	memo[n]=fib(n-1)+fib(n-2);
	return memo[n];
}

int main()
{
	int i,n;
	while(cin>>n){
	for(i=0;i<5009;i++)
	memo[i]=-1;
	cout<<"The Fibonacci number for "<<n<<" "<<"is"<<" "<<fib(n)<<endl;
	}
	return 0;
}