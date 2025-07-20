#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for(auto &x : a){
      cin >> x;
      ans+=x;
    }
    cout << ans - 2* a[n-2] << "\n";
  }
  
}