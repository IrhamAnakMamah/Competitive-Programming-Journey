#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n,x,y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      sum+=a[i];
    }
    /*
    
    x <= sum - (ai - aj) <= y
    x - sum <= - (ai - aj) <= y - sum
    sum - x >= (ai - aj) >= sum - y

    x' = sum - x
    y' = sum - x

    x' >= (ai - aj) >= y'

    cukup mencari nilai ai

    x' - aj >= ai >= y' - ai
    
    */
    //nilai x dan y yang baru
    x = sum - x;
    y = sum - y;
    ll ans = 0;
    // lakukan sort karena menggunakan metode binary search
    sort(a.begin(),a.end());
    for (int i = 0; i < n; i++)
    {
      // mencari batas bawah
      int l = lower_bound(a.begin(), a.end(), y - a[i]) - a.begin();

      // mencari batas atas, jadi r-1
      int r = upper_bound(a.begin(), a.end(), x - a[i]) - a.begin();
      ans+=max(0,r-l);

      //jika i berada diantara l dan r-1, maka jawaban tidak valid (dihapus karena i dan j tidak boleh sama)
      if((l<=i) && (i < r)){
        ans--;
      }
    }
    
    ans/=2; //perhitungan diatas harus dibagi 2 ( jika ada (1,2) dan (2,1), maka hanya diambil satu aja)

    cout << ans << endl;
  }
  
}