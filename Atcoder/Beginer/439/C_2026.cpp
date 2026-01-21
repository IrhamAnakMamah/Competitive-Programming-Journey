#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n;
  cin >> n;

  vector<ll> a;
  bool ok = 1;
  int i = 2;
  while (true)
  {
    for (int j = 1; j < i; j++)
    {
      int temp = (i * i) + (j * j);
      if(temp > n){
        if(j == 1){
          ok = 0;
          break;
        }else{
          break;
        }
      }else{
        a.push_back(temp);
      }
    }
    
    if(!ok) break;
    i++;
  }
  
  bool sama = 0;
  ll temp = 0;
  sort(a.begin(), a.end());
  vector<ll> ans;
  for (int i = 0; i < a.size(); i++)
  { 
    if(sama){
      if(temp == a[i]){
        continue;
      }else{
        sama = 0;
      }
    }
    
    if(i < (int)a.size() - 1){
      if(a[i] == a[i+1]){
        temp = a[i];
        sama = 1;
      }else{
        ans.push_back(a[i]);
      }
    }else{
      ans.push_back(a[i]);
    }
  }
  cout << ans.size() << endl;
  for(auto x : ans){
    cout << x << " ";
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
  

  return 0;
}

