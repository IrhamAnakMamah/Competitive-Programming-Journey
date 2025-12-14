#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  int ans1 = 0;
  int ans2 = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i+1; j < n; j++)
    {
      for (int k = j+1; k < n; k++)
      {
        int mx = max({a[i], a[j], a[k]});
        int mn = min({a[i], a[j], a[k]});

        if(mx - mn <= m){
          ans1++;
          ans2 = max(ans2, a[i] + a[j] + a[k]);
        }
      }
      
    }
    
  }
  
  if(ans1 == 0){
    cout << -1 << endl;
  }else{
    cout << ans1 << " " << ans2 << endl;
  }
}