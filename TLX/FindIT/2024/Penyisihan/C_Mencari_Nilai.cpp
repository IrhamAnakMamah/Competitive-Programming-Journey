#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n,r,k;
    cin >> n >> r >> k;

    int b[n];
    int hasil = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
      float x;
      cin >> x;
      x /= 100;
      hasil += b[i] * x;
    }
    
    if(hasil>=r){
      cout << "PASS" << endl;
    }else{
      cout << "NOT PASS" << endl;
    }

  }
  
}