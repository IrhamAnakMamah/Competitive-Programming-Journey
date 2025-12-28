#include <bits/stdc++.h>
using namespace std;

void solve(){
  string s;
  cin >> s;
  
  int ans = 0;
  for (int i = 0; i < (int)s.length(); i++)
  {
    if(i == 0 && s[i] == 'u'){
      if(s[i+1] == 's'){
        ans++;
        s[i] = 's';
      }
    }else if(i == ((int)s.length()-1) && s[i] == 'u'){
      ans++;
    }else if(s[i] == 'u'){
      int l = i-1;
      int r = i+1;
      int ok = 0;
      while (l >= 0 && r < (int)s.length())
      {
        if(s[l] == 's' && s[r] == 's'){
          ok = 1;
          break;
        }else if(s[l] == 's'){
          ok = 2;
          break;
        }else if(s[r] == 's'){
          ok = 3;
          break;
        }
        l--;
        r++;
      }
      if(ok == 0){
        s[i-1] = 's';
        s[i+1] = 's';
        ans+=2;
      }else if(ok == 3){
        s[l] = 's';
        ans++;
      }else if(ok == 2){
        s[r] = 's';
        ans++;
      }
    }
  }
  cout << ans << endl;
  
}

int main(){
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