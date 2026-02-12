#include <bits/stdc++.h>
using namespace std;

void solve()
{
  const int MAXN = (1 << 18) + 5;
  int tree[2 * MAXN];
  int n, q;
  int pw;
  cin >> n >> q;
  pw = 1 << n;

  for (int i = 0; i < pw; i++){
    cin >> tree[pw + i];
  }

  for (int i = pw - 1; i > 0; i--){
    tree[i] = tree[2 * i] ^ tree[2 * i + 1];
  }

  while (q--)
  {
    int idx, c;
    cin >> idx >> c;
    idx--;

    int curr = pw + idx;
    int current_skill = c;

    int ans = 0;
    int sz = 1;

    for (int i = 0; i < n; i++){
      int sibling;
      bool is_left_child = (curr % 2 == 0);

      if (is_left_child){
        sibling = curr + 1;
      }else{
        sibling = curr - 1;
      }

      int sibling_skill = tree[sibling];
      bool win = false;
      if (is_left_child){
        if (current_skill >= sibling_skill)
          win = true;
      }else{
        if (current_skill > sibling_skill)
          win = true;
      }

      if (win){
        current_skill = current_skill ^ sibling_skill;
      }
      else{
        ans += sz;
        current_skill = current_skill ^ sibling_skill;
      }
      curr /= 2;
      sz *= 2;
    }
    cout << ans << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
  {
    solve();
  }

  return 0;
}