#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main()
{
//stack<char> st;
char a[10000],b[10000];
int i,j;
while(gets(a))
    {
    int len=strlen(a);
    a[len]=' ';
    int k=0;
    for(i=0;i<=len;i++)
        {
        if(a[i]==' ')
            {
            for(j=i-1;j>=k;j--)
                cout<<a[j];
            if(i<len-1)
                cout<<" ";
            k=i+1;
            }
        }
        cout<<endl;
    }
return 0;
}
