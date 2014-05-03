#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<queue>

using namespace std;
int ar[1000009];
int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,a,b,c,x,y,z,fast,last,ar[3],br[3];
    while(cin>>ar[0]>>ar[1]>>ar[2])
    {
        if(!ar[0]&&!ar[1]&&!ar[2])break;
        sort(ar,ar+3);
        //for(i=0;i<3;i++)
         //   cout<<ar[i]<<" ";
        //cout<<endl;
        if((ar[0]==ar[1])&&(ar[1]==ar[2]))
        {
            cout<<"jj"<<endl;
            if(ar[0]==13){cout<<"*"<<endl;continue;}
            cout<<ar[0]+1<<" "<<ar[1]+1<<" "<<ar[2]+1<<endl;
        }
        else if(ar[0]==ar[1]||ar[1]==ar[2])
        {
            cout<<"sss"<<endl;
            if(ar[0]==ar[1])
            {
                cout<<"sss"<<endl;
                if(ar[2]==13){cout<<ar[0]+1<<" 9"<<ar[1]+1<<" "<<13<<endl;continue;}
                //br[0]=ar[0];br[1]=ar[1];br[2]=ar[2]+1;
                //sort(br,br+3);
                //cout<<br[0]<<" "<<br[1]<<" "<<br[2]<<endl;
            }
            if(ar[1]==ar[2])
            {
                if(ar[0]==12&&ar[1]==13){cout<<1<<" "<<1<<" "<<1<<endl;continue;}
                if(ar[0]==(ar[1]-1))
                {
                    br[0]=1;br[1]=ar[1]+1;br[2]=ar[2]+1;
                    sort(br,br+3);
                    cout<<br[0]<<" "<<br[1]<<" "<<br[2]<<endl;
                }
                else{
                cout<<br[0]+1<<" "<<br[1]<<" "<<br[2]<<endl;
                }
            }
        }
        else
        {
            cout<<"di"<<endl;
            if(ar[0]==11&&ar[1]==12&&ar[2]==13)
            {
                cout<<1<<" "<<1<<" "<<2<<endl;continue;
            }
            if((ar[0]==(ar[1]-1))&&(ar[1]==ar[2]-1))
            {
                cout<<ar[0]<<" "<<ar[1]<<" "<<ar[2]+1<<endl;
            }
            else if(ar[0]==(ar[1]-1))
            {
                cout<<ar[0]<<" "<<ar[1]+1<<" "<<ar[2]<<endl;
            }
            else
            {
                cout<<ar[0]+1<<" "<<ar[1]<<" "<<ar[2]<<endl;

            }

        }


    }

return 0;
}
