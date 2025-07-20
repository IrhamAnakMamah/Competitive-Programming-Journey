#include <bits/stdc++.h>
using namespace std;

int main (){
  string s;
  cin >> s;
  cout << max({stoi(s),stoi(s.substr(0,s.length()-1)),stoi(s.substr(0,s.length()-2)+s[s.length()-1])});
}