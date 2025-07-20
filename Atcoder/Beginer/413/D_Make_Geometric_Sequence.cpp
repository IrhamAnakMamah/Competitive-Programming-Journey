#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool op(const ll &a, const ll &b){
  return abs(a) < abs(b);
}

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    bool ok = 1;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
      ll x;
      cin >> x;
      a[i] = x;
    }
    sort(a,a+n, op);
    for (int i = 1; i < n; i++)
    {
      if(abs(a[i]) != abs(a[i-1])){
        ok = 0;
      }
    }
    if(ok){
      int count = 0;
      for (int i = 0; i < n; i++)
      {
        count += (a[i] > 0);
      }
      if(count == n || count == 0 || abs(count - (n - count)) <= 1){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }else{
      ok = 1;
      for (int i = 0; i+2 < n; i++)
      {
        if(a[i] * a[i+2] != a[i+1] * a[i+1]){
          ok = 0;
        }
      }
      cout << (ok ? "Yes" : "No") << endl;
    }
  }
  
}