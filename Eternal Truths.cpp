//Bismillahir Rahmanir Rahim

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

#define st 330

using namespace std;

int R,C;
char board[409][409];

int sx=0,sy=0,tx=0,ty=0,color[st][st][5],d[st][st][5];

int bfs()
{
    queue<pair<int,int> >Q;

    queue<int>P;


    for(int i=0;i<R;i++)
    for(int j=0;j<C;j++){
    if(board[i][j]=='S'){
        sx=i;
        sy=j;
    }
    else if(board[i][j]=='E')
    {
        tx=i;
        ty=j;
    }
    for(int k=0;k<=3;k++)
    color[i][j][k]=0;
    }

    Q.push(make_pair(sx,sy));
    P.push(0);
    d[sx][sy][0]=0;
    color[sx][sy][0]=1;

    int ret = 2147483647;

    while(!Q.empty())
    {
        pair<int,int>pa;
        pa=Q.front();Q.pop();
        int dis = (P.front()+1)%3;
        int dx=P.front();
        if(dis==0)dis=3;
        int ks = P.front();
        ks%=3;
        if(ks==0)ks=3;
        int u = pa.first,v=pa.second;

        if(pa.first==tx&&pa.second==ty)return d[tx][ty][ks];

        P.pop();

        int flag=0;
        if(u-dis<0)flag=1;
        else
        for(int x=u-dis;x<u;x++)
        {
            if(board[x][v]=='#')flag=1;
        }

        int nu=u-dis,nv=v;
        if(flag==0 && color[nu][nv][dis]==0){
            Q.push(make_pair(nu,nv));
            d[nu][nv][dis]=dx+1;
            P.push(dx+1);
            color[nu][nv][dis]=1;
        }
        flag=0;
        if(u+dis>=R)flag=1;
        else
        for(int x=u;x<=u+dis;x++)if(board[x][v]=='#')flag=1;
        nu=u+dis,nv=v;
        if(!flag && color[nu][nv][dis]==0){
        Q.push(make_pair(nu,nv));
        d[nu][nv][dis]=dx+1;
        P.push(dx+1);
        color[nu][nv][dis]=1;
        }


        flag=0;
        if(v-dis<0)flag=1;
        else
        for(int y=v-dis;y<v;y++)if(board[u][y]=='#')flag=1;
        if(!flag && color[u][v-dis][dis]==0){

            Q.push(make_pair(u,v-dis));
            d[u][v-dis][dis]=dx+1;
            P.push(dx+1);
            color[u][v-dis][dis]=1;
        }


        flag=0;
        if(v+dis>=C)flag=1;
        else
        for(int y=v;y<=v+dis;y++)if(board[u][y]=='#')flag=1;
        if(!flag && color[u][v+dis][dis]==0){
            Q.push(make_pair(u,v+dis));
            d[u][v+dis][dis]=dx+1;
            P.push(dx+1);
            color[u][v+dis][dis]=1;
        }

    }

    return -1;

}

int main()
{
    int kas,cas;
    cin>>kas;
    while(kas--)
    {
        cin>>R>>C;
        for(int i=0;i<R;i++)cin>>board[i];
        int ret = bfs();
        if(ret>=0)cout<<ret;
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}
