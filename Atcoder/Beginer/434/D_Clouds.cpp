#include <bits/stdc++.h>
using namespace std;

const int MAX = 2005;
int grid[MAX][MAX];
int ones[MAX][MAX];
struct cloud {
    int u, d, l, r;
};

int main() {
  int n;
  cin >> n;

  vector<cloud> clouds(n);
  for (int i = 0; i < n; i++) {
    cin >> clouds[i].u >> clouds[i].d >> clouds[i].l >> clouds[i].r;
    grid[clouds[i].u][clouds[i].l]++;
    grid[clouds[i].d + 1][clouds[i].l]--;
    grid[clouds[i].u][clouds[i].r + 1]--;
    grid[clouds[i].d + 1][clouds[i].r + 1]++;
  }

  for (int i = 1; i <= 2000; i++) {
    for (int j = 1; j <= 2000; j++) {
      grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
    }
  }
  int base_empty = 0;
    
  for (int i = 1; i <= 2000; i++) {
    for (int j = 1; j <= 2000; j++) {
      if (grid[i][j] == 0) {
        base_empty++;
      }
      int is_unique = (grid[i][j] == 1 ? 1 : 0);
      ones[i][j] = is_unique + ones[i-1][j] + ones[i][j-1] - ones[i-1][j-1];
    }
  }
  
  for (int i = 0; i < n; i++) {
    int u = clouds[i].u;
    int d = clouds[i].d;
    int l = clouds[i].l;
    int r = clouds[i].r;
    int count_unique = ones[d][r] - ones[u-1][r] - ones[d][l-1] + ones[u-1][l-1];
    cout << base_empty + count_unique << "\n";
  }
}