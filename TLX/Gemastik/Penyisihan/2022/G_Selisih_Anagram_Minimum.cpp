#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  string temp1 = s.substr(s.length()-2,2);
  string temp2 = "aa";
  temp2[0] = s[s.length()-1];
  temp2[1] = s[s.length()-2];
  cout << abs(stoi(temp1) - stoi(temp2)) << endl;
}