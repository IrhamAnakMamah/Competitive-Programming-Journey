#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n;
  cin >> n;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  bool ok = 1;
  ll ans = 0;
  ll temp = 0;
  ll jumlah = 0;
  for (int i = 1; i < n; i++)
  {
    if(i == 1){
      temp = a[i] - a[i-1];
      jumlah++;
    }else{
      if(temp != a[i] - a[i-1]){
        jumlah = 1;
        temp = a[i] - a[i-1];
      }else{
        jumlah++;
      }
    }
    ans+=jumlah;
  }
  cout << ans + n << endl;
}