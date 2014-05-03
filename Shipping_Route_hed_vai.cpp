                                    //Bismillahir Rahmanir Rahim//


#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
int N,E;
vector<int>adj[10000];
map<string,int>mymap;


int BFS(int a,int b)
{
    int i,n,j,k,l,m,color[10000],d[10000],u,v;
    deque<int>Q;
    Q.clear();
    Q.push_back(a);
    for(i=0;i<N;i++)
    {
        color[i]=0;
    }
    color[a]=0;
    d[a]=0;
    while(!Q.empty())
    {
        u=Q.front();
        if(u==b)
        return d[u];
        Q.pop_front();
        for(i=0;i<adj[u].size();i++)
        {
            if(color[adj[u][i]]==0)
            {
                d[adj[u][i]]=d[u]+1;
                color[adj[u][i]]=1;
                Q.push_back(adj[u][i]);
            }
        }
    }
    return -1;
}




int main()
{
    int i,n,j,k,l,m,ca,u,v,ka;
    string a,b,c,d;

    cin>>ca;
    cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;
    for(ka=0;ka<ca;ka++)
    {
        cin>>N>>E>>n;
        {
            for(i=0;i<1000;i++)
            adj[i].clear();
            mymap.clear();
            cout<<"DATA SET  "<<ka+1<<endl<<endl;

            for(i=0;i<N;i++)
            {
                cin>>a;
                mymap[a]=i;
            }

            for(i=0;i<E;i++)
            {
                cin>>a>>b;
                u=mymap[a];
                v=mymap[b];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            for(i=0;i<n;i++)
            {
                cin>>j>>a>>b;
                u=mymap[a];
                v=mymap[b];
                int res;
                res=BFS(u,v);
                if(res>-1)
                cout<<"$"<<res*100*j<<endl;
                else
                cout<<"NO SHIPMENT POSSIBLE"<<endl;
            }
            cout<<endl;
        }

    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
