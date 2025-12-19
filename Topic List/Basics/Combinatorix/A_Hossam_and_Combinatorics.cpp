#include <bits./stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int a[n];
    int mx = 0;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      mx = max(a[i], mx);
      mn = min(a[i], mn);
    }
    
    ll sum = 0;
    ll cnt1 = 0;
    ll cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
      if(a[i] == mx || a[i] == mn){
        if(mx == mn){
          sum += 2 * cnt1;
          cnt1++;
        }else{
          if(a[i] == mx){
            sum += 2 * cnt2;
            cnt1++;
          }else{
            sum += 2 * cnt1;
            cnt2++;
          }
        }
      }
    }
    cout << sum << endl;
  }
  
}