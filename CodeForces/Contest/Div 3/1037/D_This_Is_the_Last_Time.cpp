#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;

    vector<tuple<int,int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
      int l,r,c;
      cin >> l >> r >> c;
      a[i] = {c,l,r};
    }
    
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
      auto [x,y,z] = a[i];
      if(y<=k && k<=z) k = max(k,x);
    }
    cout << k << endl;
  }
  
}