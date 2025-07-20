#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int mx = -1;
  int mn = INT_MAX;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    mx = max(mx,a[i]);
    mn = min(mn,a[i]);
  }
  
  auto checker = [&] (){
    bool ok = 1;
    for (int i = 1; i < n; i++)
    {
      if(a[0] != a[i]){
        ok = 0;
      }
    }
    return ok;
  };

  if(checker()){
    cout << "SESUAI" << endl;
  }else{
    int x = -1;
    int y = -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum+=(a[i] - mn);

      if(a[i] == mx){
        x = i;
      }else if(a[i] == mn){
        y = i;
      }
    }

    if(sum%n==0){
      int ans = sum/n;
      a[x] -= ans;
      a[y] += ans;
      if(checker()){
        cout << ans << " " << x+1 << " " << y+1 << endl;
      }else{
        cout << "TIDAK SESUAI" << endl;
      }
    }else{
      cout << "TIDAK SESUAI" << endl;
    }
    
  }
}