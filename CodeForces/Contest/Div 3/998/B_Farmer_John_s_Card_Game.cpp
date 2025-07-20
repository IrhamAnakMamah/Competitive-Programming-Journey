#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> cow;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int x;
        cin >> x;
        cow.push_back({x,i+1});
      }
    }
    sort(cow.begin(),cow.end());
    int urut[n];
    for (int i = 0; i < n; i++)
    {
      urut[i] = cow[i].second;
    }

    // for (int i = 0; i < n*m; i++)
    // {
    //   auto[x,y] = cow[i];
    //   cout << x << " " << y << endl;
    // }
    // cout << endl;
    
    bool ok = 1;
    int i = 0;
    int k = 0;
    int count = 0;
    while (i<n*m)
    {
      auto[x,y] = cow[i];
      if(x==count && y==urut[k]){
        count++;
        k++;
        i++;
        if(k==n){
          k = 0;
        }
      }else{
        ok = 0;
        break;
      }
    }
    
    if(!ok){
      cout << -1 << endl;
    }else{
      for (int i = 0; i < n; i++)
      {
        cout << urut[i] << " ";
      }
      cout << endl;
    }
  }
  
}