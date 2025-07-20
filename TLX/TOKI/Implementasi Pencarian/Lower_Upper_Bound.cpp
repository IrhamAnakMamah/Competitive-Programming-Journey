#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,q,x,y;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a,a+n);
  cin >> q;
  for (int i = 0; i < q; i++){
    cin >> x >> y;
    int low = lower_bound(a,a+n,x)-a;
    int upper = upper_bound(a,a+n,y)-a;
    cout << upper - low << "\n";
  }
  
  return 0;
}