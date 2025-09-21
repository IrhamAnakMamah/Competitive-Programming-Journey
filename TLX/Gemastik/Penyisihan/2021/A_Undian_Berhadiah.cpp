#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;

  int a[n];
  int mn = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    mn = min(mn, abs(k-a[i]));
  }
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if(mn == abs(k-a[i])){
      ans.push_back(a[i]);
    }
  }
  sort(ans.begin(), ans.end());
  for(auto x : ans){
    cout << setfill('0') << setw(5) << x << endl;
  }
  
}