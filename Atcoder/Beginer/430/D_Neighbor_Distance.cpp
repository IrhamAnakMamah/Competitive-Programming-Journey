#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
    return 0;
  vector<ll> X(N);
  for (int i = 0; i < N; ++i)
    cin >> X[i];

  set<ll> pos;
  map<ll, ll> dist;
  multiset<ll> ms;  
  ll total = 0;

  pos.insert(0);
  dist[0] = 0; 
  ms.insert(0);
  total = 0;

  for (int i = 0; i < N; ++i)
  {
    ll x = X[i];
    pos.insert(x);

    auto it = pos.find(x);
    ll left = -1, right = -1;
    if (it != pos.begin())
      left = *prev(it);
    if (next(it) != pos.end())
      right = *next(it);

    ll INF = (1LL << 60);
    ll d_new = INF;
    if (left != -1)
      d_new = min(d_new, x - left);
    if (right != -1)
      d_new = min(d_new, right - x);
    if (d_new == INF)
      d_new = 0;

    dist[x] = d_new;
    ms.insert(d_new);
    total += d_new;

    if (left != -1)
    {
      ll old = dist[left];
      auto itms = ms.find(old);
      if (itms != ms.end())
      {
        ms.erase(itms);
        total -= old;
      }
      ll newd = INF;
      auto itl = pos.find(left);
      if (itl != pos.begin())
      {
        ll leftleft = *prev(itl);
        newd = min(newd, left - leftleft);
      }
      newd = min(newd, x - left);
      if (newd == INF)
        newd = 0;
      dist[left] = newd;
      ms.insert(newd);
      total += newd;
    }

    if (right != -1)
    {
      ll old = dist[right];
      auto itms = ms.find(old);
      if (itms != ms.end())
      {
        ms.erase(itms);
        total -= old;
      }
      ll newd = INF;
      auto itr = pos.find(right);
      if (next(itr) != pos.end())
      {
        ll rightright = *next(itr);
        newd = min(newd, rightright - right);
      }
      newd = min(newd, right - x);
      if (newd == INF)
        newd = 0;
      dist[right] = newd;
      ms.insert(newd);
      total += newd;
    }

    cout << total << '\n';
  }

  return 0;
}
