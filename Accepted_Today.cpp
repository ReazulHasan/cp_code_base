#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<string>
#include<cstring>
using namespace std;

int main()
{
int i,j,k,per,gol,sil,cop,me,n,h,m,s,metot,metime;
while(cin>>per>>gol>>sil>>cop>>me)
    {
    pair<int,int> pa;
    vector<pair<int,int> > v;
    vector<int> vec;
    if(per==0&&gol==0&&sil==0&&cop==0&&me==0)
        break;
    for(i=0;i<per;i++)
        {
        cin>>n;
        int fuki=0;
        scanf("%d:%d:%d",&h,&m,&s);
        fuki=h*3600+m*60+s;
        if(i==me-1)
            {
            metot=n;
            metime=fuki;
            }
        pa.first=n; pa.second=fuki;
        v.push_back(pa);
        }
    sort(v.begin(),v.end());
    int len=v.size();
    int pos,sam=0;
    for(i=0;i<len;i++)
        {
        if(metot==v[i].first&&metime==v[i].second)
            {
            pos=i;
            }
        if(metot==v[i].first)
            if(metime>v[i].second)
                {
                sam++;
                //cout<<v[i].first<<" fi "<<v[i].second<<endl;
                }
        if(metot<v[i].first)
            {
            sam++;
            //cout<<v[i].first<<" hi "<<v[i].second<<endl;
            }
        }
    //cout<<sam<<endl;
    pos=sam+1;
    if(pos<=gol)
        cout<<"Accepted today? I've got a golden medal :)"<<endl;
    else if(pos>gol&&pos<=(gol+sil))
        cout<<"Accepted today? I've got a silver medal :)"<<endl;
    else if(pos>(gol+sil)&&pos<=(gol+sil+cop))
        cout<<"Accepted today? I've got a copper medal :)"<<endl;
    else
        cout<<"Accepted today? I've got an honor mentioned :)"<<endl;
    }
return 0;
}
