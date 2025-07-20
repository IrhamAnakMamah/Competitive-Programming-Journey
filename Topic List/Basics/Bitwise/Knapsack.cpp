#include <bits/stdc++.h>
using namespace std;
  
int n,k;
vector<pair<int, int>> a(21);

int f(int jumlah,int i, int bobot){
  if(i==n){
    if(bobot<=k){
      return jumlah;
    }else{
      return 0;
    }
  }

  int pick = f(jumlah+a[i].second,i+1,bobot+a[i].first);
  int notpick = f(jumlah,i+1,bobot);

  return max(pick,notpick);
}

int main(){
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    int x,y;
    cin >> x >> y;
    a[i] = {x,y};
  }
  
  int ans = f(0,0,0);
  cout << ans << '\n';
}