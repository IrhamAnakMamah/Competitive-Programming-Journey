#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  if(n == 1){
    cout << -1 << endl;
    return;
  }

  int sum = 0;
  vector<int> ans;
  vector<int> temp;
  int j = 0;
  while (ans.size() != n)
  {
    vector<int> res;
    if(j > 0){
      for(auto x : temp){
        int temp = sum + x;
        int s = floor(sqrt(temp));
        if(s * s != temp){
          ans.push_back(x);
          sum += x;
        }else{
          res.push_back(x);
        }
      }
    }else{
      for (int i = 1; i <= n; i++)
      {
        int temp = sum + i;
        int s = floor(sqrt(temp));
        if(s * s != temp){
          ans.push_back(i);
          sum += i;
        }else{
          res.push_back(i);
        }
      }
    }
    temp = res;
    j++;
  }

  for(auto x : ans){
    cout << x << " ";
  }
  cout << endl;
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
  
  return 0;
}
