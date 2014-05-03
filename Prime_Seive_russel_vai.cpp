#include <iostream>
using namespace std;

const int MAXN = 1000000;

int isPrime[MAXN+1];

void sieve(int n)
{
    isPrime[1]=0;
    for(int i=2;i<=n;i++) {
        isPrime[i] = 1;
    }
    for(int i=2;i*i<=n;i++) {
        if(!isPrime[i]) continue;
        for(int j=i*2;j<=n;j+=i) {
            isPrime[j]=0;
        }
    }
    for(int i=2;i<=n;i++) {
        if(!isPrime[i]) continue;
        cout<<i<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    sieve(n);
}
