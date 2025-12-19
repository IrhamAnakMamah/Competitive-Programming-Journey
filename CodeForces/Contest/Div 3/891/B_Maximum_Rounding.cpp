#include <bits/stdc++.h>
using namespace std;

void solve(){
  string s;
  cin >> s;

  int sz = s.length();
  int hapus = sz;
  int cnt = 0;
  for (int i = sz-2; i >= 0; i--)
  {
    int temp = s[i+1] - '0';
    if((temp + cnt) >= 5){
      if(s[i] == '9'){
        cnt = 1;
      }else{
        cnt = 0;
        s[i] = s[i] + 1;
      }
      hapus = i+1;
    }else{
      s[i] = s[i] + cnt;
      cnt = 0;
    }
  }
  
  if(s[0] - '0' >= 5){
    cnt++;
    s[0] = '0';
    hapus = 0;
  }

  if(cnt){
    s[0] = '0';
  }
  for (int i = hapus; i < sz; i++)
  {
    s[i] = '0';
  }

  if(cnt){
    cout << 1;
  }
  cout << s << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  
  return 0;
}