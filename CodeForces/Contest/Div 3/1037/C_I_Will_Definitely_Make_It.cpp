#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;

    int a[n];
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if(k-1 == i){
        idx = a[i];
      }
    }
    sort(a,a+n);
    for (int i = 0; i < n; i++)
    {
      if(idx == a[i]){
        idx = i;
        break;
      }
    }
    
    bool ok = 1;
    int cek = 0;
    int air = 0;
    for (int i = idx; i < n-1; i++)
    {
      if(a[i] == a[i+1]){
        continue;
      }
      if(abs(a[i] - a[i+1]) + air > a[i]){
        ok = 0;
      }else{
        air+=abs(a[i] - a[i+1]);
      }
    }
    if(cek == a[n-1]){
      ok = 1;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  
}