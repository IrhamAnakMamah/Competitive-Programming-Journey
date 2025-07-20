#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  sort(a,a+n);
  int mx = 0;

  int ans1 = 0;
  for (int i = 0; i < n-1; i++)
  {
    ans1 = max(ans1, abs(a[i]-a[i+1]));
  }
  
  int ans2 = abs(a[0]-a[n-1]);
  cout << ans1 << endl;
  cout << ans2 << endl;
}