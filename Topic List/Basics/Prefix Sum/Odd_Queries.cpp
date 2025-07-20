#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,q;
    cin >> n >> q;
    int a[n];
    vector<ll> pref(n+1);
      
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    pref[0] = 0;
    for (int i = 1; i <= n; i++)
    {
      pref[i] = pref[i-1] + a[i-1];
    }
    
    
    for(int i = 0; i<q; i++){
      int l,r,x;
      cin >> l >> r >> x;
      int temp = pref[r]-pref[l-1];
      cout << ((pref[n]-temp+((r-l+1)*x))&1 ? "YES" : "NO") << endl;
    }
  }
  
}