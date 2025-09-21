#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;

  vector<int> a(n), b(n), c(n);

  iota(a.begin(), a.end(), 0U);
  iota(b.begin(), b.end(), 0U);
  iota(c.begin(), c.end(), 0U);
  
  for (int i = 0; i < q; i++)
  {
    int x;
    cin >> x;
    if(x == 1){
      int y,z;
      cin >> y >> z;
      c[y-1] = b[z-1];
    }else if(x == 2){
      int y,z;
      cin >> y >> z;
      swap(b[y-1], b[z-1]);
      swap(a[b[y-1]], a[b[z-1]]);
    }else{
      int y;
      cin >> y;
      cout << a[c[y-1]] + 1 << endl;
    }
  }
  cout << endl;
}