#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<int,int> ans;
int n;
int k[21];

void f(int groupA, int groupB, int i){
  if(i == n){
    if(ans.first == -1){
      ans = {abs(groupA - groupB), max(groupA, groupB)};
    }else if(ans.first > abs(groupA - groupB)){
      ans = {abs(groupA - groupB), max(groupA, groupB)};
    }else if(ans.first == abs(groupA - groupB)){
      ans = {ans.first, min(ans.second, max(groupA, groupB))};
    }
    return;
  }

  // tambah di groupA
  groupA += k[i];
  f(groupA, groupB, i + 1);
  groupA -= k[i];
  
  groupB += k[i];
  f(groupA, groupB, i + 1);
  groupB -= k[i];
}

void solve(){
  ans = {-1,-1};
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> k[i];
  }
  
  f(0,0,0);
  cout << ans.second << endl;
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
  
  return 0;
}
