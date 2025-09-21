#include <bits/stdc++.h>
using namespace std;

int main(){
  int m,n;
  cin >> m >> n;

  vector<pair<int,int>> a;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.push_back({x,i});
  }
  
  sort(a.begin(), a.end());

  int ans[n];

  for (int i = 0; i < n; i++)
  {
    if(i == 0){
      auto[x,y] = a[i];
      int kanan = x;
      int kiri = 0;
      int j = j+1;
      while (j < n)
      {
        if(a[j].second < y){
          kiri = a[j].first - x;
          break;
        }
        j++;
      }
      ans[y] = max(kiri,kanan);
    }else{
      auto[x,y] = a[i];
      int kanan = 0;
      int kiri = 0;

      int j = i-1;
      while (j >= 0)
      {
        if(a[j].second > y){
          kiri = x - a[j].first;
          break;
        }
        j--;
      }
      j = i+1;
      while (j < n)
      {
        if(a[j].second > y){
          kanan = a[j].first - x;
          break;
        }
        j++;
      }
      if(kanan == 0){
        kanan = m - x;
      }
      ans[y] = max(kanan, kiri);
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << endl;
  }
  
  
}