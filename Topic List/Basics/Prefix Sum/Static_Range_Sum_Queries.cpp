#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,t;
  cin >> n >> t;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<ll> pref(n+1);
  pref[0] = 0;
  for(int i = 1; i <=n ; i++){
    pref[i] = pref[i-1] + a[i-1];
  }

  for (int i = 0; i < t; i++)
  {
    int l,r;
    cin >> l >> r;
    cout << pref[r]-pref[l-1] << endl;
  }
  
}