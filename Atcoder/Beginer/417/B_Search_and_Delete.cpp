#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  int a[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  vector<bool> vis(n+1, 0);
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;

    for (int j = 0; j < n && a[j] <= x; j++)
    {
      if(x == a[j] && !vis[j]){
        vis[j] = 1;
        break;
      }
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    if(!vis[i]){
      cout << a[i] << " ";
    }
  }
  cout << endl;

}