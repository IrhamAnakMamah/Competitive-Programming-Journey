#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n,m;
  cin >> n >> m;

  vector<pair<int,ll>> a(m);

  for (int i = 0; i < m; i++)
  {
    cin >> a[i].first;
  }
  for (int i = 0; i < m; i++)
  {
    cin >> a[i].second;
  }

  sort(a.begin(),a.end());

  ll sum = 0, idx = 0;
  bool ok = 1;
  for (int i = 0; i < m; i++)
  {
    if(sum<a[i].first-1){
      ok = 0;
    }
    sum+=a[i].second;
    idx += a[i].first * a[i].second;
  }
  
  if(sum!=n || !ok){
    cout << -1 << endl;
  }else{
    cout << (n*(n+1))/2 - idx << "\n";
  }
  
}