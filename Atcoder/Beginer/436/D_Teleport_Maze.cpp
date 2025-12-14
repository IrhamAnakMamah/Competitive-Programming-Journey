#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;

  vector<string> s(n);
  vector<vector<pair<int, int>>> warps(26);

  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (islower(s[i][j])) {
        warps[s[i][j] - 'a'].push_back({i, j});
      }
    }
  }

  vector<vector<int>> dp(n, vector<int>(m, -1));
  queue<pair<int, int>> q;

  dp[0][0] = 0;
  q.push({0, 0});
  vector<bool> vis(26, false);
  
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (x == n - 1 && y == m - 1) {
      cout << dp[x][y] << endl;
      return 0;
    }

    int current_dp = dp[x][y];

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (s[nx][ny] != '#' && dp[nx][ny] == -1) {
          dp[nx][ny] = current_dp + 1;
          q.push({nx, ny});
        }
      }
    }

    if (islower(s[x][y])) {
      int char_idx = s[x][y] - 'a';
      if (!vis[char_idx]) {
        for (auto p : warps[char_idx]) {
          int wx = p.first;
          int wy = p.second;
          if (dp[wx][wy] == -1) {
            dp[wx][wy] = current_dp + 1;
            q.push({wx, wy});
          }
        }
        vis[char_idx] = true;
      }
    }
  }
    
  cout << -1 << endl;

  return 0;
}