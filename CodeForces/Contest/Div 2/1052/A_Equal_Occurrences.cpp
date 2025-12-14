#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    int ans = 0;
    for (int k = 1; k <= n; k++)
    {
      vector<int> cache(n+1, 0);
      int temp = 0;
      for (int i = 0; i < n; i++)
      {
        cache[a[i]]++;
        if(k == cache[a[i]]){
          temp+=k;
        }
      }
      ans = max(temp, ans);
    }
    cout << ans << endl;
  }
  
}
