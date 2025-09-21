#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    vector<ll> a;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      ll c;
      cin >> c;
      if(c&1){
        a.push_back(c);
      }else{
        sum+=c;
      }
    }
    
    ll ans = 0;
    sort(a.begin(), a.end());
    if(a.size() > 0){
      ans = sum+a[a.size()-1];
      int temp = (a.size() - 1)/2;
      for (int i = a.size() - 2, j = 0; j < temp ; i--, j++)
      {
        ans += a[i];
      }
    }
    cout << ans << endl;
  }
  
}