#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n;
  cin >> n;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<ll> pref1(n+1, 0);
  vector<ll> pref2(n+1, 0);

  for (int i = 1; i <= n; i++)
  {
    pref1[i] = pref1[i-1] + a[i-1];
  }

  sort(a, a+n);

  for (int i = 1; i <= n; i++)
  {
    pref2[i] = pref2[i-1] + a[i-1];
  }

  int q;
  cin >> q;
  while (q--)
  {
    int t,a,b;
    cin >> t >> a >> b;

    if(t == 1){
      cout << pref1[b] - pref1[a-1] << endl;
    }else{
      cout << pref2[b] - pref2[a-1] << endl;
    }
  }
  
  
}