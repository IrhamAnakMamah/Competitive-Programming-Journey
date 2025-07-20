#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE 
    freopen("div7.in", "r", stdin);   
    freopen("div7.out", "w", stdout); 
  #endif 
  int n;
  cin >> n;
  int a[n];
  vector<ll> pref(n+1);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + a[i-1];
  }

  int ans = 0;
  
  for (int i = n; i > 0; i--)
  {
    for (int j = 0; j <= i; j++)
    {
      if((pref[i]-pref[j])%7==0){
        ans = max(ans, i - j);
      }
    }
    
  }
  cout << ans << "\n";
}