#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
bool is_target[MAXN];
int N, K;
int ans = 0;

bool dfs(int u, int p)
{
  bool has_target = is_target[u];

  for (int v : adj[u])
  {
    if (v == p)
      continue;

    if (dfs(v, u))
    {
      has_target = true;
    }
  }

  if (has_target)
  {
    ans++;
  }

  return has_target;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;

  int first_target = -1;

  for (int i = 0; i < N - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < K; i++)
  {
    int v;
    cin >> v;
    is_target[v] = true;
    if (i == 0)
      first_target = v;
  }
  dfs(first_target, -1);

  cout << ans << endl;

  return 0;
}