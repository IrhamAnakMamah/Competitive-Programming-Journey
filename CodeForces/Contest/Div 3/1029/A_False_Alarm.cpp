#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;

    int nyala = 0;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
      if(nyala){
        if(k <= 0 && a[i] == 1){
          ok = 0;
        }else{
          k--;
        }
      }else{
        if(a[i] == 1){
          nyala = 1;
          k--;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  
}