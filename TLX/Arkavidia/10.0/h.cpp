#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5+5;
ll tree[MAXN][26];
ll cnt[MAXN];
ll node = 1;
ll ans = 0;

void add (string s){
  int u = 1;
  for(auto c : s){
    int idx = c - 'a';
    if(!tree[u][idx]){
      node++;
      tree[u][idx] = node;
    }
    u = tree[u][idx];
    ans += cnt[u];
    cnt[u]++;
  }
}

void remove (string s){
  int u = 1;
  for(auto c : s){
    int idx = c - 'a';
    u = tree[u][idx];
    cnt[u]--;
    ans -= cnt[u];
  }
}

void solve(){
  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;

    add(s);
  }
  
  while (q--)
  {
    char c;
    cin >> c;
    if(c == '?'){
      cout << ans << endl;
    }else if(c == '+'){
      string s;
      cin >> s;
      add(s);
    }else{
      string s;
      cin >> s;
      remove(s);
    }
  }
  
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