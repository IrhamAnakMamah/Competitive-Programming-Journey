#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  vector<vector<char>> block(n+1, vector<char>(n+1));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> block[i][j];
    }
    
  }
  
  for (int i = 1; i <= (n/2); i++)
  {
    int bawah = i;
    int atas = n + 1 - i;
    vector<vector<char>> temp(n+1, vector<char>(n+1));
    temp = block;
    for (int x = bawah; x <= atas; x++)
    {
      for (int y = bawah; y <= atas; y++)
      {
        temp[y][n + 1 - x] = block[x][y];
      }
    }
    block = temp;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << block[i][j];
    }
    cout << endl;
  }
  
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;

  while (t--)
  {
    solve();
  }
  
  return 0;
}