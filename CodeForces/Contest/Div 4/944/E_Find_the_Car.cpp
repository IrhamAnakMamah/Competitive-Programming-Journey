#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n,k,q;
    cin >> n >> k >> q;
    ll a[k+1];
    ll b[k+1];
    a[0] = 0;
    b[0] = 0;
    for (int i = 1; i <= k; i++)
    {
      cin >> a[i];
    }
    for (int i = 1; i <= k; i++)
    {
      cin >> b[i];
    }
    //rumus pembagian ke bawah antara a[i]-a[i-1]/b[i]-b[i-1]
    //query d-poin sebelumnya/kecepatan
    //berarti waktu sebelumnya + query
    for (int i = 0; i < q; i++)
    {
      ll d;
      cin >> d;
      int l = 0, r = k;
      while(l <= r)
      {
        int mid = l+r>>1;
        if(a[mid] > d)
        {
          r = mid-1;
        }
        else
        {
          l = mid+1;
        }
      }
      if(a[r] == d)
      {
        cout << b[r] << " ";
        continue;
      }
      ll ans = b[r]+(d-a[r])*(b[r+1]-b[r])/(a[r+1]-a[r]);
      cout << ans << " ";
    }
    cout << endl;
  }
  
}