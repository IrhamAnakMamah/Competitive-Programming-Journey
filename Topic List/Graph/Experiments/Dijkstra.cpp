#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
  int to;
  int value;
};

const int INF = 1e9;
vector<vector<Node>> adj;

void dijkstra(int s, vector<int> &d, vector<int> &p)
{
  int n = adj.size();
  d.assign(n, INF);
  p.assign(n, -1);

  d[s] = 0;
  using pii = pair<int, int>;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  while (!q.empty())
  {
    int v = q.top().second;
    int d_v = q.top().first;
    q.pop();
    if (d_v != d[v])
      continue;

    for (auto edge : adj[v])
    {
      int to = edge.to;
      int len = edge.value;

      if (d[v] + len < d[to])
      {
        d[to] = d[v] + len;
        p[to] = v;
        q.push({d[to], to});
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> d;
  vector<int> p;
  adj.resize(n + 1);

  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  // from 1
  dijkstra(1, d, p);
  cout << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << "d[" << i << "] : " << d[i] << endl;
  }
  
}