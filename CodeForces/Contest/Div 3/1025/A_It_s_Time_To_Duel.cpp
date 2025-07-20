#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    bool ok = 1;

    int nol = 0;
    int total_nol = 0;

    int a;
    cin >> a;
    int temp = a;
    if(a==0){
      total_nol++;
      nol++;
    }
    for (int i = 1; i < n; i++)
    {
      cin >> a;
      if(a==0){
        total_nol++;
        nol++;
        if(nol>=2){
          ok = 0;
        }
      }else{
        nol = 0;
      }
    }
    
    if(total_nol == 0 || nol>=2){
      ok = 0;
    }
    cout << (ok ? "NO" : "YES") << endl;
  }
  
}