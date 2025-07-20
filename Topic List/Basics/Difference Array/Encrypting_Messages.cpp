#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,c;
  cin >> n >> m >> c;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vector<int> ans(n+1,0);
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    ans[i] += x;
    ans[i+(n-m)+1] -=x;
  }
  a[0] = (a[0]+ans[0])%c;
  for (int i = 1; i < n; i++)
  {
    ans[i] += ans[i-1];
    a[i] = (a[i]+ans[i])%c;
  }
  
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}