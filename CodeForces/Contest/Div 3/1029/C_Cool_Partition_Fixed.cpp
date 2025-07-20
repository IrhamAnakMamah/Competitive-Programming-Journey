#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    set<int> x,y;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      x.insert(a[i]);
      y.insert(a[i]);
      if(x.size() == y.size()){
        ans++;
        y.clear();
      }
    }
    cout << ans << endl;
  }
  
}