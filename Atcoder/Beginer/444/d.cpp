#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e7 + 5;

void solve(){
  int n;
  cin >> n;

  vector<int> diff(MAXN, 0);
  vector<int> pref(MAXN, 0);
  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    diff[a]--;
    diff[0]++;
    mx = max(mx, a);
  }

  for (int i = 1; i < MAXN; i++)
  {
    pref[i] = pref[i-1] + diff[i-1];
  }

  vector<int> ans(MAXN, 0);
  int cnt = 0;
  for (int i = 1; i <= MAXN; i++)
  {
    if(pref[i] == 0 && cnt == 0){
      mx = i;
      break;
    }
    ans[i] = (pref[i] + cnt)%10;
    cnt = ((pref[i] + cnt)/10);
  }
  
  for (int i = mx-1; i > 0; i--)
  {
    cout << ans[i] << "";
  }
  cout << endl;
  
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
  
}