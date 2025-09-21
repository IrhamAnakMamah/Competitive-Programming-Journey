#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  string s;
  cin >> s;

  if(n >= 3){
    cout << (s.substr(n-3, 3) == "tea" ? "Yes" : "No") << endl;
  }else{
    cout << "No" << endl;
  }
}