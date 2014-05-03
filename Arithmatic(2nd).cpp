#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

int len1,len2,len3;

int convert(string s1,string s2,int bas)
{
int i,j,k,coun;
stack<int> st;
int rem=0;
if(len1>len2)
    {
    coun=len2-1;
    for(i=len1-1;i>=0;i--)
        {
        int x;
        if(coun>=0)
            x=(s1[i]-'0')+(s2[coun]-'0')+rem;
        else
            x=s1[i]-'0'+rem;
        int now=x%bas;
        if(now==0)
            st.push(now);
        else
        while(now)
            {
            st.push(now%10);
            now/=10;
            }
        //st.push(x%bas);
        rem=x/bas;
        coun--;
        }
    }
else
    {
    coun=len1-1;
    for(i=len2-1;i>=0;i--)
        {
        int x;
        if(coun>=0)
            x=(s1[coun]-'0')+(s2[i]-'0')+rem;
        else
            x=s2[i]-'0'+rem;
        int now=x%bas;
        if(now==0)
            st.push(now);
        else
        while(now)
            {
            st.push(now%10);
            now/=10;
            }
        //st.push(x%bas);
        rem=x/bas;
        coun--;
        }
    }
if(rem>0)
    st.push(rem);
int res=0;
while(!st.empty())
    {
    res*=10;
    res+=st.top();
    st.pop();
    }
return res;
}

int main()
{
int i,j,k,cas;
cin>>cas;
while(cas--)
    {
    string s1,s2,s3,ss,se;
    cin>>s1>>ss>>s2>>se>>s3;
    len1=s1.size(); len2=s2.size(); len3=s3.size();
    int maxn=0,x=0,y=0,fin=0,sep1=0,sep2=0,sep3=0;
    for(i=0;i<len1;i++)
        {
        x*=10;
        x+=s1[i]-'0';
        if(maxn<s1[i]-'0')
            maxn=s1[i]-'0';
        if((s1[i]-'0')==1)
            sep1++;
        }
    for(i=0;i<len2;i++)
        {
        y*=10;
        y+=s2[i]-'0';
        if(maxn<s2[i]-'0')
            maxn=s2[i]-'0';
        if(s2[i]-'0'==1)
            sep2++;
        }
    for(i=0;i<len3;i++)
        {
        fin*=10;
        fin+=s3[i]-'0';
        if(maxn<s3[i]-'0')
            maxn=s3[i]-'0';
        if(s3[i]-'0'==1)
            sep3++;
        }
    if(sep1==len1&&sep2==len2&&sep3==len3)
        {
        if((sep1+sep2)==sep3)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
        }
    else
        {
        int flg=1;
        for(i=maxn+1;i<=18;i++)
            {
            int z=convert(s1,s2,i);
            //cout<<i<<" : "<<x<<" "<<y<<" "<<z<<endl;
            if((fin==z))
                {
                if(i==1)
                    cout<<"2"<<endl;
                else
                    cout<<i<<endl;
                flg=0;
                break;
                }
            }
        if(flg)
            cout<<"0"<<endl;
        }
    }
return 0;
}
