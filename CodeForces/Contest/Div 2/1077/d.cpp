#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> get(ll u){
  vector<ll> res;
  res.push_back(u);
  res.push_back(0);
  for(int i = 0; i <= 30; i++){
    ll mask = ~((1LL << (i + 1)) - 1);
    res.push_back((u & mask) | (1LL << i));
    res.push_back((u & mask) | ((1LL << i) - 1));
  }
  return res;
}

ll f(ll target, ll mask){
  ll base = target & (~mask);
  ll best = base;
  ll min_diff = abs(target - base);

  for(int i = 0; i <= 30; i++){
    if((mask >> i) & 1) continue;
    
    ll low = (1LL << i) - 1;
    ll prefix = base & ~low;

    ll v1 = prefix | (1LL << i);
    if(abs(target - v1) < min_diff){
      min_diff = abs(target - v1);
      best = v1;
    }

    ll v2 = (prefix & ~(1LL << i)) | (low & (~mask));
    if(abs(target - v2) < min_diff){
      min_diff = abs(target - v2);
      best = v2;
    }
  }
  return best;
}

void solve(){
  ll x, y;
  cin >> x >> y;

  ll ans1 = 0, ans2 = 0;
  ll mn = -1;

  vector<ll> cx = get(x);
  for(auto p : cx){
    ll q = f(y, p);
    ll cost = abs(x - p) + abs(y - q);
    if(mn == -1 || cost < mn){
      mn = cost;
      ans1 = p;
      ans2 = q;
    }
  }

  vector<ll> cy = get(y);
  for(auto q : cy){
    ll p = f(x, q);
    ll cost = abs(x - p) + abs(y - q);
    if(mn == -1 || cost < mn){
      mn = cost;
      ans1 = p;
      ans2 = q;
    }
  }

  cout << ans1 << " " << ans2 << endl;
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