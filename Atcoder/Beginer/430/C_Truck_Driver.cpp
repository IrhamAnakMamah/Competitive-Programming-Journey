#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n,a,b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  vector<ll> pref1(n+1, 0), pref2(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    pref1[i] = pref1[i-1] + (s[i-1] == 'a');
    pref2[i] = pref2[i-1] + (s[i-1] == 'b');
  }
  
  ll ans = 0;
  ll idx1 = 0;
  ll idx2 = 0;
  for (ll i = 0; i < n; i++)
  {
    if(idx1 < i) idx1 = i;
    if(idx2 < i) idx2 = i;
    while (idx1 < n && pref1[idx1 + 1] - pref1[i] < a)
    {
      idx1++; 
    }

    while (idx2 < n && pref2[idx2 + 1] - pref2[i] < b)
    {
      idx2++;
    }
    if (idx1 < n && idx1 < idx2){
      ans += (idx2 - idx1);
    }
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
  
}