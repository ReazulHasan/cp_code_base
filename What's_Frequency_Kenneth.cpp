#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
map<char,int> mp1;
map<int,char> mp2;
int b[10000],i;
char a[10000],c;
while(gets(a))
    {
    int len=strlen(a),high=0;
    for(i=0;i<len;i++)
        {
        if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z'))
            {
            mp1[a[i]]++;
            if(high<mp1[a[i]])
                high=mp1[a[i]];
            }
        }
    if(high>0)
        {
        for(c='A';c<='Z';c++)
            if(mp1[c]==high)
                {
                cout<<c;
                mp1[c]=0;
                }
        for(c='a';c<='z';c++)
            if(mp1[c]==high)
                {
                cout<<c;
                mp1[c]=0;
                }
        cout<<" "<<high<<endl;
        mp1.clear();
        }
    }
return 0;
}
