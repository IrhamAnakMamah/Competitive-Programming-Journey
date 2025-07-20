#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    vector<int> cek(n+1,0);
    vector<int> sekarang(n+1,0);
    int ans1 = 1;
    cek[a[0]] = 1;
    int jumlah_lama = 1;
    int jumlah_baru = 0;
    vector<int> temp(n+1,0);

    for (int i = 1; i < n; i++)
    {
      if(cek[a[i]] > 0){
        cek[a[i]]--;
        if(cek[a[i]] == 0){
          jumlah_lama--;
        }
      }
      sekarang[a[i]]++;
      jumlah_baru++;
      if(jumlah_lama == 0){
        ans1++;
        jumlah_lama = jumlah_baru;
        jumlah_baru = 0;
        cek = sekarang;
        sekarang = temp;
      }
    }
    cout << ans1 << endl;
  }
  
}