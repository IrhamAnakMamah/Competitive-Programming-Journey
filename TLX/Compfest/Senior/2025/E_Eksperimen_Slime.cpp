#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n,d,k;
  cin >> n >> d >> k;
  
  vector<ll> maju(n+2, 0);
  vector<ll> mundur(n+2, 0);

  maju[1] = 1;
  for (int xx = 0; xx < k; xx++)
  {
    vector<ll> pref1(n+2, 0);
    vector<ll> pref2(n+2, 0);
    // benerin yang maju
    for (int i = 1; i <= n+1; i++)
    {
      if(maju[i-1] <= 0){
        continue;
      }
      ll temp = (maju[i-1] * d) + i - 1;
      if(temp > n){
        pref1[i-1] += maju[i-1];
        pref1[n] -= maju[i-1];
        temp-=(n-i+2);
        int bagi = temp/(n-1);
        if(bagi&1){
          ll sum = temp - (bagi * (n-1));
          pref1[0] += maju[i-1];
          pref1[sum] -= maju[i-1];

          pref2[n] += (maju[i-1]) * (bagi+1);
          pref2[1] -= (maju[i-1]) * (bagi+1);

          pref1[0] += (maju[i-1]) * (bagi-1);
          pref1[n] -= (maju[i-1]) * (bagi-1);
        }else{
          ll sum = temp - (bagi * (n-1));
          pref2[n] += (maju[i-1]);
          pref2[(n-sum-1)] -= (maju[i-1]);

          if(bagi > 1){
            pref2[n] += (maju[i-1]) * (bagi-1);
            pref2[1] -= (maju[i-1]) * (bagi-1);
  
            pref1[0] += (maju[i-1]) * (bagi-1);
            pref1[n] -= (maju[i-1]) * (bagi-1);
          }
        }
      }else{
        pref1[i-1] += maju[i-1];
        pref1[i+d-1] -= maju[i-1];
      }
    }
    
    vector<ll> dif1 (n+2, 0);
    vector<ll> dif2 (n+2, 0);

    for (int i = 1; i <= n+1; i++)
    {
      dif1[i] += pref1[i-1] + dif1[i-1];
    }
    
    for (int i = n; i >= 0; i--)
    {
      dif2[i-1] += pref2[i] + dif2[i];
    }

    pref1.clear();
    pref1.resize(n+2,0);
    pref2.clear();
    pref2.resize(n+2,0);

    for(auto x : dif1){
      cout << x << " ";
    }
    cout << endl;
    for(auto x : dif2){
      cout << x << " ";
    }
    cout << endl;

    for (int i = n-1; i >= 0; i--)
    {
      if(mundur[i+1] <= 0){
        continue;
      }
      ll temp = (mundur[i+1] * d) + i - 1;
      if(temp > n){
        pref1[i+1] += mundur[i+1];
        pref1[0] -= mundur[i+1];
        temp-=(n-i+2);
        int bagi = temp/(n-1);
        if(bagi%2==0){
          ll sum = temp - (bagi * (n-1));
          pref1[0] += mundur[i+1];
          pref1[sum] -= mundur[i+1];

          if(bagi > 1){
            pref2[n] += (mundur[i+1]) * (bagi-1);
            pref2[0] -= (mundur[i+1]) * (bagi-1);
  
            pref1[0] += (mundur[i+1]) * (bagi-1);
            pref1[n] -= (mundur[i+1]) * (bagi-1);
          }
        }else{
          ll sum = temp - (bagi * (n-1));
          pref2[n] += (mundur[i+1]);
          pref2[(n-sum-1)] -= (mundur[i+1]);

            pref2[n] += (mundur[i+1]) * (bagi-1);
            pref2[0] -= (mundur[i+1]) * (bagi-1);
  
            pref1[0] += (mundur[i+1]) * (bagi);
            pref1[n] -= (mundur[i+1]) * (bagi);
        }
      }else{
        pref1[i+1] += mundur[i+1];
        pref1[i-d] -= mundur[i+1];
      }
    }

    vector<ll> dif3 (n+2,0);
    vector<ll> dif4 (n+2,0);

    
    for (int i = 1; i <= n+1; i++)
    {
      dif3[i] += pref1[i-1] + dif3[i-1];
    }
    
    for (int i = n; i >= 0; i--)
    {
      dif4[i-1] += pref2[i] + dif4[i];
    }

    for (int i = 1; i <= n; i++)
    {
      dif1[i] += dif3[i];
      dif2[i] += dif4[i];
    }

    maju = dif1;
    mundur = dif2;
  }

    // for(auto x : maju){
    //   cout << x << " ";
    // }
    // cout << endl;
    // for(auto x : mundur){
    //   cout << x << " ";
    // }
    // cout << endl;
}