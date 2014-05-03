#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
vector <string> v;
//pushing element into the last of vector
v.push_back("russel");
v.push_back("nishat");
v.push_back("tasnim");
//printing elements of vector
for(int i=0;i<v.size();i++)
    cout<<v[i]<<endl;
    cout<<endl;
//printing elements with iterator
vector<string>::iterator it;

for(it=v.begin();it<v.end();it++)
    cout<<*it<<endl;
    cout<<endl;

//reverse with iterator
vector<string>::reverse_iterator itt;
for(itt=v.rbegin();itt<v.rend();itt++)
    cout<<*itt<<endl;
    cout<<endl;

v.push_back("R+N");

vector<string>::iterator t;

for(t=v.begin();t<v.end();t++)
    cout<<*t<<endl;
    cout<<endl;


vector<string>::reverse_iterator tt;
for(tt=v.rbegin();tt<v.rend();tt++)
    cout<<*tt<<endl;
    cout<<endl;
//swapping elements
cout<<"swap"<<endl;
cout<<v[0]<<" "<<v[2]<<endl;
swap(v[0],v[2]);
cout<<v[0]<<" "<<v[2]<<endl;
vector<string>::iterator tm;

for(tm=v.begin();tm<v.end();tm++)
    cout<<*tm<<endl;
    cout<<endl;


}
