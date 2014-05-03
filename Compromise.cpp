#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<stack>
using namespace std;

int res[6000][6000];
char path[6000][6000];
stack<int> fin;
vector<int> vf,vl;

int print_lcs(int a,int b)
{
int i,j,k;
if(a==0||b==0)
    return 0;
if(path[a][b]=='y')
    {
    fin.push(vf[a-1]);
    print_lcs(a-1,b-1);
    }
else if(path[a][b]=='u')
    print_lcs(a-1,b);
else
    print_lcs(a,b-1);
}

int main()
{
string s,s1;
int i,j,k;
map<string,int> mpsf,mpsl;
map<int,string> mpif,mpil;
while(getline(cin,s))
    {
    int ind=1,fl=0;
    while(1)
        {
        int len=s.size();
        if(s[0]=='#')
            fl++;
        if(fl==2)
            break;
        if(s[0]!='#')
        for(i=0;i<len;)
            {
            while(s[i]!=' '&&i<len)
                {
                s1+=s[i];
                i++;
                }
            if(mpsf[s1]==0)
                {
                mpsf[s1]=ind;
                mpif[ind]=s1;
                if(fl==0)
                    vf.push_back(ind);
                if(fl==1)
                    vl.push_back(ind);
                ind++;
                }
            else
                {
                if(fl==0)
                    vf.push_back(mpsf[s1]);
                else if(fl==1)
                    vl.push_back(mpsf[s1]);
                }
            //cout<<s1<<endl;
            s1.clear();
            while(s[i]==' '&&i<len)
                i++;
            }
        getline(cin,s);
        }
    int lenf=vf.size();
    int lenl=vl.size();
    for(i=0;i<=lenf;i++)
        res[0][i]=0;
    for(i=0;i<=lenl;i++)
        res[i][0]=0;
    for(i=1;i<=lenf;i++)
        for(j=1;j<=lenl;j++)
            {
            if(vf[i-1]==vl[j-1])
                {
                res[i][j]=res[i-1][j-1]+1;
                path[i][j]='y';
                }
            else
                {
                if(res[i-1][j]>res[i][j-1])
                    {
                    res[i][j]=res[i-1][j];
                    path[i][j]='u';
                    }
                else
                    {
                    res[i][j]=res[i][j-1];
                    path[i][j]='l';
                    }
                }
            }
    //cout<<res[lenf][lenl]<<endl;
    print_lcs(lenf,lenl);
    if(!fin.empty())
        {
        int oh=fin.top();
        cout<<mpif[oh];
        fin.pop();
        }
    while(!fin.empty())
        {
        int oh=fin.top();
        cout<<" "<<mpif[oh];
        fin.pop();
        }
    cout<<endl;
    mpsf.clear(); mpif.clear();
    mpsl.clear(); mpil.clear();
    vf.clear(); vl.clear();
    s.clear(); s1.clear();
    for(i=0;i<=lenf;i++)
        for(j=0;j<=lenl;j++)
            {
            res[i][j]=0;
            path[i][j]='\0';
            }
    /*cout<<"first"<<endl;
    for(i=0;i<vf.size();i++)
        cout<<vf[i]<<endl;
    cout<<"second"<<endl;
    for(i=0;i<vl.size();i++)
        cout<<vl[i]<<endl;*/
    }
return 0;
}
