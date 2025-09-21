#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int a,b,k;
    cin >> a >> b >> k;

    int cek = ceil((b * 1.0)/k);
    int l = 0;
    int p = 0;
    string ans = "";
    while (a > 0 || b > 0)
    {
      if(((a >= b && l < 2) || p == k) && a > 0){
        ans += 'L';
        l++;
        p = 0;
        a--;
      }else if(b > 0 && p < k){
        ans += 'P';
        p++;
        l = 0;
        b--;
      }else{
        ans = "mustahil";
        break;
      }
    }
    
    cout << ans << endl;
  }
  
}