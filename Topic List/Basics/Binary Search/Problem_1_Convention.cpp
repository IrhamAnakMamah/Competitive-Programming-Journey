#include <bits/stdc++.h>
using namespace std;

int main(){
  
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);

  int n,k,q;
  cin >> n >> k >> q;

  vector<int> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  sort(a.begin(), a.end());

  int l = 0;
  int r = a[n-1] - a[0];

  auto cek = [&] (int x){
    int mobil = 1;
    int kapasitas = 0;
    int sapi = a[0];

    for (int i = 0; i < n; i++)
    {
      kapasitas++;
      if(a[i] - sapi > x || kapasitas > q){
        mobil++;
        kapasitas = 1;
        sapi = a[i];
      }
    }
    
    return mobil <= k;
  };
  
  while (l<r)
  {
    int mid = (r+l)/2;
    if(cek(mid)){
      r = mid;
    }else{
      l = mid+1;
    }
  }
  cout << l << endl;
}