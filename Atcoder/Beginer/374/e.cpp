#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, x;
  cin >> n >> x;

  int a[n], b[n], p[n], q[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> p[i] >> b[i] >> q[i];
  }

  auto cek = [&] (int x){
    
    int cost = x;
    bool ok = 1;
    for (int i = 0; i < n; i++)
    {

    }
    
    return ok;
  };

  int l = 0;
  int r = 1e9;
  while(l<r){
    int mid = (l+r)/2;
    if(cek(mid)){
      r = mid;
    }else{
      l = mid+1;
    }
  }
  cout << r << endl;
  
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
