#include<iostream>
#include<vector>
int main()
{
    int n,i,a;
    vector <int> v;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    cout<<v;
return 0;
}
