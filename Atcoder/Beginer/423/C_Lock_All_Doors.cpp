#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k;
  cin >> n >> k;

  ll a[n];
  ll kunci1 = -1;
  ll kunci2 = -1;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if(a[i] == 0 && kunci1 == -1){
      kunci1 = i;
      kunci2 = i;
      ans++;
    }else if(a[i] == 0){
      kunci2 = i;
      ans++;
    }
  }
  
  if(kunci1 == -1){
    cout << 0 << endl;
  }else{
    for (int i = kunci1; i <= kunci2; i++)
    {
      if(a[i] == 1){
        ans+=2;
      }
    }
    
    if(k<=kunci1){
      ans+=kunci1*2;
    }else if(k > kunci2){
      ans+=(k-1-kunci2)*2;
    }
    cout << ans << endl;
  }
}