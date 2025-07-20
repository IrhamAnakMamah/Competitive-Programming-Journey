#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    // kalo totalnya ganjil, maka jerry kalah dan berlaku sebaliknya
    int n,k;
    bool ok = 0;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    sort(a,a+n, greater<>());
    bool found = 0;
    int mn = a[n-1];
    int mx = a[0];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum+=a[i];
      if(i>0 && mx==a[i]){
        found = 1;
      }
    }
    
    
    if((a[0]-1)-mn>k){
      ok = 0;
    }else if((mx-mn>k)&&found){
      ok = 0;
    }else{
      ok = (sum&1 ? 1 : 0);
    }
    
    cout << (ok ? "Tom" : "Jerry") << endl;
  }
  
}