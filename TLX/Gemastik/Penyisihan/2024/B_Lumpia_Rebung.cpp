#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n,k;
  cin >> n >> k;

  vector<ll> ans;
  ans.push_back(k);
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    ans[a-1] = ans[a-1]/2;
    ans.insert(ans.begin()+a, ans[a-1]);
  }
  
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}