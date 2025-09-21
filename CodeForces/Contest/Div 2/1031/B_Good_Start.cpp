#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m,a,b;
    cin >> n >> m >> a >> b;

    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int jarak1 = abs(x1-x2)%a;
    int jarak2 = abs(y1-y2)%b;
    bool ok = 0;

    if(x1 == x2){
      if(jarak2 == 0){
        ok = 1;
      }else{
        ok = 0;
      }
    }else if(y1 == y2){
      if(jarak1 == 0){
        ok = 1;
      }else{
        ok = 0;
      }
    }else if((x1-x2)%a == 0 || (y1-y2)%b == 0){
      ok = 1;
    }

    cout << (ok ? "Yes" : "No") << endl;
  }
  
}