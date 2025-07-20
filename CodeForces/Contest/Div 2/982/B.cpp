#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      int res = 0;
      for (int j = 0; j < n; j++)
      {
        if(j<i || a[j]>a[i]){
          res++;
        }
      }
      ans = min(res,ans);
    }
    cout << ans << '\n';
  }
  
}