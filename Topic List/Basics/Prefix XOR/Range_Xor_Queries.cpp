#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  int a[n];
  vector<int> pref(n+1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  
  pref[1] = a[1];
  for (int i = 2; i <= n; i++)
  {
    pref[i] = pref[i-1]^a[i];
  }
  
  while (q--)
  {
    int l,r;
    cin >> l >> r;
    cout << (pref[l-1]^pref[r]) << "\n";
  }
  

}