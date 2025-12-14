#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<pair<int,int>> a,b,c;
    
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      a.push_back({x,i});
    }
    
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      b.push_back({x,i});
    }
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      c.push_back({x,i});
    }

    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    sort(c.begin(), c.end(), greater<>());

    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
      auto [x1, y1] = a[i];
      int temp = x1;
      for (int j = 0; j < 3; j++)
      {
        auto [x2, y2] = b[j];
        if(y2 != y1){
          temp += x2;
        }

        for (int k = 0; k < 3; k++)
        {
          auto[x3, y3] = c[k];
          if(y3 != y1 && y2 != y3){
            temp += x3;
            ans = max(ans, temp);
            temp -= x3;
          }
        }

        if(y2!=y1){
          temp -= x2;
        }
      }
      
    }
    cout << ans << endl;
    
  }
  
}