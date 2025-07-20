#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll x[20];

long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

void comp(){
  for (int i = 0; i < 18; i++)
  {
    x[i] = binpow(2,i);
  }
}

int main(){
  comp();
  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
      a[i] = i+1;
    }
    
    bool ok = 0;
    do
    {
      
      ll sum = 0;
      bool bahaya = 0;
      for (int i = 0; i < n; i++)
      {
        sum+=x[a[i]-1];
        if(s[sum-1] == '1'){
          bahaya = 1;
        }
      }
      if(!bahaya){
        ok = 1;
      }
    } while (next_permutation(a.begin(), a.end()));
    cout << (ok ? "Yes" : "No") << endl;
  }
  
}