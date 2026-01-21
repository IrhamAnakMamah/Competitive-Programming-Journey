#include <bits/stdc++.h>
using namespace std;

int main(){
  int p, q;
  cin >> p >> q;
  int x, y;
  cin >> x >> y;

  if(x < p || y < q || x > 100 + p - 1 || y > 100 + q - 1){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}