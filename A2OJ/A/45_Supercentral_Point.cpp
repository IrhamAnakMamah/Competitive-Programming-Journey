/*
Author : Irham
Date : 19 October 2024
Problem : Supercentral Point
*/
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define sec second
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,ans = 0;
  cin >> n;
  vector<pair<int,int>> a(n);
  for(int i = 0; i<n ; i++){
    int x,y;
    cin >> x >> y;
    a[i] = {x,y};
  }

  for (int i = 0; i < n; i++)
  {
    bool kanan = 0;
    bool kiri = 0;
    bool atas = 0;
    bool bawah = 0;
    for (int j = 0; j < n; j++)
    {
      if(i==j) continue;
      if((a[i].fi == a[j].fi && a[i].sec > a[j].sec) && !bawah){
        bawah = 1;
      }
      if((a[i].fi == a[j].fi && a[i].sec < a[j].sec) && !atas){
        atas = 1;
      }
      if((a[i].sec == a[j].sec && a[i].fi < a[j].fi) && !kanan){
        kanan = 1;
      }
      if((a[i].sec == a[j].sec && a[i].fi > a[j].fi) && !kiri){
        kiri = 1;
      }
    }
    if(kanan+kiri+bawah+atas == 4){
      ans++;
    }
  }
  cout << ans << "\n";
}