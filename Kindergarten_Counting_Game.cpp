#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;

int main()
{
queue<char> q;
char a[10000];
int i,j,k,coun=0;
while(gets(a))
    {
    int flag=0;
    for(i=0;i<strlen(a);i++)
        q.push(a[i]);
    int n=q.size();
    while(!q.empty())
        {
        char it=q.front();
        q.pop();
        if((it>='A'&&it<='Z')||(it>='a'&&it<='z'))
            {
            coun++;
            char p=q.front();
            while(((p>='A'&&p<='Z')||(p>='a'&&p<='z'))&&!q.empty())
                {
                q.pop();
                p=q.front();
                }
            while((p<'A'||(p>'Z'&&p<'a')||p>'z')&&!q.empty())
                {
                q.pop();
                p=q.front();
                }
            }
        }
    cout<<coun<<endl;
    coun=0;
    q.empty();
    }
return 0;
}
