#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;

  vector<int> a(k+1, 0);
  for (int i = 0; i < n; i++)
  {
    int c;
    cin >> c;
    for (int j = 0; j < c; j++)
    {
      int x;
      cin >> x;
      a[x]++;
    }
    
  }

  sort(a.begin(), a.end(), greater<>());
  
  int ans = 1;
  int mx = a[0];
  for (int i = 1; i <= k; i++)
  {
    if(mx == a[i]){
      ans++;
    }
  }
  cout << ans << endl;
  
}