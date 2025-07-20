#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < 50000; i++)
  {
    s+="aa";
    s+="bb";
  }
  cout << s.substr(0,n) << "\n";
}