#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int x = c - a;
    int y = d - b;

    if(c < a || d < b){
      cout << "NO" << endl;
    }else{
      int mn = min(a,b);
      if(mn == 0 && max(a,b) >= 3){
        cout << "NO" << endl;
      }else{
        int batas = 4 + ((mn - 1) * 2);
        int hasil = batas - max(a,b);
        if(hasil < 0){
          cout << "NO" << endl;
        }else{
          batas = (min(x,y) >= 1 ? 4 : 0) + ((min(x,y) - 1) * 2);
          if(batas - max(x,y) < 0 && max(x,y) >= 3){
            cout << "NO" << endl;
          }else{
            cout << "YES" << endl;
          }
        }

      }
    }

  }
  
}