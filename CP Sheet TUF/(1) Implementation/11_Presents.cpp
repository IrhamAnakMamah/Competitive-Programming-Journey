#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,a;
  int ans[101];
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a;
    ans[a] = i;
  }
  for (int i = 1; i <= n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << "\n";
}