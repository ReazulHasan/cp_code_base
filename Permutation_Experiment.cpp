#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
char str[100];
string s,s1;
int i,j,k,cas;
cin>>cas;
while(cas--)
    {
    vector<string> v;
    cin>>s;
    sort(s.begin(),s.end());
    int len=s.size();
    for(i=0;i<len;i++)
        {
        //cout<<s[i];
        str[i]=s[i];
        }
    //cout<<endl;
    v.clear();
    while(next_permutation(str,str+len))  //next_permutation() is used to generate the permutations.
        {                                 //It works on a char array. Header file needed is
        s1.clear();                       //#include<algorithm>
        for(i=0;i<len;i++)
            {
            //cout<<str[i];
            s1+=str[i];
            }
        v.push_back(s1);
        //cout<<endl;
        }
    return 0;
    }
return 0;
}
