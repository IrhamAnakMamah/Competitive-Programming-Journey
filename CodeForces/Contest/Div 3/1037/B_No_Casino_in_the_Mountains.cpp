#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
  
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    vector<int> pref(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
      pref[i] = pref[i-1] + a[i-1];
    }
    
    int ans = 0;
    int j = 0;
    while (j < n)
    {
      if(a[j] == 1 || j+k > n){
        j++;
      }else if(pref[j+k] - pref[j] > 0){
        j++;
      }else{
        j+=k+1;
        ans++;
      }
    }
    cout << ans << endl;
  }
  
}