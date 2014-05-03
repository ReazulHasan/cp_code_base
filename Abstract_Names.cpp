#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main()
{
int t,i,j,k;
char a[100],b[100],z[10];
map<char,int> mp;
mp['a']=1;mp['e']=1;mp['i']=1;mp['o']=1;mp['u']=1;
cin>>t;
gets(z);
while(t--)
    {
    gets(a);
    gets(b);
    int lena=strlen(a);
    int lenb=strlen(b);
    if(lena!=lenb)
        cout<<"No"<<endl;
    else
        {
        int flag=0;
        for(i=0;i<lena;i++)
            {
            if(mp[a[i]]==mp[b[i]])
                {
                if(mp[a[i]]==0)
                    if(a[i]!=b[i])
                        {
                        flag=1;
                        cout<<"No"<<endl;
                        break;
                        }
                }
            else
                {
                flag=1;
                cout<<"No"<<endl;
                break;
                }
            }
        if(flag==0)
            cout<<"Yes"<<endl;
        }
    }
return 0;
}
