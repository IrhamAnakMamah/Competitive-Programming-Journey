#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n,target;
  cin >> n >> target;

  vector<pair<ll,int>> a(n);
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    a[i] = {x,i+1};
  }
  
  sort(a.begin(), a.end());
  int awal = -1;
  int akhir = -1;

  int i = 0;
  int j = n-1;
  while(i<j){
    if(a[i].first + a[j].first == target){
      awal = a[i].second;
      akhir = a[j].second;
      break;
    }else if(a[i].first + a[j].first < target){
      i++;
    }else{
      j--;
    }
  }
  if(awal == -1){
    cout << "IMPOSSIBLE" << endl;
  }else{
    cout << awal << " " << akhir << endl;
  }
}