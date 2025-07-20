#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin >> n;
  ll a[n];
  vector<ll> pref(n+1);
  vector<ll> spref(n+1);//already sort prefix sum
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  pref[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + a[i-1];
  }
  
  sort(a,a+n);
  for (int i = 1; i <= n; i++)
  {
    spref[i] = spref[i-1] + a[i-1];
  }
  
  int q;
  cin >> q;
  while (q--)
  {
    int t,l,r;
    cin >> t >> l >> r;
    if(t==1){
      cout << pref[r] - pref[l-1] << "\n";
    }else{
      cout << spref[r] - spref[l-1] << "\n";
    }
  }
  
}