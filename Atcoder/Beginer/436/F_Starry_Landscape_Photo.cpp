#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct FenwickTree
{
  int size;
  vector<int> tree;

  FenwickTree(int n)
  {
    size = n;
    tree.assign(n + 1, 0);
  }

  void add(int index, int value)
  {
    while (index <= size)
    {
      tree[index] += value;
      index += index & (-index);
    }
  }

  int query(int index)
  {
    int sum = 0;
    while (index > 0)
    {
      sum += tree[index];
      index -= index & (-index);
    }
    return sum;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<int> B(N);
  for (int i = 0; i < N; i++)
  {
    cin >> B[i];
  }

  vector<ll> countL(N), countR(N);
  FenwickTree bitL(N);
  for (int i = 0; i < N; i++)
  {
    countL[i] = bitL.query(B[i]) + 1;
    bitL.add(B[i], 1);
  }
  FenwickTree bitR(N);
  for (int i = N - 1; i >= 0; i--)
  {
    countR[i] = bitR.query(B[i]) + 1;
    bitR.add(B[i], 1);
  }

  ll ans = 0;
  for (int i = 0; i < N; i++)
  {
    ans += (countL[i] * countR[i]);
  }

  cout << ans << endl;

  return 0;
}