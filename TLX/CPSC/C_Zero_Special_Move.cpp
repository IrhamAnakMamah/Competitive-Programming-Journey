#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n,m;
  cin >> n >> m;
  ll x,y;
  cin >> x >> y;

  vector<ll> pref1(n+1, 0);
  vector<ll> pref2(n+1, 0);

  for (int i = 0; i < n; i++)
  {
    int a,b;
    cin >> a >> b;
    pref1[i+1] = pref1[i] + a;
    pref2[i+1] = pref2[i] + b;
  }
  
  int idx = 0;
  while (m--)
  {
    int a;
    cin >> a;

    cout << x + pref1[a] << " " << y + pref2[a] << endl;
  }
  
}