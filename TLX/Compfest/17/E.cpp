#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const ll MOD = 998244353;

int main(){
  ll n,d,k;
  cin >> n >> d >> k;
  vector<ll> petak(n+2, 0);
  vector<ll> tetap1(n+2, 0);
  vector<ll> tetap2(n+2, 0);
  petak[1] = 1;
  tetap1[1] = 1;
  for (ll xx = 0; xx < k; xx++)
  {
    vector<ll> pref (n+2, 0);
    vector<ll> pref2 (n+2, 0);
    vector<ll> uhuy = tetap2;
    for (ll i = 1; i <= n+1; i++)
    {
      if(tetap1[i-1] <= 0){
        continue;
      }
      int temp = d - (n - i);
      if(temp > 0){
        int bagi = temp/(n-1);
        if(bagi&1){
          if(temp % (n-1) != 0){
            pref[1] += tetap1[i-1];
            pref[temp % (n-1)] += -1 * tetap1[i-1];   
          }
          
          pref2[n] += bagi*tetap1[i-1];
          pref2[1] += -1*bagi*tetap1[i-1];
          
          pref[1] += bagi * tetap1[1];
          pref[n] += -1 * bagi * tetap1[i-1];
        }else{
          if(bagi == 0){
            bagi = INT_MAX;
          }
          pref2[n] += tetap1[i-1];
          pref2[n-(temp % bagi)] += -1 * tetap1[i-1];
          
          if(bagi != INT_MAX){
            pref2[n] += bagi*tetap1[i-1];
            pref2[1] += -1*bagi*tetap1[i-1];
            
            pref[1] += bagi * tetap1[1];
            pref[n] += -1 * bagi * tetap1[i-1];
          }
        }

      }else{
        cout << i << " " << endl;
        pref[i] = d*tetap1[i-1];
        pref[i+d] = -1 * d * tetap1[i-1];
      }
    }

    vector<ll> dif1(n+2,0);
    vector<ll> dif2(n+2,0);
    for (int i = 1; i <= n; i++)
    {
      dif1[i] += pref[i-1] + dif1[i-1];
    }

    for (int i = n; i >= 0; i--)
    {
      dif2[i] += pref2[i+1] + dif2[i+1];
    }
    for(auto x : dif1){
      cout << x << " ";
    }
    cout << endl;
    for(auto x : dif2){
      cout << x << " ";
    }
    cout << endl << endl;

    vector<ll> simpan = dif2;
    for (int i = 0; i <= n; i++)
    {
      tetap1[i] = dif1[i];
    }
    uhuy = dif2;
    dif1.clear();
    dif1.resize(n+2, 0);
    dif2.clear();
    dif2.resize(n+2, 0);

    pref.clear();
    pref.resize(n+2, 0);
    pref2.clear();
    pref2.resize(n+2, 0);
    
    for (ll i = n; i > 0; i--)
    {
      if(tetap2[i+1] <= 0){
        continue;
      }
      int temp = d - (n - i);
      if(temp > 0){
        int bagi = temp/(n-1);
        if(bagi%2==0){
          pref[1] += tetap2[i+1];
          pref[temp - (temp * (n-1))] += -1 * tetap2[i+1];   
          
          pref2[n] += bagi*tetap2[i+1];
          pref2[1] += -1*bagi*tetap2[i+1];
          
          pref[1] += bagi * tetap2[1];
          pref[n] += -1 * bagi * tetap2[i+1];
        }else{
          if(bagi == 0){
            bagi = INT_MAX;
          }
          pref2[n] += tetap2[i+1];
          pref2[n-(temp % bagi)] += -1 * tetap2[i+1];
          
          if(bagi != INT_MAX){
            pref2[n] += bagi*tetap2[i+1];
            pref2[1] += -1*bagi*tetap2[i+1];
            
            pref[1] += bagi * tetap2[1];
            pref[n] += -1 * bagi * tetap2[i+1];
          }
        }

      }else{
        pref2[i] = d*tetap2[i+1];
        pref2[i-d] = -1 * d * tetap2[i+1];
      }
    }

    for (int i = 1; i <= n; i++)
    {
      dif1[i] += pref[i-1] + dif1[i-1];
    }
    tetap2 = uhuy;

    for (int i = n; i >= 0; i--)
    {
      dif2[i] += pref2[i+1] + dif2[i+1];
    }

    for (int i = 0; i <= n; i++)
    {
      tetap1[i] += dif1[i];
      tetap2[i] += dif2[i];
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans += ((tetap1[i] % MOD) * (i % MOD)) % MOD;
    ans += ((tetap2[i] % MOD) * (i % MOD)) % MOD;
  }
  cout << ans << endl;
}