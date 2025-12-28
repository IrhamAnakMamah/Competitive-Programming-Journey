#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  vector<pair<int,int>> st;
  
  for (int i = 0; i < n; i++)
  {
    if(i == 0){
      st.push_back({a[i], 1});
    }else{
      if(st.back().first == a[i]){
        st.back().second++;
        if(st.back().second == 4){
          st.pop_back();
        }
      }else{
        st.push_back({a[i], 1});
      }
    }
  }
  
  int ans = 0;
  for(auto [_, x] : st){
    ans += x;
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  
  return 0;
}