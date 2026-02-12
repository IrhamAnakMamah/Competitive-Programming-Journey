#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  /*
  
  n = 5
  1. (0, 0) - (1, 5)
  2. (0, 1) - (2, 5)
  3. (0, 2) - (3, 5)
  */
  bool ok = 1;
  for (int i = 0; i < n-1; i++)
  {
    int temp1 = 0;
    int temp2 = 0;
    int key = 0;
    for (int j = 0; j <= i; j++)
    {
      if(key == a[j]) key++;
    }
    temp1 = key;
    key = 0;
    for (int j = i+1; j < n; j++)
    {
      if(key == a[j]) key++;
    }
    temp2 = key;
    if(temp1 == temp2) ok = 0;
  }
  cout << (ok ? "YES" : "NO") << endl;
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while (t--)
  {
    solve();
  }
  
  return 0;
}