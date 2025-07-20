#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  int a[n];
  vector<vector<ll>> pref(n+1,vector<ll>(4,0));

  for(int i = 0; i<n ;i++){
    cin >> a[i];
  }

  pref[0][0] = 0;
  pref[0][1] = 0;
  pref[0][2] = 0;
  for(int i = 1; i<=n ;i++){
    pref[i] = pref[i-1];
    pref[i][a[i-1]-1]++;
  }

  for (int i = 0; i < q; i++)
  {
    int l,r;
    cin >> l >> r;
    for (int j = 0; j < 3; j++)
    {
      cout << pref[r][j] - pref[l-1][j] << " ";
    }
    cout << "\n";
  }
  
}