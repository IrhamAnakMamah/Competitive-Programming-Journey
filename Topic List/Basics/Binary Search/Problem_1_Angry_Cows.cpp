#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
  int n,k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  sort(a.begin(), a.end());

  auto cek = [&] (int x){
    int jumlah = 1;
    int kanan = a[0] + x*2;

    for(auto hay : a){
      if(hay > kanan){
        jumlah++;
        kanan = hay + (x*2);
      }
    }

    return jumlah <= k;
  };
  
  int l = 0;
  int r = a[n-1] - a[0];
  while(l<r){
    int mid = (l+r)/2;
    if(cek(mid)){
      r = mid;
    }else{
      l = mid+1;
    }
  }
  cout << l << endl;
}