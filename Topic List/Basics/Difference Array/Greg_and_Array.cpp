#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  ll b[m][3];
  for (int i = 0; i < m; i++)
  {
    cin >> b[i][0] >> b[i][1] >> b[i][2];
  }
  
  vector<ll> cal(n+1,0);
  vector<int> pref(m+1,0);
  for (int i = 0; i < k; i++)
  {
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    pref[x]++;
    pref[y+1]--;
  }

  for (int i = 1; i <= m; i++)
  {
    pref[i]+=pref[i-1];
  }


  for (int i = 0; i < m; i++)
  {
    cal[b[i][0]-1]+=b[i][2]*pref[i];
    cal[b[i][1]]-=b[i][2]*pref[i];
  }

  for (int i = 1; i <= n; i++)
  {
    cal[i] += cal[i-1];
  }
  
  for (int i = 0; i < n; i++)
  {
    // cout << cal[i] << endl;
    a[i] += cal[i];
    cout << a[i] << " ";
  }
  
}