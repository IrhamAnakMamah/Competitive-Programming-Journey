#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, k;
  cin >> n >> k;

  vector<string> s(k);
  for (int i = 0; i < k; i++)
  {
    cin >> s[i];
  }

  vector<int> col(n, 0);
  for (int j = 0; j < n; j++)
  {
    for (int i = 0; i < k; i++)
    {
      col[j] |= (1 << (s[i][j] - 'a'));
    }
  }

  vector<int> div;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0) {
      div.push_back(i);
      if (i * i != n) div.push_back(n / i);
    }
  }
  sort(div.begin(), div.end());
  for (int d : div)
  {
    string t = "";
    bool ok = true;
    for (int i = 0; i < d; i++)
    {
      int sama = (1 << 26) - 1; 

      for (int j = i; j < n; j += d)
      {
        sama &= col[j];
      }

      if (sama == 0) {
        ok = false;
        break;
      }
      int idx = __builtin_ctz(sama); 
      t += (char)('a' + idx);
    }

    if (ok) {
      for (int i = 0; i < n / d; i++)
      {
        cout << t;
      }
      cout << endl;
      return;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
}