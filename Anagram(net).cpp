#include <algorithm>
#include <iostream>
#include <cctype>
using namespace std;
string s;
bool comp(const char &a, const char &b) {
    int delta = tolower(a) - tolower(b);
    return delta ? delta < 0 : a <b;
}
int main() {
    int cas;
    cin>>cas;
    while (cas--)
    {
        cin >> s;
        sort(s.begin(), s.end(), comp);
        cout<<s<<endl;
        do
            cout << s << endl;
        while (next_permutation(s.begin(), s.end(), comp));
    }
    return 0;
}
