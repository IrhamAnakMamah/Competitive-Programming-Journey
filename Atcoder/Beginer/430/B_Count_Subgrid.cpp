#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++)
    cin >> grid[i];

  set<string> patterns;

  for (int i = 0; i + m <= n; i++)
  {
    for (int j = 0; j + m <= n; j++)
    {
      string pattern = "";
      for (int x = 0; x < m; x++)
      {
        for (int y = 0; y < m; y++)
        {
          pattern += grid[i + x][j + y];
        }
      }
      patterns.insert(pattern);
    }
  }

  cout << patterns.size() << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
}