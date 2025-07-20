#include <bits/stdc++.h>
using namespace std;

int main (){
  vector<pair<int,int>> a;
  int x,y;
  for (int i = 0; i < 2; i++)
  {
    cin >> x >> y;
    a.push_back({x,y});
  }

  if((a[0].first == a[1].first && a[0].second != a[1].second)){
    cout << a[0].first + abs(a[0].second - a[1].second) << " " << a[0].second << " " << a[0].first + abs(a[0].second - a[1].second) << " " << a[1].second;
  }else if((a[0].first != a[1].first && a[0].second == a[1].second)){
    cout << a[0].first << " " << a[0].second + abs(a[0].first - a[1].first) << " " << a[1].first << " " << a[0].second + abs(a[0].first - a[1].first);
  }else if(abs(a[0].first - a[1].first)==abs(a[0].second - a[1].second)){
    cout << a[0].first << " " << a[1].second << " " << a[1].first << " " << a[0].second;
  }else{
    cout << -1 << "\n";
  }
}