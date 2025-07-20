#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = (int)s.length();
  bool ok = 1;
  bool no = 1;
  if(n&1) ok = 0;
  vector <int> a(26,0);
  for (int i = 0; i < (n/2); i++)
  {
    int x = 2*i;
    if(s[x]==s[x+1]){
      continue;
    }else{
      ok = 0;
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    a[s[i]-'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    if(a[i]==2 || a[i]==0){
      continue;
    }else{
      ok = 0;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}