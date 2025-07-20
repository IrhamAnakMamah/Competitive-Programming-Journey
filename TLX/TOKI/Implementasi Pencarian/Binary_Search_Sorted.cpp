#include <iostream>
using namespace std;

int main (){
  int n,q,d;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  cin >> q;
  for(int i = 0;i<q;i++){
    cin >> d;
    int ans = -1;
    int awal = 0;
    int tengah = 0;
    int akhir = n-1;
    while(awal<=akhir){
      tengah = (awal+akhir)/2;
      if(a[tengah]==d){
        ans = tengah;
        akhir = tengah - 1;
      }else if(a[tengah]<d){
        awal = tengah +1;
      }else if (a[tengah]>d){
        akhir = tengah - 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}