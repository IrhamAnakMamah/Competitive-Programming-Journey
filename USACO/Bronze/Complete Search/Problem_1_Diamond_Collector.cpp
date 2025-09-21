#include <bits/stdc++.h>
using namespace std;

int main(){

  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a,a+n);
  
  int mn = a[0];
  int ans = 1;

  int i = 0;
  int j = 1;
  while (i < n && j < n)
  {
    if(a[j] - mn <= k){
      ans = max((j-i)+1, ans);
      j++;
    }else{
      i++;
      mn = a[i];
    }
  }
  cout << ans << endl;
  
}