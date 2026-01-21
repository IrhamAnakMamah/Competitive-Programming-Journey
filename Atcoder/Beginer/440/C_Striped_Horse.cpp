#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,w;
    cin >> n >> w;

    vector<pair<int,int>> a;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      a.push_back({(i+1) % (2 * w), x});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
      cout << a[i].first << " " << a[i].second << endl;
    }
    
    cout << endl;
  }
  
}