#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    ll cnt[2] = {0,0};
    ll a[2] = {0,0};
    for (int i = 0; i < n; i++)
    {
      ll x;
      cin >> x;
      a[i%2]+=x;
      cnt[i%2]+=1;
    }

    bool ok = (a[0] % cnt[0] == 0 && a[1] % cnt[1] == 0 && a[0]/cnt[0] == a[1]/cnt[1]);
    cout << (ok ? "YES" : "NO") << endl;
  }
  
}