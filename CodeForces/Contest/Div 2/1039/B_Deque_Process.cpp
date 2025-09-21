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
    int i = 0;
    int j = n-1;
    bool ok = 0; // 0 naik, 1 turun
    string ans = "L";
    while (i != j)
    {
      int mx = max(a[i], a[j]);
      int mn = min(a[i], a[j]);
      if(ok){
        if(mx == a[i]){
          cout << "L";
          i++;
        }else{
          cout << "R";
          j--;
        }
      }else{
        if(mn == a[i]){
          cout << "L";
          i++;
        }else{
          cout << "R";
          j--;
        }
      }
      ok^=1;
    }
    cout << ans << endl;
  }
  
}