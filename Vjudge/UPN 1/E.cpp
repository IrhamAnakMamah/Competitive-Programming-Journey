#include <bits/stdc++.h>
using namespace std;

int main (){
  string s,t;
  cin >> s >> t;
  int a = s.length()-1, x = 0;
  vector <int> v;
  for (int i = 0; i < t.length(); i++){
    if(s[x]==t[i]){
      v.push_back(i+1);
      x++;
    }
  }
  for(auto it : v){
    cout << it << " ";
  }
  cout << "\n";
  return 0;
}