#include<iostream>
using namespace std;

int main()
{
 string s;
   string paragraph;
   do {
    getline(cin, s);
    paragraph += s + "\n";
   } while (s.length() > 0);
cout<<paragraph;
}
