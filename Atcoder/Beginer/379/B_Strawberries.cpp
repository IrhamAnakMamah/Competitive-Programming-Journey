#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if(s[i]=='O'){
      cnt++;
    }else{
      cnt = 0;
    }

    if(cnt == k){
      ans++;
      cnt = 0;
    }
  }
  cout << ans << "\n";
}