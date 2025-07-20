#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> pref(n+1,0);
  for (int i = 0; i < n; i++)
  {
    
    pref[i+1] = pref[i];
  }
  
}