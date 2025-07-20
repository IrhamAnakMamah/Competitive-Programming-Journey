#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,q,d;
  cin >> n;
  int a;
  vector <pair <int ,int >> b;
  for(int i = 0; i<n ; i++){
    cin >> a;
    b.push_back(make_pair(a,i));
  }
  sort(b.begin(), b.end());
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> d;
    int awal = 0;
    int akhir = n-1;
    int ans = -1;
    while (awal<=akhir){
      int tengah = (awal+akhir)/2;
      if(b[tengah].first==d){
        ans = b[tengah].second;
        akhir = tengah - 1;
      }else if(b[tengah].first<d){
        awal = tengah +1;
      }else if(b[tengah].first>d){
        akhir = tengah -1;
      }
    }
    cout << ans << "\n";
  }
  
}
